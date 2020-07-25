// 给你一棵以 root 为根的二叉树和一个 head 为第一个节点的链表。
// 如果在二叉树中，存在一条一直向下的路径，且每个点的数值恰好一一
// 对应以 head 为首的链表中每个节点的值，那么请你返回 True ，否则返回 False 。
// 一直向下的路径的意思是：从树中某个节点开始，一直连续向下的路径。


struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution 
{
public:

    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        
    }
};