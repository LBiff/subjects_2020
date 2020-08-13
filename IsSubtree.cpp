// 给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。
// s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

// 示例 1:
// 给定的树 s:

//      3
//     / \
//    4   5
//   / \
//  1   2
// 给定的树 t：

//    4 
//   / \
//  1   2
// 返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。

 struct TreeNode 
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 //------------------------递归解决
 //判断是不是相同的树
 bool isSameTree(TreeNode* s, TreeNode* t)
 {
     if(!s && !t)
     {
         return true;
     }
     if(!t || !s)
     {
         return false;
     }
     return s->val == t->val && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
 }

//递归解决
bool isSubStructure_2(TreeNode* s, TreeNode* t) 
{
    if(!s && !t)
    {
        return false;
    };
    if(!s || !t)
    {
        return false;
    };

    return isSameTree(s,t) || isSubStructure(s->left, t) || isSubStructure(s->right, t);
}


//非递归
//1.前序序列化
//2.kmp
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
//前序的非递归用栈
//!表示空节点， #表示节点结束
string SerializeByPre(TreeNode* head)
{
    string ret;
    stack<TreeNode*> s;
    s.push(head);
    while(!s.empty())
    {
        auto top =  s.top();
        s.pop();
        //先右再左
        if(top)
        {
            ret += to_string(top->val);
            if(top->right)
            {
                s.push(top->right);
            }
            else
            {
                s.push(nullptr);
            }
            
            if(top->left)
            {
                s.push(top->left);
            }
            else
            {
                s.push(nullptr);
            }
        }
        else
        {
           ret += "!";
        };

        ret += "#";
    };

    return ret;
};

//KMP算法
//创建next数组
vector<int> CreateNext(const vector<int>& v)
{

}
bool KMP(const string& s, const string& t)
{
    
}




//非递归解决
bool isSubStructure(TreeNode* s, TreeNode* t) 
{
    string serial_s = SerializeByPre(s);
    string serial_t = SerializeByPre(t);

    //kmp判断t是否是s的子串
    return KMP(serial_s, serial_t);

}