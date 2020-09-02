// 129. 求根到叶子节点数字之和
// 给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
// 例如，从根到叶子节点路径 1->2->3 代表数字 123。
// 计算从根到叶子节点生成的所有数字之和。


struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <string>
#include <queue>
using namespace std;

int sum = 0;
// root节点进来处理
void dp(const TreeNode* root, string cur_sum)
{
    if(!root)
    {
        return;
    };
    cur_sum += to_string(root->val);
    if(!(root->left) && !(root->right))
    {
        sum += atoi(cur_sum.c_str());
        return;
    };

    if(root->left)
    {
        dp(root->left, cur_sum);
    };
    if(root->right)
    {
         dp(root->right, cur_sum);
    }
};

int sumNumbers_2(TreeNode* root)
{

};



int sumNumbers(TreeNode* root) 
{
    dp(root, "");
    return sum;
};

int main()
{
//     1
//    / \
//   2   3

    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = nullptr;
    n2.right = nullptr;
    n3.left = nullptr;
    n3.right = nullptr;

    auto ret = sumNumbers(&n1);
    return 0;
}

