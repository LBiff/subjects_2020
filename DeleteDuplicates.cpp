// 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
// 示例 1:
// 输入: 1->1->2
// 输出: 1->2


struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(!head)
        {
            return nullptr;
        };
        if(!(head->next))
        {
            return head;
        };
        ListNode* pre_n = head;
        int pre_v = head->val;
        ListNode* cur_n = head->next;

        while(cur_n)
        {
            if(cur_n->val != pre_v)
            {
                pre_n->next = cur_n;
                pre_n = cur_n;
                pre_v = cur_n->val;
            }
            cur_n = cur_n->next;
        };
        pre_n->next = nullptr;
        return head;
    };
};

int main()
{
    auto l1 = new ListNode(1);
    auto l2 = new ListNode(1);
    auto l3 = new ListNode(2);
    l1->next = l2;
    l2->next = l3;
    Solution s;
    auto ret = s.deleteDuplicates(l1);
    return 0;
}