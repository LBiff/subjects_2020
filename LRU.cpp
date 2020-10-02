// 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 
// 获取数据 get 和 写入数据 put 。
// 获取数据 get(key) - 如果关键字 (key) 存在于缓存中，则获取关键字的值（总是正数），否则返回 -1。
// 写入数据 put(key, value) - 如果关键字已经存在，则变更其数据值；如果关键字不存在，
// 则插入该组「关键字/值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，
// 从而为新的数据值留出空间。
// 进阶:
// 你是否可以在 O(1) 时间复杂度内完成这两种操作？

//LRU的实现，get和put  O(1)

//双向链表加hash_map实现

#include <unordered_map>
#include <list>
#include <vector>
#include <string>
using namespace std;

class LRUCache 
{
    struct Node
    {
        int _value;
        int _key;
        Node* _pre;
        Node* _next;
        Node(int key, int value):_key(key),_value(value),_pre(nullptr),_next(nullptr){};
    };
public:
    LRUCache(int capacity) : _capacity(capacity), _l_head(new Node(-1, -1))
                            ,_l_tail(new Node(-1, -1)) ,_now_capacity(0)
    {
        _l_head->_next = _l_tail;
        _l_tail->_pre = _l_head;
    };
    
    int get(int key) 
    {
        auto iter = _map.find(key);
        if(iter != _map.end())  //查找到
        {
            MoveNodeToHead(key);
            return iter->second->_value;
        }
        else
        {
            return -1;
        }
    }
    
    void put(int key, int value) 
    {
        if(_now_capacity < _capacity && _map.find(key) == _map.end())
        {
            ListInsertFrontAndInsertMap(key,value);
        }
        else if(_now_capacity <= _capacity && _map.find(key) != _map.end())
        {
            UpdateValue(key,value);
            MoveNodeToHead(key);
        }
        else
        {
            DelTailAndDelMap();
            ListInsertFrontAndInsertMap(key,value);
        }
    };

private:
    void ListInsertFrontAndInsertMap(int key, int value)
    {
        auto iter = _map.find(key);
        if(iter == _map.end())
        {
            Node* new_node = new Node(key, value);
            new_node->_pre = _l_head;
            Node* front_next = _l_head->_next;
            new_node->_next = front_next;

            front_next->_pre = new_node;
            _l_head->_next = new_node;
            _now_capacity++;

            _map.insert(make_pair(key, new_node));
        }
    }
    //移动到头结点
    void MoveNodeToHead(int key)
    {
        auto iter = _map.find(key);
        if(iter != _map.end())
        {
            Node* cur = iter->second;
            Node* pre = cur->_pre;
            Node* next = cur->_next;
            next->_pre = pre;
            pre->_next = next;

            //将cur到头
            cur->_pre = _l_head;
            Node* head_next = _l_head->_next;
            cur->_next = head_next;

            _l_head->_next = cur;
            head_next->_pre = cur;
        }
    };

    //删除尾结点
    void DelTailAndDelMap()
    {
        Node* tail_node = _l_tail->_pre;
        if(tail_node != _l_head)
        {
            Node* tail_pre = tail_node->_pre;
            _map.erase(tail_node->_key);
            delete tail_node;
            _l_tail->_pre = tail_pre;
            tail_pre->_next = _l_tail;
            _now_capacity--;
        }
    }
    
    void UpdateValue(int key, int value)
    {
        auto iter = _map.find(key);
        if(iter != _map.end())
        {
            iter->second->_value = value;
        }
    }

private:
    int _capacity; //容量
    int _now_capacity; //现在的容量
    unordered_map<int, Node*> _map;
    Node* _l_head; //头结点
    Node* _l_tail; //尾结点
};

int main()
{
    vector<string> name{"LRUCache","get","put","get","put","put","get","get"};
    vector<vector<int>> paras{{2},{2},{2,6},{1},{1,5},{1,2},{1},{2}};

    int idx = 0;
    LRUCache* lru = nullptr;
    while(idx < name.size())
    {
        if(name[idx] == "LRUCache")
        {
            lru = new LRUCache(paras[idx][0]);
        }
        else if(name[idx] == "put")
        {
            lru->put(paras[idx][0], paras[idx][1]);
        }
        else if(name[idx] == "get")
        {
            lru->get(paras[idx][0]);
        }
        idx++;
    }
}