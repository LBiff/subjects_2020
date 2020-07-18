// 面试题68 - II. 二叉树的最近公共祖先
// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，
// 最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

// 【原理】以root为根的子树，p，q分布四种情况：
// （1）p，q分布在左右，则root为最近公共祖先
//   (2) p和q同时在左或者右，则递归左或者右
// (3)p和q都没在左右，一般不存在，返回root

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
    //返回在以root为根节点的子树上查找p和q的结果
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || !root)
        {
            return root;
        };
        auto l = lowestCommonAncestor(root -> left, p, q);
        auto r = lowestCommonAncestor(root -> right, p, q);
        if(l && r) //分布在左右子树上
        {
            return root;
        };
        return l ? l : r;
    }
};

//方法二： 记录所有的<node,pnode> 链式查找
#include <unordered_map>
#include <unordered_set>
using namespace std;
// unordered_map<TreeNode*, TreeNode*> mp; //<node, pnode>
void CreateMap(TreeNode* root,  unordered_map<TreeNode*, TreeNode*>& mp) 
{
    if(root)
    {
        if(root->left)
        {
            mp.insert({root->left, root});
            CreateMap(root ->left, mp);
        };
        if(root -> right)
        {
            mp.insert({root->right, root});
            CreateMap(root ->right, mp);
        };
    };
};


 TreeNode* lowestCommonAncestor_2(TreeNode* root, TreeNode* p, TreeNode* q) 
 {
     if(!root || !p || !q)
     {
         return nullptr;
     };
     if(p == root || q == root)
     {
         return root;
     }
     unordered_map<TreeNode*, TreeNode*> mp; //<node, pnode>
     CreateMap(root, mp);
     unordered_set<TreeNode*> st;
     TreeNode* tmp = p;
     st.insert(tmp);
     st.insert(root);
     while(tmp != root)
     {
         auto iter = mp.find(tmp);
         if(iter != mp.end())
         {
            st.insert(iter -> second);
            tmp = iter ->second;
         }
     };
     
     tmp = q;
     while(tmp != root)
     {
         if(st.find(tmp) != st.end())
         {
             return tmp;
         };
         tmp = mp.find(tmp) -> second;
     };
     
     return nullptr;
 };

