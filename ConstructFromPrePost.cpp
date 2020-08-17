#include <vector>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//返回根据前序和中序构造的树的根节点
TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) 
{
    int len = pre.size();
    if(len == 0)
    {
        return nullptr;
    };
    //从前序中拿出根节点;
    TreeNode* root = new TreeNode(pre.front());
    if(len == 1)
    {
        return root;
    }
    //从中序中找到根节点
    int root_v = pre.front();
    int l_count = 0;
    for(auto i : post)
    {
        if(i == root_v)
        {
            break;
        };
        l_count++;
    };
    int r_count = len - 1 - l_count;
    vector<int> pre_l_new(l_count);
    vector<int> post_l_new(l_count);
    vector<int> pre_r_new(r_count);
    vector<int> post_r_new(r_count);
    if(l_count > 0)
    {
        copy(pre.begin() + 1, pre.begin() + 1 + l_count, pre_l_new.begin());
        copy(post.begin(), post.begin() + l_count, post_l_new.begin());
    };
    if(r_count > 0)
    {
        copy(pre.begin() + 1 + l_count, pre.end(), pre_r_new.begin());
        copy(post.begin() + 1 + l_count, post.end(), post_r_new.begin());
    }

    root -> left = constructFromPrePost(pre_l_new, post_l_new);
    root -> right = constructFromPrePost(pre_r_new, post_r_new);
    return root;
}

int main()
{
    vector<int> pre{1,2,4,5,3,6,7};
    vector<int> post{4,5,2,6,7,3,1};
    auto ret = constructFromPrePost(pre, post);
    return 0;
}