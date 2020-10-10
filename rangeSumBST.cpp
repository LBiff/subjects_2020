// 给定二叉搜索树的根结点 root，返回 L 和 R（含）之间的所有结点的值的和。
// 二叉搜索树保证具有唯一的值。
// 示例 1：
// 输入：root = [10,5,15,3,7,null,18], L = 7, R = 15
// 输出：32
// 示例 2：
// 输入：root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
// 输出：23

#include <stack>
using namespace std;

//10.9
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

//中序遍历是升序
int rangeSumBST(TreeNode* root, int L, int R) 
{
    int ret = 0;
    stack<TreeNode*> stk;
    auto head = root;
    while(!stk.empty() || head)
    {
        if(!head)
        {
            auto top = stk.top();
            stk.pop();
            ret += top->val >= L && top->val <= R ? top->val : 0;
            if(top->val > R)
            {
                break;
            };
            head = top;
            head = head -> right;
        }
        else
        {
            stk.push(head);
            head = head -> left;
        }
    };

    return ret;
};