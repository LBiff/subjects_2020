// 给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
using namespace std;

//中序有序，双指针

void MidTravel(TreeNode* root, vector<int>& v)
{
    if(!root)
    {
        return;
    };
    MidTravel(root->left, v);
    v.push_back(root->val);
    MidTravel(root->right,v);
}


bool findTarget(TreeNode* root, int k) 
{
    vector<int> v;
    MidTravel(root,v);
    int l_idx = 0;
    int r_idx = v.size() - 1;
    while(l_idx < r_idx)
    {
        int sum = v[l_idx] + v[r_idx];
        if(sum == k)
        {
            return true;
        }
        else if(sum < k)
        {
          l_idx++;  
        }
        else
        {
            r_idx--;
        }
    };

    return false;
};

