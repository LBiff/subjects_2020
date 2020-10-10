// 给出一个以头节点 head 作为第一个节点的链表。链表中的节点分别编号为：node_1, node_2, node_3, ... 。
// 每个节点都可能有下一个更大值（next larger value）：对于 node_i，如果其 next_larger(node_i) 是 node_j.val，
// 那么就有 j > i 且  node_j.val > node_i.val，而 j 是可能的选项中最小的那个。如果不存在这样的 j，那么下一个更大值为 0 。
// 返回整数答案数组 answer，其中 answer[i] = next_larger(node_{i+1}) 。
// 注意：在下面的示例中，诸如 [2,1,5] 这样的输入（不是输出）是链表的序列化表示，其头节点的值为 2，第二个节点值为 1，第三个节点值为 5 。

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


#include <vector>
#include <stack>
using namespace std;

//单调栈解决
vector<int> nextLargerNodes(ListNode* head) 
{
    //栈低到栈顶递减，谁将其弹出，谁就是第一个比其大的
    stack<pair<int,int>> stk; //<value,idx>
    vector<int> ret;
    int cur_idx = 0;
    while(head)
    {
        ret.push_back(0);
        //将比其小的弹出
        while(!stk.empty())
        {
            auto top = stk.top();
            if(top.first < head->val)
            {
                ret[top.second] = head->val;
                stk.pop();
            }
            else
            {
                break;
            }
        };
        stk.push({head->val, cur_idx});
        cur_idx++;
        head = head->next;
    };

    return ret;
};