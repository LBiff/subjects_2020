//N叉数的深度
//给定一个 N 叉树，找到其最大深度。
// 最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。

//队列查找层数
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Node 
{
public:
    int val;
    vector<Node*> children;
    Node() {};
    Node(int _val) 
    {
        val = _val;
    };
    Node(int _val, vector<Node*> _children) 
    {
        val = _val;
        children = _children;
    };
};

class Solution 
{
public:
    int maxDepth(Node* root) 
    {
        if(!root)
        {
            return  0;
        };
        queue<Node*> s;
        int level = 0; //栈中装的层数
        s.push(root);
        while(!s.empty())
        {
            size_t count = s.size();
            while(count-- > 0)
            {
                Node* top = s.front();
                s.pop();
                for(auto c : top->children)
                {
                    if(c)
                    {
                        s.push(c);
                    };
                }
            };
            level++;
        };
        return level;
    }
};