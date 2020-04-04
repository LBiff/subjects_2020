//节点对的实际交换
// 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {};
};

class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if(!head)
        {
            return nullptr;
        }
        ListNode head_p(-1);
        head_p.next = head;

        ListNode* n1_p = &head_p;
        ListNode* n1 = head;
        ListNode* n2 = head->next;
        while(n2)
        {
            SwapTwoNode(n1_p,n1,n2,n2->next);
            n1_p = n1;
            n1 = n1->next;
            n2 = n1 ? n1->next : nullptr;
        };

        return head_p.next;
    };

    void SwapTwoNode(ListNode* n1_p, ListNode* n1, ListNode* n2, ListNode* n2_next)
    {
        if(!n1_p || !n1 || !n2)
        {
            return;
        }
        n1_p->next = n2;
        n2->next = n1;
        n1->next = n2_next;
    }
};