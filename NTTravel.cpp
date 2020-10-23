//N叉树的遍历
//其实跟二叉树的遍历是一个套路

//前序
//stack, 弹出一个入子孩子，从右到左入
#include <vector>
#include <stack>
using namespace std;
class Node 
{
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<int> preorder(Node* root) 
{
    vector<int> ret;
    if(root)
    {
        stack<Node*> s;
        s.push(root);
        while(!s.empty())
        {
            Node* top = s.top();
            ret.push_back(top->val);
            s.pop();
            for(int i = top->children.size() - 1; i >=0; i--)
            {
                if(top->children[i])
                {
                    s.push(top->children[i]);
                }
            }
        }
    };
    return ret;
}