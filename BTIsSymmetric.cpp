//二叉树的镜像
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(NULL) {}
};

//层次遍历搜判断镜像
class Solution 
{
public:
    bool isSymmetric(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int p_count = q.size();
            vector<TreeNode*> p;
            while(p_count-- > 0)
            {
                TreeNode* top = q.front();
                p.push_back(top);
                q.pop();

                if(top)
                {
                    q.push(top->left);
                    q.push(top->right);
                }
            };
            if(!help(p))
            {
                return false;
            }
        };

        return true;
    };

    //检测镜像
    bool help(const vector<TreeNode*>& v)
    {
        int l = 0;
        int r = v.size() - 1;
        while(l < r)
        {
            if(v[l] && v[r] && v[l]->val != v[r]->val)
            {
                return false;
            }
            else if((v[l] && !v[r]) || (!v[l] && v[r]))
            {
                return false;
            }
            l++;
            r--;
        };
        return true;
    }
};

//翻转二叉树
class Solution_2 
{
public:
    //递归
    TreeNode* mirrorTree_1(TreeNode* root) 
    {
        if(!root)
        {
            return root;
        };
        TreeNode* tmp = root->left;
        root->left = mirrorTree_1(root->right);
        root->right = mirrorTree_1(tmp);
        return root;
    };

    //非递归
    //直接交换每个节点的左右孩子即可
    TreeNode* mirrorTree(TreeNode* root) 
    {
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* p = s.top();
            s.pop();
            if(p)
            {
                TreeNode* l = p->left;
                TreeNode* r = p->right;
                p->left = r;
                p->right = l;
                if(l) s.push(l);
                if(r) s.push(r);
            }
        };
        return root;
    }
};
