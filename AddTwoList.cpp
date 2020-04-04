//两数相加
//直接按正常逻辑相加
 struct ListNode 
 {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {};
  };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    if(!l1)
    {
        return l2;
    }
    else if(!l2)
    {
        return l1;
    };

    int sum = l1->val + l2->val;
    ListNode* new_head = new ListNode(sum % 10);
    int over_flow = sum / 10;
    l1 = l1->next;
    l2 = l2->next;
    ListNode* node = new_head;
    while(l1 || l2)
    {
        int sum = over_flow;
        sum = l1 ? sum + l1->val : sum;
        sum = l2 ? sum + l2->val : sum;
        node->next = new ListNode(sum % 10);
        over_flow = sum /10;
        node = node->next;
        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
    };
    if(over_flow)
    {
        node->next = new ListNode(1);
    };

    return new_head;
}

