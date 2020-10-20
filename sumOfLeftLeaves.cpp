// 计算给定二叉树的所有左叶子之和。
// 示例：
//     3
//    / \
//   9  20
//     /  \
//    15   7
// 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
class Solution 
{
public:
    //求解一个树的左叶子之和
    int sumOfLeftLeaves(TreeNode* root) 
    {
        if(!root)
        {
            return 0;
        };
        int ret = 0;
        //如果是左叶子
        if(root -> left && !(root -> left -> left) && !(root -> left -> right))
        {
            ret += root -> left -> val;
        }
        ret += sumOfLeftLeaves(root -> left);
        ret += sumOfLeftLeaves(root -> right);
        return ret;
    }
};