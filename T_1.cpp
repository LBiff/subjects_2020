#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

//删除链表的倒数第N个节点
//添加父哑节点，排除删除的头结点时找不到父节点
//两指针，第一个指针先走到n+1，再和第二个指针同时走知道第一null,此时第二压中倒数n的父节点。
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {};
};

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    //特殊处理,删除头结点，添加哑节点
    ListNode new_head = ListNode(-1);
    new_head.next = head;
    
    ListNode* n1 = &new_head;
    ListNode* n2 = &new_head;
    int n2_go = n + 1; //n2向前走n + 1步,n1之后随之走完压到删除的父节点
    while((n2_go--) > 0)
    {
        n2 = n2->next;
    };
    
    //同时向前走
    while(n2 != nullptr)
    {
        n1 = n1->next;
        n2 = n2 ->next;
    };
    //此时n1指向倒数n + 1位置
    ListNode* child = n1->next->next;
    delete n1->next;
    n1 -> next = child;
    return new_head.next;
};


static vector<int> GetIntVByLineBySpace()
{
    string s;
    string word;
    vector<int> v;
    getline(cin,s);
    istringstream record(s);
    while(record >> word)
    {
        v.push_back(atoi(word.c_str()));
    };
    return v;
};

int main()
{
    auto p1 = GetIntVByLineBySpace();
    int list_len = p1[0];
    int del_idx = p1[1] - 1;
    if(list_len == 1)
    {

    };

    auto v = GetIntVByLineBySpace();
    v.erase(v.begin() + del_idx);
    if(!v.empty())
    {
        cout << v[0];
        for(int i = 1; i < v.size(); i++)
        {
            cout << " " << v[i];
        }
    };

    return 0;
    

}