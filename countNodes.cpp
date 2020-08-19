// 计算完全二叉树的节点个数

// 给出一个完全二叉树，求出该树的节点个数。
// 说明：
// 完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，
// 并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。
#include <algorithm>
#include <cmath>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 普通二叉树的计算方式
int countNodes_1(TreeNode* root) 
{
    if(!root)
    {
        return 0;
    };
    return 1 + countNodes(root -> left) + countNodes(root -> right);
}

// 考虑完全二叉树的特殊性
// 时间 O(lgn * lgn)
int countNodes(TreeNode* root) 
{
    if(!root)
    {
        return 0;
    };
    // 左右子树的高度
    int lh = 0;
    auto l_root = root;
    while(l_root)
    {
        lh++;
        l_root = l_root ->left;
    }
    int rh = 0;
    auto r_root = root;
    while(r_root)
    {
        lh++;
        r_root = r_root ->right;
    };

    //满二叉树
    if(lh = rh)
    {
        return pow(2, lh) - 1;
    };

    //按普通计算
    // 由于完全二叉树肯定有一个左或右子树是满二叉树，所以只有一个会递归出去
    return 1 + countNodes(root->left) + countNodes(root -> right);
}