//树的右视图
#include <vector>
#include <queue>
using namespace std;

 struct TreeNode 
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
 //广度优先遍历
vector<int> rightSideView(TreeNode* root) 
{
    queue<TreeNode*> q; //每一层的值
    vector<int> ret;
    if(!root)
    {
        return ret;
    }
    q.push(root);
    while(!q.empty())
    {
        ret.push_back(q.back()->val);
        size_t cur_size = q.size();
        while(cur_size-- > 0)
        {
            if(q.front() -> left)
            {
                q.push(q.front()->left);
            }
            if(q.front() -> right)
            {
                q.push(q.front()->right);
            };
            q.pop();
        }
    };
    return ret;
}   