//二叉树next指针连接右边节点
// 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，
// 则将 next 指针设置为 NULL。
// 初始状态下，所有 next 指针都被设置为 NULL。

//Thinking
class Node 
{
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution 
{
public:
    Node* connect(Node* root) {
        
    }
};
