//环检测
 struct ListNode 
 {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
 
ListNode *detectCycle(ListNode *head) 
{
    if(!head || !(head->next) || !(head->next->next))
    {
        return nullptr;
    }
    ListNode* slow_n = head->next;
    ListNode* fast_n = head->next->next;
    while(fast_n)
    {
        if(fast_n == slow_n) //表示有环
        {
            slow_n = head;
            while(slow_n != fast_n)
            {
                slow_n = slow_n->next;
                fast_n = fast_n ->next;
            };

            return slow_n;
        }
        else
        {
            slow_n = slow_n ->next;
            fast_n = fast_n ->next ? fast_n ->next->next : fast_n ->next;
        }
    };

    return nullptr;
};