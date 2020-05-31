//合并二叉树
// 给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。
// 你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为
// 节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

#include <unordered_map>
#include <cstdlib>
using namespace std;

class Solution 
{
public:
//傻缓存反而慢
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
    {
       unordered_map<string, TreeNode*> map;
       return process(t1,t2,map);
    };

    TreeNode* process(TreeNode* t1, TreeNode* t2, unordered_map<string, TreeNode*>& map) 
    {
        if(!t1)
        {
            return t2;
        };
        if(!t2)
        {
            return t1;
        };

        t1->val += t2->val;
        string s_l = to_string(reinterpret_cast<int64_t>(t1->left)) + "_" + 
                               to_string(reinterpret_cast<int64_t>(t2->left));
        string s_r = to_string(reinterpret_cast<int64_t>(t1->right)) + "_" + 
                               to_string(reinterpret_cast<int64_t>(t2->right));
        auto iter_l = map.find(s_l);
        auto iter_r = map.find(s_r);

        if(iter_l != map.end())
        {
            t1->left = iter_l->second;
        }
        else
        {
            t1->left = process(t1->left, t2->left,map);
            map.insert({s_l, t1->left});
        };

        if(iter_r != map.end())
        {
            t1->right = iter_r->second;
        }
        else
        {
            t1->right = process(t1->right, t2->right,map);
            map.insert({s_r, t1->right});
        }
        
        return t1;
    };

//直接递归
    TreeNode* mergeTrees_2(TreeNode* t1, TreeNode* t2) 
    {
        if(!t1)
        {
            return t2;
        };
        if(!t2)
        {
            return t1;
        };

        t1->val += t2->val;
        t1->left = mergeTrees_2(t1->left, t2->left);
        t1->right = mergeTrees_2(t1->right, t2->right);
        return t1;
    };
};


