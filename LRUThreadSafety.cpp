// 线程安全的lru

#include <cstdlib>
#include <valarray>
#include <cstdint>
#include <cassert>
using namespace std;

// 基类
struct LRUHandle 
{ // 这便是返回的 Handle，在返回的时候会 return reinterpret_cast<Cache::Handle*>(handle)
   void *value; 
   void (*deleter)(const slice &, void *);
   LRUHandle *next_hash; // 给自己实现的 hahs_table 使用;
   LRUHandle *next; // 双向链表
   LRUHandle *prev; // 双向链表
   size_t charge; // 权重
   size_t key_length; // key 长度
   bool in_cache; // 是否被缓存（我们的类可以通过将 capacity 设置为0来关闭缓存）
   uint32_t refs; // 引用计数
   uint32_t hash; // 我们要将 hash 值缓存起来，防止需要重复 hash 计算
   char key_data[1]; // 柔性数组，存储键

   slice key() const {
     assert(next != this); // Hold true iff this is the head of an empty list
     return slice(key_data, key_length);
   }
 };

class Cache 
{
 public:
  Cache() { }

  // 需要调用插入时的 deleter 销毁所有 entries
  virtual ~Cache()
  {
      
  }

  // 每个 entry 对应的 handle，客户端只能通过调用 this->Value(handle) 来获取缓存的内容，不可以直接访问缓存
  struct Handle { };

  // 插入一个 key->value 的映射，支持通过 charge 为不同的缓存设定不同的权重。
  // 返回一个 entry 对应的 handle 指针到客户端，客户端不需要使用后必须显示的调用 this->Release(handle),
  // 当缓存要被换出的时候，会调用传入的 deleter
  virtual Handle *Insert(const slice &key, void *value, size_t charge,
                         void (*deleter)(const slice &key, void *value)) = 0;

  // 查询接口，如果缓存不存在，返回 NULL 指针。否则返回 entry 对应的 handle 指针，同样必须调用 this->Release(handle)
  virtual Handle *Lookup(const slice &key) = 0;

  // 释放由 Insert 或者 Lokkup 返回的 handle。Release a mapping returned by a previous Lookup().
  // NOTE: 1.仅能在一个 handle 上调用一次 this->Release(handle)
  // NOTE: 2.handle 在调用该方法后不能再使用(handle 指针会被 free 掉)
  virtual void Release(Handle *handle) = 0;

  // 获取缓存内容
  virtual void *Value(Handle *hanle) = 0;

  // 见上面第6点
  virtual uint64_t NewId() = 0;

  // 清楚所有的未使用缓存
  virtual void Prune() { }

  // 查看缓存使用总量
  virtual size_t TotalCharge() const = 0;

 private:
  // No copying allowed
  Cache(const Cache &);
  void operator=(const Cache &);
};


 class HandleTable {
 public:
   HandleTable() : length_(0), elems_(0), list_(NULL) { Resize(); }
   ~HandleTable() { delete[] list_; }

   LRUHandle *Lookup(const slice &key, uint32_t hash) {
     return *FindPointer(key, hash);
   }

   // Insert into the last position
   LRUHandle *Insert(LRUHandle *h) {
     LRUHandle **ptr = FindPointer(h->key(), h->hash);
     LRUHandle *old = *ptr;
     h->next_hash = (old == NULL ? NULL : old->next_hash);
     *ptr = h;
     if (old == NULL) {
       ++elems_;
       if (elems_ > length_) {
         Resize();
       }
     }
     return old;
   }

   LRUHandle *Remove(const slice &key, uint32_t hash) {
     LRUHandle **ptr = FindPointer(key, hash);
     LRUHandle *result = *ptr;
     if (result != NULL) {
       *ptr = result->next_hash;
       --elems_;
     }
     return result;
   }
 private:
   uint32_t length_; // hash table 的 bucket 数
   uint32_t elems_; // hash table 中 entry 数
   LRUHandle **list_; // hash bucket 数组

   LRUHandle **FindPointer(const slice &key, uint32_t hash) { 
     assert(list_ != NULL);
     LRUHandle **ptr = &list_[hash & (length_ - 1)]; // 找到对应键的桶，取第一个 entry
     while (*ptr != NULL &&
            ((*ptr)->hash != hash || (*ptr)->key() != key)) {
       ptr = &(*ptr)->next_hash; // 注意，我们返回的不是一个 LRUHandle *,而是一个 LRUHandle **(&(LRUHandle::next_hash))
     }
     return ptr;
   }

   void Resize() {
     uint32_t new_length = 4; // length_ 一定是 2 的幂次，这样可以使用 hash & (length_ - 1) 来算出 hash % length_
     while (new_length < elems_) new_length <<= 1; // 算出新 length，因为 length > elems_; 所以装载因子<1
     LRUHandle **new_list = new LRUHandle *[new_length]; 
     memset(new_list, 0, sizeof(new_list[0]) * new_length);
     uint32_t count = 0;
     for (uint32_t i = 0; i < length_; i++) { // 遍历所有的桶，为桶内元素搬家
       LRUHandle *h = list_[i]; // 每个桶的第一个 entry
       while (h != NULL) {
         LRUHandle *next = h->next_hash; // 先保存起来 next
         uint32_t hash = h->hash;
         LRUHandle **ptr = &new_list[hash & (new_length-1)];  // 计算在新表中的桶下标，取桶内第一个 entry
         h->next_hash = *ptr; // 头插法
         *ptr = h;
         h = next;
         ++count;
       }
     }
     assert(count == elems_);
     delete[] list_; // 更新 list_ 和 length_
     list_ = new_list;
     length_ = new_length;
   }
};


