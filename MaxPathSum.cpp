//  124. 二叉树中的最大路径和
// 给定一个非空二叉树，返回其最大路径和。
// 本题中，路径被定义为一条从树中任意节点出发，
// 达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
#include <cstdlib>
#include <algorithm>
#include <climits>
using namespace std;

//计算前提是存在的最大的路径肯定是以某个节点为根节点进行扩展
 struct TreeNode 
 {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution 
{
public:
    Solution():max_sum(INT_MIN){};

    //计算以node节点为根节点为>>>起点<<<的最大路径和
    int max_dp(TreeNode* node)
    {
        if(!node)
        {
            return 0;
        };

        int left = max(max_dp(node->left), 0);
        int right = max(max_dp(node->right), 0);
        //更新
        max_sum = max(max_sum, node->val + left + right);

        return node->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) 
    {
        max_dp(root);
        return max_sum;
    };
private:
    int max_sum;
};
