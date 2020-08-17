// 二叉树的最小深度

#include "createTreeByLevelTravel.cpp"

//bfs
int minDepth(TreeNode* root) 
{
    if(root == nullptr)
    {
        return 0;
    };

    //bfs
    queue<TreeNode*> q;
    q.push(root);
    int dep = 0;
    while(!q.empty())
    {
        int level_count = q.size();
        while(level_count-- > 0 && !q.empty())
        {
            auto front = q.front();
            q.pop();
            if(!front->left && !front->right)
            {
                return dep + 1;
            }

            if(front->left)
            {
                q.push(front->left);
            }

            if(front->right)
            {
                q.push(front->right);
            }
        };
        dep++;
    };

    return dep;
};

int main()
{
    vector<TreeNode*> nodeV = GetTreeNodeVSpiltByChar(',');
    auto root = CreateTree(nodeV);
    auto ret = minDepth(root);
    return 0;
}