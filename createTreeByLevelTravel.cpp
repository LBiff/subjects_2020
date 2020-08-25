// 根据给定的层次遍历的二叉树构建二叉树，重建二叉树
//[3,9,20,null,null,15,7]

#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

//关于null的定义
#define nullTreeNodeStr "null"

struct TreeNode
{
    int _v;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : _v(v),left(nullptr), right(nullptr){};
};

TreeNode* TransTreeNode(string s)
{
    return s == nullTreeNodeStr ? nullptr : new TreeNode(atoi(s.c_str()));
};

//获取以特定字符分隔的TreeNode数组
// [3,9,20,null,null,15,7]
static vector<TreeNode*> GetTreeNodeVSpiltByChar(char c)
{
    string s;
    getline(cin,s);
    vector<TreeNode*> v;
    if(s.empty())
    {
        return v;
    }
    
    //去除前后括号************
    s.erase(s.begin());
    s.erase(s.end() - 1);


    size_t first_pos = s.find_first_of(c,0);
    v.push_back(TransTreeNode(s.substr(0, first_pos)));
    int pre = first_pos;
    size_t pos =  s.find_first_of(c,pre + 1);
    while(pos != string::npos)
    {
        v.push_back(TransTreeNode(s.substr(pre+1, pos-pre -1)));
        pre = pos;
        pos = s.find_first_of(c,pos + 1);
    };
    v.push_back(TransTreeNode(s.substr(pre+1)));
    return v;   
};


TreeNode* CreateTree(vector<TreeNode*> v)
{
    if(v.empty())
    {
        return nullptr;
    };

    auto root = v[0];
    queue<TreeNode*> q;
    q.push(root);
    int idx = 1; //当前还未处理的
    while(!q.empty() && idx < v.size())
    {
        int count = q.size();
        for(int i = 0; i < count; i++)
        {
            auto front = q.front();
            q.pop();
            if(front == nullptr)
            {
                continue;
            }

            if(idx < v.size())
            {
                auto l = v[idx++];
                front->left = l;
                q.push(l);
            }
            else
            {
                break;
            };

            if(idx < v.size())
            {
                auto r = v[idx++];
                front->right = r;
                q.push(r);
            }
            else
            {
                break;
            }
        };
    };

    return root;
};


// int main()
// {
//     vector<TreeNode*> v = GetTreeNodeVSpiltByChar(',');
//     auto root = CreateTree(v);
//     return 0;
// }
