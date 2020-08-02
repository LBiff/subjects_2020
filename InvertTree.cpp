//逐层翻转二叉树
// 示例：
// 输入：
//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9
// 输出：
//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1


struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//递归
TreeNode* invertTree(TreeNode* root)
{
    if(!root)
    {
        return nullptr;
    };

    TreeNode* l = invertTree(root->left);
    TreeNode* r = invertTree(root->right);
    root ->left = r;
    root ->right = l;
    return root;
}
