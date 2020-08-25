// 958. 二叉树的完全性检验
// 给定一个二叉树，确定它是否是一个完全二叉树。
// 百度百科中对完全二叉树的定义如下：
// 若设二叉树的深度为 h，除第 h 层外，其它各层 (1～h-1) 的结点数都达到最大个数，
// 第 h 层所有的结点都连续集中在最左边，这就是完全二叉树。（注：第 h 层可能包含 1~ 2h 个节点。）

#include <vector>
#include <queue>
using namespace std;

 struct TreeNode 
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 

 bool isCompleteTree(TreeNode* root) 
 {
     if(!root)
     {
         return false;
     };
    queue<TreeNode*> q;
    q.push(root);
    bool is_leaf = false; //当前判断的节点是不是叶子节点
    while(!q.empty())
    {
        auto top = q.front();
        q.pop();
        auto l = top -> left;
        auto r = top -> right;
        //当前节点是叶子节点时候则全空，不管是不是叶子节点都不允许存在左空右不空的
        if((is_leaf && (l || r)) || (!l && r))
        {
            return false;
        }
        if(l)
        {
            q.push(l);
        };
        if(r)
        {
            q.push(r);
        }
        else  //右子树为空就直接认为以后进来的必须是叶子节点
        {
            is_leaf = true;
        }
    };
    return true;
 };

 int main()
 {
    //  TreeNode* n1 = new TreeNode(1);
    //  TreeNode* n2 = new TreeNode(2);
    //  TreeNode* n3 = new TreeNode(3);
    //  TreeNode* n4 = new TreeNode(4);
    //  TreeNode* n5 = new TreeNode(5);
    //  TreeNode* n6 = new TreeNode(6);
    // vector<TreeNode*> v = GetTreeNodeVSpiltByChar(',');
    // auto root = CreateTree(v);
    // auto ret = isCompleteTree(root);
    // return 0;

     
 }