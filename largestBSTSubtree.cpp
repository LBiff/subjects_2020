// 给定一个二叉树，找到其中最大的二叉搜索树（BST）子树，其中最大指的是子树节点数最多的。
// 注意:
// 子树必须包含其所有后代。


struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

#include <stack>
#include <vector>
using namespace std;

int largestBSTSubtree(TreeNode* root) 
{
    if(!root)
    {
        return 0;
    }

    //中序遍历,左中右
    vector<int> mid_travel;

    auto cur_node = root;
    stack<TreeNode*> stk;
    while(!stk.empty() || cur_node)
    {
        if(cur_node)
        {
            stk.push(cur_node);
            cur_node = cur_node -> left;
        }
        else
        {
            auto top = stk.top();
            mid_travel.push_back(top->val);
            stk.pop();
            cur_node = top -> right;
        }
    };

    vector<int> dp(mid_travel.size(), 0); //dp[i]表示以i索引结尾的最长连续增长
    dp[0] = 1;
    int max_end_idx = 0;
    int max_len = 1;
    for(int i = 0; i < dp.size(); i++)
    {
        dp[i] = dp[i] > dp[i - 1] ? dp[i - 1] + 1 : 1;
        if(dp[i] > max_len)
        {
            max_len = dp[i];
            max_end_idx = i;
        }
    };

    return mid_travel[max_end_idx - max_len - 1];
}