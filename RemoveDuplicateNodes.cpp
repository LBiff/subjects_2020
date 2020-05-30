//编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {};
};
 
#include <unordered_set> 
using namespace std;

class Solution 
{
public:
    ListNode* removeDuplicateNodes(ListNode* head) 
    {
        unordered_set<int> set;
        ListNode* cur_node = head;
        ListNode* pre_node = nullptr;
        while(cur_node) 
        {
            auto iter = set.find(cur_node->val);
            if(iter == set.end())  //找不到
            {
                set.insert(cur_node->val);
                pre_node = cur_node;
                cur_node = cur_node -> next;
            }
            else
            {
                ListNode* next_node = cur_node->next;
                pre_node ->next = next_node;
                //pre_node不变
                cur_node = next_node;
            }
        };
        return head;
    };
};