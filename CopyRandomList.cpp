//复制含有随机结点的链表

#include <hash_map>
using namespace std;

//hash_map
struct Node
{
    int _value;
    Node* _next;
    Node* _random;
    Node(int value)
    {
        _value = value;
    }
};

//hash_map
Node* CopyRandomList_1(const Node* head)
{
    __gnu_cxx::hash_map<Node*, Node*> map;
    //遍历源链表构建数据
    Node* old_node = const_cast<Node*>(head);
    Node* new_node;
    while(old_node != NULL)
    {
        new_node = new Node(old_node->_value);
        map.insert(pair(new_node, old_node));
        old_node = old_node->_next;
    };

    //遍历构建next和random
    old_node = const_cast<Node*>(head);
    Node* old_next;
    Node* old_random;
    Node* new_next;
    Node* new_random;
    while(old_node != NULL)
    {
        new_node = map.find(old_node)->second;
        old_next = old_node->_next;
        old_random = old_node -> _random;
        new_next = map.find(old_next)->second;
        new_random = map.find(old_random)->second;   

        new_node -> _next = new_next;
        new_node ->_random = new_random;

        old_node = old_node ->_next;     
    };

    return map.find(const_cast<Node*>(head))->second;
};

//1'挂载1的后面,和hash_map一样相对位置可以查询到
Node* CopyRandomList_2(const Node* head)
{
    Node* old_node = const_cast<Node*>(head);
    Node* new_node;
    Node* old_node_next;
    //1'挂在１后面
    while(old_node != NULL)
    {
        new_node = new Node(old_node->_value);
        old_node_next = old_node -> _next;
        old_node ->_next = new_node;
        new_node ->_next = old_node_next;
    };

    //连接random
    old_node = const_cast<Node*>(head);
    Node* old_node_random;
    Node* new_olde_random;
    while(old_node != NULL)
    {
        old_node_random = old_node->_random;
        new_node = old_node ->_next;
        if(old_node_random)
        {
            new_node -> _random = old_node_random->_next;
        }
        else
        {
            new_node -> _random = NULL;
        };

        old_node = old_node->_next->_next;
    };

    //拆解还原
    old_node = const_cast<Node*>(head);
    Node* new_node_next;
    while(old_node != NULL)
    {
        new_node = old_node->_next;
        old_node_next = old_node->_next->_next;
        new_node_next = new_node -> _next == NULL ? NULL : new_node->_next->_next;
        old_node->_next = old_node_next;
        new_node ->_next = new_node_next;
    }
}


int main()
{
    
}

