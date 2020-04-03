//单链表和双链表的反转问题
#include <forward_list>
#include <iostream>
using namespace std;

struct Node
{
    Node* _next;
    Node* _pre;
    int _value;
    Node(int value, Node* next = nullptr, Node* pre = nullptr)
    {
        _value = value;
        _next = next;
        _pre = pre;
    }
};


void PrintList(const Node* head)
{
    if(head)
    {
        Node* node = const_cast<Node*>(head);
        while(node != nullptr)
        {
            cout << node->_value << " ";
            node = node->_next;

        }
        cout << endl;
    }

}

//返回调整后的头指针
 Node* ReverseForwardList(Node* head)
 {
     Node* pre = nullptr;
     Node* next = nullptr;

    // 依次往前指
    while(head != nullptr)
    {
        next = head -> _next;
        head->_next = pre;
        pre = head;
        head = next;
    }
    return pre;
 };

 //双链表的反转
 Node* ReverseList(Node* head)
 {
     Node* pre = nullptr;
     Node* next = nullptr;
    while(head != nullptr)
    {
        next = head -> _next;
        head->_next = pre;
        head->_pre = next;
        pre = head;
        head = next;
    };
    return pre;
 };



int main()
{
    Node n_1(1);
    Node n_2(2);
    Node n_3(3);
    Node n_4(4);
    Node n_5(5);
    cout << "1: " << &n_1 << endl; 
    cout << "2: " << &n_2 << endl; 
    cout << "3: " << &n_3 << endl; 
    cout << "4: " << &n_4 << endl; 
    cout << "5: " << &n_5 << endl; 
    n_1._next = &n_2;
    n_2._next = &n_3;
    n_3._next = &n_4;
    n_4._next = &n_5;
    n_5._next = nullptr;

    PrintList(&n_1);
   // Node* a = ReverseForwardList(&n_1);

    PrintList(ReverseForwardList(&n_1));
    return 0; 
    
}