// 234. 回文链表
// 请判断一个链表是否为回文链表。


struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

#include <stack>
using namespace std;

class Solution 
{
public:
    bool isPalindrome(ListNode* head) 
    {
        if(!head || !head->next)
        {
            return true;
        };
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast)
        {
 
            fast = fast->next ? fast->next->next : fast->next;
            slow = slow->next;
        };

        stack<ListNode*> stk;
        while(slow)
        {
            stk.push(slow);
            slow = slow->next;
        };

        slow = head;
        while(!stk.empty())
        {
            if(slow->val != stk.top()->val)
            {
                return false;
            };
            slow = slow->next;
            stk.pop();
        };

        return true;
    }
};