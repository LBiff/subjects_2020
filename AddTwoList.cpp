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
        ListNode* new_head = new ListNode((l1->val + l2->val) % 10);
        int over_flow = (l1->val + l2->val) / 10;
        ListNode* new_node = new_head;
        ListNode* n1 = l1->next;
        ListNode* n2 =l2->next;
        while(n1 || n2)
        {
            over_flow = n1 ? over_flow + n1->val : over_flow;
            over_flow = n2 ? over_flow + n2->val : over_flow;
            new_node -> next = new ListNode(over_flow % 10);
            over_flow /= 10;
            new_node = new_node -> next;
            n1 = n1 ? n1->next : nullptr;
            n2 = n2 ? n2->next : nullptr;
        }
        if(over_flow)
        {
            new_node -> next = new ListNode(1);
        };
        
        return new_head;
    };

