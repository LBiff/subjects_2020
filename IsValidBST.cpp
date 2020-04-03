//验证搜索二叉树
//原理： 搜索二叉树的中序遍历是严格升序

#include <stack>
#include <cstdlib>
using namespace std;

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
//搜索二叉树中序遍历是升序
bool isValidBST(TreeNode* root) 
{
    if(root)
    {
        if(!root -> left && !root ->right)
        {
            return true;
        }
        int pre_v = INT_MIN;
        stack<TreeNode*> s;
        bool is_first = true; //考虑第一个点是INT_MIN时，相等也是可以的
        while(root || !s.empty())
        {
            if(root) //不断压左节点
            {
                s.push(root);
                root = root -> left;
            }
            else //到最左节点，pop,跳到压右节点
            {
                if(!is_first && s.top()->val <= pre_v)
                {
                    return false;
                };
                is_first = false;
                root = s.top();
                pre_v = s.top()->val;
                s.pop();
                root = root ->right;
            }
        }
    };
    return true;
}
};

