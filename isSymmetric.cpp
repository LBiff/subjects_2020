// 剑指 Offer 28. 对称的二叉树
// 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
//     1
//    / \
//   2   2
//    \   \
//    3    3
//  
// 示例 1：

// 输入：root = [1,2,2,3,4,4,3]
// 输出：true
// 示例 2：

// 输入：root = [1,2,2,null,3,null,3]
// 输出：false


// 1. 可以层次遍历去做
// 2. 递归

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

// 判断两个子树是否对称
bool isSymmetricForTwoNode(TreeNode* l, TreeNode* r)
{
    if(l && !r || !l && r)
    {
        return false;
    };
    if(!l && !r)
    {
        return true;
    }
    
    if(l->val == r->val)
    {
        return isSymmetricForTwoNode(l->left, r->right) && isSymmetricForTwoNode(l->right, r->left);
    }
    else
    {
        return false;
    }
};

bool isSymmetric(TreeNode* root) 
{
    if(!root)
    {
        return true;
    };

    return isSymmetricForTwoNode(root->left, root -> right);
};
