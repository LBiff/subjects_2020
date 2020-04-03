//给定一个二叉搜索树的根结点 root，返回树中【任意】两节点的差的最小值。

#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    int minDiffInBST(TreeNode* root) 
    {
        vector<int> nodes_v;
        Travel(root,nodes_v);
        if(nodes_v.size() < 2)
        {
            return 0;
        };

        sort(nodes_v.begin(), nodes_v.end());
        int min_v = INT_MAX;
        for(int i = 1; i< nodes_v.size(); i++)
        {
            min_v = min(min_v, nodes_v[i] - nodes_v[i - 1]);
        };

        return min_v;
    };

    //遍历
    void Travel(TreeNode* p, vector<int>& v)
    {
       if(p)
       {
            v.push_back(p->val);
            Travel(p->left, v);
            Travel(p->right, v);
       };
    }
};

int main()
{
    TreeNode n4(4);
    TreeNode n2(2);
    TreeNode n6(6);
    TreeNode n1(1);
    TreeNode n3(3);

    n4.left = &n2;
    n4.right = &n6;
    n2.left = &n1;
    n2.right = &n3;
    n1.left = nullptr;
    n1.right = nullptr;
    n3.left = nullptr;
    n3.right = nullptr;
    n6.left = nullptr;
    n6.right = nullptr;

    Solution s;
    auto ret = s.minDiffInBST(&n4);
    return 0;
}