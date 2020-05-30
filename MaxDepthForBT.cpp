//二叉树的最大深度
#include <queue>
using namespace std;

 struct TreeNode 
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
 };

//层次遍历用队列
int maxDepth(TreeNode* root) 
{
    if(!root)
    {
        return 0;
    }
    queue<TreeNode*> q;
    int deep = 0;
    q.push(root);
    while(!q.empty())
    {
        //弹出所有的
        int size = q.size();
        deep += 1;
        while(size-- > 0)
        {
            auto top = q.front();
            q.pop();
            if(top->left)
            {
                q.push(top->left);
            };
            if(top->right)
            {
                q.push(top->right);
            };
        }
    };
    return deep;
}
 