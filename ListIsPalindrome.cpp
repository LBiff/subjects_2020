//判断单链表是否是回文结构

#include <forward_list>  //list是双链表
#include <iostream>
#include <stack>
using namespace std;

//快慢指针，慢指针指出中间位置，后半部分入栈
//时间O(N), 空间O(N)
// 1 2 3
//1 2 3 4
bool ListIsPalindrome_1(const forward_list<int>& l)
{
    forward_list<int>::const_iterator fast = l.begin();
    forward_list<int>::const_iterator slow = l.begin();
    while(fast != l.end() && next(fast) != l.end())
    {
        advance(fast,2);
        advance(slow,1);
    };
    forward_list<int>::const_iterator iter = slow;
    if(fast != l.end()) //奇数
    {
        advance(iter,1);
    };

    //后半部分入栈
    stack<int> s;
    while(iter != l.end())
    {
        s.push(*iter);
        advance(iter,1);
    };

    //栈对比

    forward_list<int>::const_iterator b_iter = l.begin();
    while(!s.empty())
    {
        if(*b_iter != s.top())
        {
            return false;
        };
        advance(b_iter,1);
        s.pop();
    }
    return true;
}


//快慢指针，慢指针指出中间位置，改写原链表，需要实现自定义链表
//时间O(N), 空间O(1)
// 1 2 3
//1 2 3 4
struct Node
{
    Node* _next;
    int _value;
    Node(Node* node = NULL, int value = -1)
    {
        _next = node;
        _value = value;
    }
};

bool ListIsPalindrome_2(const Node* head)
{
    Node* fast = const_cast<Node*>(head);
    Node* slow = const_cast<Node*>(head);
    while(fast->_next != NULL && fast ->_next ->_next != NULL)
    {
        fast = fast ->_next -> _next;
        slow = slow -> _next;
    };

    //slow在奇数压中最中间位置，偶数压中中间上一位置
    //调整链表后半部分
    // 1 2 3 2 1
    //1 2 3 4
    Node* slow_next = slow -> _next;
    Node* slow_bak = slow;
    slow -> _next = NULL;
    slow = slow_next;
    Node* slow_pre = slow_bak;
    while(slow -> _next != NULL)
    {
        slow_bak = slow;
        slow_next = slow -> _next;
        slow->_next = slow_pre;
        slow = slow_next;
        slow_pre = slow_bak;
    };
    //处理最后一个
    slow->_next = slow_pre;

    //两个指针从头遍历
    Node* front = const_cast<Node*>(head);
    Node* tail = slow;
    while(front->_next != NULL && tail->_next != NULL)
    {
        if(front->_value != tail -> _value)
        {
            return false;
        };
        front = front->_next;
        tail = tail -> _next;
    };
    //处理最后一个
    if(front->_value != tail -> _value)
    {
        return false;
    };
    return true;
};

int main()
{
    // forward_list<int> a{1,2,3,2,1};
    // forward_list<int> b{1,2,3};
    // forward_list<int> c{1,2,2,1};
    // forward_list<int> d{1,2};
    // bool e;
    // e = ListIsPalindrome_1(a);
    // e = ListIsPalindrome_1(b);
    // e = ListIsPalindrome_1(c);
    // e = ListIsPalindrome_1(d);
    Node* n_1 = new Node(NULL, 1);
    cout << "1: " << n_1 << endl;
    Node* n_2 = new Node(NULL,2);
    cout << "2: " <<  n_2 << endl;
    Node* n_3 = new Node(NULL,2);
    cout << "2: " <<  n_3 << endl;
    Node* n_4 = new Node(NULL,1);
    cout <<  "1: " << n_4 << endl;
    // Node* n_5 = new Node(NULL,1);
    // cout <<  "1: " << n_5 << endl;
    n_1->_next = n_2;
    n_2->_next = n_3;
    n_3->_next = n_4;
    n_4->_next = NULL;
    // n_5->_next = NULL;
    bool a = ListIsPalindrome_2(n_1);
    return 0;

}
