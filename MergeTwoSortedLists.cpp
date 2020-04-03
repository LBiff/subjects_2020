//合并两个有序链表
//双指针法，谁小+谁，可以添加哑结点
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {};
};
 

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
    ListNode* n1 = l1;
    ListNode* n2 = l2;
    ListNode new_head(-1); //哑结点
    ListNode* new_node = &new_head;
    while(n1 && n2)
    {
        if((n1->val) > (n2->val))
        {
            new_node->next = new ListNode(n2->val);
            n2 = n2->next;
        }
        else
        {
            new_node->next = new ListNode(n1->val);
            n1 = n1->next;
        }
        new_node = new_node -> next;
    };
    while(n1)
    {
        new_node->next = new ListNode(n1->val);
        n1 = n1->next;
        new_node = new_node -> next;
    };
    while(n2)
    {
        new_node->next = new ListNode(n2->val);
        n2 = n2->next;
        new_node = new_node -> next;
    };
    
    return new_head.next;
}