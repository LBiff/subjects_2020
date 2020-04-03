//带有随机节点的链表的深拷贝
//关键是找到新节点和旧节点之间的映射关系
//1.map映射，2.下一节点映射

//1.map映射
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;


// Definition for a Node.
class Node 
{
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution_1 
{
public:
    Node* copyRandomList(Node* head) 
    {
        if(!head)
        {
            return nullptr;
        }
        unordered_map<Node*, Node*> map;
        
        //先加入所有的节点
        Node* node = head;
        while(node)
        {
            Node* new_node = new Node(node->val);
            map.insert(make_pair(node, new_node));
            node = node->next;
        };

        //连接next和random
        node = head;
        while(node)
        {
            auto iter = map.find(node);
            iter->second->next = node->next ? map.find(node->next)->second : nullptr;
            iter->second->random = node->random ? map.find(node->random)->second : nullptr; 
            node = node->next;
        };
        return map.find(head)->second;
    }
};

//下一节点映射
class Solution_2 
{
public:
    Node* copyRandomList(Node* head) 
    {
        if(!head)
        {
            return nullptr;
        };

        Node* node = head;
        Node* new_head = new Node(node->val);
        Node* head_node_next = node->next;
        node->next = new_head;
        new_head->next = head_node_next;
        node = node->next->next;
        //根据next插入下一节点
        while(node)
        {
            Node* new_node = new Node(node->val);
            Node* node_next = node->next;
            node->next = new_node;
            new_node->next = node_next;
            node = node->next->next;
        };

        //调整
        node = head;
        while(node)
        {
            Node* new_node = node->next;
            node->next = new_node ->next;
            new_node ->next = node->next ? node->next->next : nullptr;
            new_node ->random = node->random ? node->random->next : nullptr;
            node = node ->next ? node->next->next :nullptr;
        };

        return new_head;
    }
};
