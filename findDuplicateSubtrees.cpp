// 给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
// 两棵树重复是指它们具有相同的结构以及相同的结点

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
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;


//牛皮的标识符法
// 节点node的id=(node->val, node->left.id, node-> right.id)
//创建一颗树各节点的id
string CreateNodesId(TreeNode* root, unordered_map<TreeNode*, string>& id_mp, unordered_map<string, TreeNode*>& diff_ids, 
                     unordered_map<string, TreeNode*>& same_ret)
{
    if(!root)
    {
        return "NULL";
    };
    auto iter = id_mp.find(root);
    string ret_s;
    if(iter != id_mp.end())
    {
        ret_s = iter -> second;
    }
    else
    {
        ret_s += to_string(root -> val);
        ret_s += "_";
        ret_s += CreateNodesId(root->left, id_mp, diff_ids, same_ret);
        ret_s += "_";
        ret_s += CreateNodesId(root->right, id_mp, diff_ids, same_ret);
    };

    auto iter_diff = diff_ids.find(ret_s);
    if(iter_diff == diff_ids.end())
    {
        diff_ids.insert({ret_s, root});
    }
    else
    {
        if(ret_s != "NULL" && same_ret.find(ret_s) == same_ret.end())
        {
            same_ret.insert({ret_s, root});
        }
    };
    return ret_s;
}
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
{
    unordered_map<TreeNode*, string> id_mp;
    unordered_map<string, TreeNode*> diff_ids; 
    unordered_map<string, TreeNode*> same_ret;
    vector<TreeNode*> ret;
    CreateNodesId(root, id_mp, diff_ids, same_ret);
    for(auto iter = same_ret.begin(); iter != same_ret.end(); iter++)
    {
        ret.push_back(iter->second);
    }
    return ret;
};
