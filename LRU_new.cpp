// 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
// 获取数据 get(key) - 如果关键字 (key) 存在于缓存中，则获取关键字的值（总是正数），否则返回 -1。
// 写入数据 put(key, value) - 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字/值」。
// 当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

#include <list>
#include <unordered_map>
#include <iostream>
using namespace std;

struct Node
{
    int _k;
    int _v;
    Node* _pre;
    Node* _next;
    Node(int k, int v) :_k(k), _v(v),_pre(nullptr), _next(nullptr){};
};

class LRUCache 
{
public:
    LRUCache(int capacity) : total_cap(capacity) , head(new Node(-1,-1)), tail(new Node(-1,-1)), cur_cap(0)
    {

        head -> _next = tail;
        tail -> _pre = head;
    };
    
    int get(int key) {
        auto iter = mp.find(key);
        if(iter != mp.end())
        {
            //将其跳整到头
            MoveNodeToHead(iter->second);
            return iter->second->_v;
        }
        else
        {
            return -1;
        }
    };
    
    void put(int key, int value) 
    {
        auto iter = mp.find(key);
        if(iter != mp.end())
        {
            auto n = iter->second;
            n->_v = value;
            //将其调整到头
            MoveNodeToHead(n);
        }
        else
        {
            if(cur_cap >= total_cap)
            {
                //淘汰最后一个
                auto end = tail -> _pre;
                if(end != head)
                {
                    auto end_end = end -> _pre;
                    mp.erase(end -> _k);
                    delete end;
                    end_end -> _next = tail;
                    tail -> _pre = end_end;
                    cur_cap--;
                }
            }
            
            if(cur_cap < total_cap)
            {
                //直接插入到头
                InsertNewNodeToHead(key,value);
            }

        }
    };

private:
    //将结点调整到头
    void MoveNodeToHead(Node* n)
    {
        if(!n)
        {
            return;
        };

        //将其调整到头
        auto n_pre = n->_pre;
        auto n_next = n -> _next;
        n_pre -> _next = n_next;
        n_next -> _pre = n_pre;
        auto fir = head -> _next;
        head -> _next = n;
        n -> _pre = head;
        n->_next = fir;
        fir->_pre = n;
    };

    //插入新节点到头部
    void InsertNewNodeToHead(int key, int value)
    {
        auto fir = head->_next;
        auto new_node = new Node(key,value);
        head->_next = new_node;
        new_node -> _pre = head;
        new_node -> _next = fir;
        fir->_pre = new_node;
        mp.insert({key, new_node});
        cur_cap++;
    }

private:
    int total_cap;
    int cur_cap;
    Node* head; //头哑结点
    Node* tail; //尾部哑结点
    unordered_map<int,Node*> mp;
};


int main()
{
    LRUCache* cache = new LRUCache( 1 /* 缓存容量 */ );

    cache->put(2, 1);
    cout << cache->get(2); 
    cache->put(3, 2); 
    cout << cache->get(2); 
    cout << cache->get(3); 
   

    return 0;


}