class LRUCache {
 public:
  LRUCache(): usage_(0) 
  { // 初始化两个双向链表的 dummy head
  lru_.next = &lru_; 
  lru_.prev = &lru_;
  in_use_.next = &in_use_;
  in_use_.prev = &in_use_;
}

  ~LRUCache() {
  assert(in_use_.next == &in_use_); // 如果在 LRUCache 在析构的时候，还有客户端持有尚未 Release() 的 handle，那么就会出问题
  LRUHandle *e = lru_.next;
  while (e != &lru_) { // 释放所有 entries
    LRUHandle *next = e->next;
    assert(e->in_cache); 
    e->in_cache = false;
    assert(e->refs == 1);
    Unref(e);
    e = next;
  }
}

  void SetCapacity(size_t cap) { capacity_ = cap; }

  Cache::Handle *Insert(const slice &key, uint32_t hash,
                        void *value, size_t charge,
                        void (*deleter)(const slice &, void *))(
    const slice &key, uint32_t hash, void *value, size_t charge,
    void (*deleter)(const slice &, void *)) {
  MutexLock l(&mutex_);

  LRUHandle *e = reinterpret_cast<LRUHandle*>(
      malloc(sizeof(LRUHandle) + (key.size() - 1))); // 这里注意，因为 LRUHandle 中保存了 key_length，所以这里在申请内存的时候，并没有为 '\0'申请内存，如果在 LRUHandle::key_data 上调用 strlen() 会有想不到的后果
  e->value = value; 
  e->charge = charge;
  e->deleter = deleter;
  e->key_length = key.size();
  e->in_cache = false;
  e->refs = 1; // 这里将引用计数设为1是代表被 this->Insert() 的调用者引用，并不是代表 LRUCache 引用，所以如果不保存 this->Insert() 的返回结果会有很大的问题
  memcpy(e->key_data, key.data(), key.size());

  if (capacity_ > 0) { // 需要缓存起来
    e->refs++; // LRUCache 类也要引用这个 handle 了
    e->in_cache = true;
    LRU_Append(&in_use_, e); // 因为这时候 refs == 2，需要放到 in_use_ 中
    usage_ += charge;
    FinishErase(table_.Insert(e)); // 如果相同键插入两次，会覆盖之前的缓存，并且需要将之前的缓存删除
  } else { // 如果将 capacity 设置为0，代表的是关闭缓存
    // 如果 handle->next == handle,会无法通过 LRUHandle::key() 中的断言
    e->next = NULL;
  }
  // 如果本次插入导致缓存超出上限，需要换出旧缓存
  while (usage_ > capacity_) {
    LRUHandle *oldest = lru_.next; // 还记得 lru_.next 存的是最早未使用的缓存吧
    assert(oldest->refs == 1);
    bool erased = FinishErase(table_.Remove(oldest->key(), oldest->hash)); // 删除调用缓存
    if (!erased) { // 如果 erased 是 false，代表 lru_ 中保存有没有被缓存起来的 entry，这是一个严重的问题
      assert(erased); // 一条一定会失败的断言
    }
  }

  return reinterpret_cast<Cache::Handle*>(e);
}
  Cache::Handle *Lookup(const slice &key, uint32_t hash){
  MutexLock l(&mutex_);
  LRUHandle *e = table_.Lookup(key, hash); // 在 hash_table 中查找
  if (e != NULL) Ref(e); // 如果有被缓存起来，增加引用计数等
  return reinterpret_cast<Cache::Handle*>(e); // 将其 cast 为一个 Handle * 返回，还记得 Cache 类中的接口吧？
}
  void Release(Cache::Handle *handle){
  MutexLock l(&mutex_);
  Unref(reinterpret_cast<LRUHandle*>(e));
}
  void Erase(const slice &key, uint32_t hash) {
  MutexLock l(&mutex_);
  FinishErase(table_.Remove(key, hash));
}
  void Prune() {
  MutexLock l(&mutex_);
  while (lru_.next != &lru_) { // 遍历 lru_ 中保存的 entries，将其全部删除掉
    LRUHandle *e = lru_.next;
    assert(e->refs == 1);
    bool erased = FinishErase(table_.Remove(e->key(), e->hash));
    if (!erased) {
      assert(erased);
    }
  }
}
  size_t TotalCharge() const {
    MutexLock l(&mutex_);
    return usage_;
  }

