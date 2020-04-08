//您需要在二叉树的每一行中找到最大的值。
//层次遍历--队列，不是栈
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> largestValues(TreeNode* root) 
{
    vector<int> ret;
    if(!root)
    {
        return ret;
    };

    queue<TreeNode*> s;
    s.push(root);

    while(!s.empty())
    {
        int p_size = s.size();
        priority_queue<int, vector<int>, less<int>> less_heap; //大根堆
        while(p_size-- > 0)
        {
            TreeNode* top = s.front();
            s.pop();
            less_heap.push(top->val);
            if(top->left)
            {
                s.push(top->left);
            };
            if(top->right)
            {
                s.push(top->right);
            }
        };
        ret.push_back(less_heap.top());
    };
    return ret;
};

int main()
{
    TreeNode n1(1);
    TreeNode n3(3);
    TreeNode n2(2);
    TreeNode n5(5);
    TreeNode n32(3);
    TreeNode n9(9);
    n1.left = &n3;
    n1.right = &n2;
    n3.left = &n5;
    n3.right = &n32;
    n2.left = nullptr;
    n2.right = &n9;
    n5.left = nullptr;
    n5.right = nullptr;
    n32.left = nullptr;
    n32.right = nullptr;
    n9.left = nullptr;
    n9.right = nullptr;

    auto ret = largestValues(&n1);
    return 0;
}