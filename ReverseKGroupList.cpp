//链表的K组翻转
// 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
// k 是一个正整数，它的值小于或等于链表的长度。
// 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
#include <algorithm>
using namespace std;

 struct ListNode 
 {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

//将内部指针翻转
void help(ListNode* s, ListNode* e, ListNode* s_pre, ListNode* e_next)
{
    ListNode* pre = s;
    ListNode* cur = s->next;
    ListNode* next = nullptr; //将next下沉到while确保正确
    while(cur != e_next)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    };
    if(s_pre)
    {
        s_pre->next = e;
    };
    s->next = e_next;
};

ListNode* reverseKGroup(ListNode* head, int k) 
{
    if(k < 2)
    {
        return head;
    };
//原则：能确定的才赋值
    ListNode* cur = head; //遍历节点
    ListNode* next = nullptr;

    ListNode mute_node(-1); //哑节点
    mute_node.next = head;

    ListNode* s_pre = &mute_node;
    ListNode* s = head;
    int count = 1;
    while(cur)
    {
        next = cur->next;
        if(count == k)
        {
            help(s, cur, s_pre, next);
            s_pre = s;
            s = next;
            count = 0;
        }
        count++;
        cur = next;
    }
    return mute_node.next;
};



int main()
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = nullptr;
    auto ret = reverseKGroup(&n1, 2);
    return 0;

}