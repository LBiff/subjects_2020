//二叉树的序列化与序列化
#include <string>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//前序
//递归
string serialize(TreeNode* root) 
{
    string ret;
    if(!root)
    {
        ret += "#";
        ret += "!";
        return ret;
    };
    
    ret += to_string(root->val);
    ret += "!";
    ret += serialize(root->left);
    ret += serialize(root ->right);
    return ret;
};
//反序列化
TreeNode* CreateTree(queue<TreeNode*>& q)
{
    TreeNode* n = q.front();
    q.pop();
    if(n == nullptr)
    {
        return nullptr;
    };
    
    TreeNode* head = n;
    head->left = CreateTree(q);
    head->right = CreateTree(q);
    return head;
};

//动态规划
string serialize_dp(TreeNode* root)
{
    string ret;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty())
    {
        TreeNode* head = s.top();
        s.pop();
        if(head)
        {
            ret += to_string(head->val);
            s.push(head->right);
            s.push(head->left);
        }
        else
        {
            ret += "#";
        }
        ret += "!";
    };
    return ret;
};


int main()
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = nullptr;
    n2.right = nullptr;
    n3.left = &n4;
    n3.right = &n5;
    n4.left = nullptr;
    n4.right = nullptr;
    n5.left = nullptr;
    n5.right = nullptr;

    string a = serialize_dp(&n1);
    string b = serialize(&n1);
    return 0;
}