 private:
  void LRU_Remove(LRUHandle *e);
  void LRU_Append(LRUHandle *list, LRUHandle *e{
  list->prev->next = e;
  e->prev = list->prev;
  e->next = list;
  list->prev = e;
}
  void Ref(LRUHandle *e)
  { // 增加引用计数，必要的话将其从 lru_. 挪到 in_use_
  if (e->refs == 1 && e->in_cache) { // ++ 后 refs 大于1，代表有客户端使用
    LRU_Remove(e); // 从 lru_ 中删除
    LRU_Append(&in_use_, e); // 插入 in_use_ 中
  }
  e->refs++; // 增加引用计数
}
  void Unref(LRUHandle *e){
  assert(e->refs > 0); // Unref() 调用前，这个 handle 应该是被引用的
  if (--e->refs == 0) { // 无人引用(包括 LRUCache 类),需要调用其构造时传入的删除器，管理资源
    assert(!e->in_cache);
    (*e->deleter)(e->key(), e->value);
    free(e); // 注意所有的 handle 都是 heap-allocated，必须要free
  } else if (e->in_cache && e->refs == 1) { // refs==1 代表仅有 LRUCache 类引用
    LRU_Remove(e);  // 从 in_use_ 中删除
    LRU_Append(&lru_, e); // 插入 lru_ 中
  }
}
  bool FinishErase(LRUHandle *e){
  if (e != NULL) {
    assert(e->in_cache);
    LRU_Remove(e); // 从 lru_ 中删除
    e->in_cache = false; // 设置状态
    usage_ -= e->charge;
    Unref(e); // 一定会进入调用删除器的分支
  }
  return e != NULL;
}
  // Initialized before use.
  size_t capacity_;

  // Capacity usage guarded by mutex
  mutable Mutex mutex_;
  size_t usage_;

  // 所有未被使用的 entries 都被存储于 lru_ 这个双向链表中，这里使用 dummy head 的方法实现双向链表
  // lru_.prev 是最新的 entry，lru_.next 是最早的 entry(也就是说换出缓存的时候就从 lru_.next 开刀)
  // lru_ 中的所有 entries 都有 refs == 1 && in_cache == true (仅被 LRUCache 类引用，而且被缓存)
  LRUHandle lru_;

  // 所有现在被使用(客户端持有至少一个尚未 Release() 的 handle)的 entries 存储在 in_use_ 双向链表中
  // in_use_ 中 entries 有 refs >= 2 && in_cache = true
  LRUHandle in_use_;

  HandleTable table_; // 用于进行 key->handle 的 mapping
};

