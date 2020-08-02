//二叉树的最大深度
// 给定一个二叉树，找出其最大深度。
// 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
// 说明: 叶子节点是指没有子节点的节点。

#include <algorithm>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//暴力递归
int maxDepth(TreeNode* root) 
{
    if(!root)
    {
        return 0;
    };
    if(!(root->left) && !(root->right))
    {
        return 1;
    };

    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
};
