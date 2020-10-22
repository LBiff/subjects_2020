// 你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。
// 空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。
// 示例 1:
// 输入: 二叉树: [1,2,3,4]
//        1
//      /   \
//     2     3
//    /    
//   4     
// 输出: "1(2(4))(3)"


struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


void pre_travel(TreeNode* t, string& s)
{
    if(!t)
    {
        return;
    };
    s += to_string(t -> val);
    if(!(t -> left)) 
    {
        if(!(t->right))
        {
            return;
        }
        else  //左节点为空右节点不为空则加()
        {
            s += "()";
        }
        
    }
    else
    {
        s += '(';
        pre_travel(t->left, s);
        s += ')';
    }
    
    if(t -> right)
    {
        s += '(';
        pre_travel(t->right, s);
        s += ')';
    }
};

string tree2str(TreeNode* t) 
{
    string ret;
    pre_travel(t, ret);
    return ret;
}