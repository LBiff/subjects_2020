// 删除二叉搜索树中的节点
// 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。
// 返回二叉搜索树（有可能被更新）的根节点的引用。
// 一般来说，删除节点可分为两个步骤：
// 首先找到需要删除的节点；
// 如果找到了，删除它。
// 说明： 要求算法时间复杂度为 O(h)，h 为树的高度。
//https://leetcode-cn.com/explore/learn/card/introduction-to-data-structure-binary
//-search-tree/65/basic-operations-in-a-bst/179/
 struct TreeNode
  {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
// 如果目标节点没有子节点，我们可以直接移除该目标节点。
// 如果目标节只有一个子节点，我们可以用其子节点作为替换。
// 如果目标节点有两个子节点，我们需要用其中序后继节点或者前驱节点来替换，再删除该目标节点。
#include <algorithm>
using namespace std;

//返回根节点
TreeNode* deleteNode(TreeNode* root, int key) 
{
    if(!root)
    {
        return nullptr;
    };
    if(key < root->val)
    {
        root->left =  deleteNode(root->left, key);
        return root;
    };
    if(key > root->val)
    {
        root->right =  deleteNode(root->right, key);
        return root;
    };

    //当key==root->val时，则找到该节点
    //没有左子树，右子树占据
    if(!root->left)
    {
        auto r = root->right;
        delete root;
        return r;
    };
    //没有右子树，左子树占据
    if(!root->right)
    {
        auto l = root->left;
        delete root;
        return l;
    };

    //左右子树都有
    //找到该节点中序遍历的下一值进行替换
    auto tmp = root->right;
    //找到右节点的最左节点
    while(tmp->left)
    {
        tmp = tmp->left;
    };
    swap(root->val, tmp->val);
    root->right = deleteNode(root->right,key); //Important
    return root;    
}
