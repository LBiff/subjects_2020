// 给定一个链表，判断链表中是否有环。
// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
// 如果 pos 是 -1，则在该链表中没有环。

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//快慢指针法判断
bool hasCycle(ListNode *head) 
{
    if(!head || !(head->next))
    {
        return false;
    };

    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast)
    {
        if(slow == fast)
        {
            return true;
        };
        if(!(fast->next) || !(fast->next->next))
        {
            return false;
        }
        
        fast = fast->next->next;
        slow = slow->next;
    };
    return false;
};