//二叉树的后序遍历
#include <vector>
using namespace std;

//Thinking
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


class Solution 
{
public:
    vector<int> postorder(Node* root) 
    {
        
    }
};