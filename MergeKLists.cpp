//合并K个排序链表
// 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
// 示例:
// 输入:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// 输出: 1->1->2->3->4->4->5->6

#include <vector>
#include <queue>
#include <memory>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    class comparator
    {
    public:
        bool operator()(const ListNode* l1, const ListNode* l2)
        {
            return l1->val < l2->val ? true : false;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<ListNode*,vector<ListNode*>,comparator> cur_h;  //当前遍历指针
        for(auto l : lists)
        {
            cur_h.push(l);
        };
        ListNode tmp =  ListNode(-1); //头哑节点
        ListNode * head = &tmp;
        while(!cur_h.empty())
        {
            //当前最小
            ListNode* cur_min = cur_h.top();
            //连上去
            head->next = cur_min;
            cur_h.pop();
            //调整堆中备选
            if(cur_min->next)
            {
                cur_h.push(cur_min->next);
            };
            head = cur_min;
        };
        return tmp.next;
    }
};

int main()
{
    vector<ListNode*> v;
    Solution s;
    auto ret = s.mergeKLists(v);
    return 0;
}
