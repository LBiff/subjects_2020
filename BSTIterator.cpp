//二叉搜索树迭代器

#include <stack>
#include <iostream>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//重点：搜索二叉树的中序遍历的升序遍历
//原理： 中序遍历非递归版while暂停改写
// 1.从root一路压到最左作为栈的初始化
// next实现： 弹出一个，如果有右孩子，一路压右孩子的左节点
class BSTIterator 
{
public:
    BSTIterator(TreeNode* root)
    {
        PushToLeftMost(root);
    };
    
    /** @return the next smallest number */
    int next() 
    {
        if(!s.empty())
        {
            TreeNode* most_left = s.top();
            s.pop();
            if(most_left->right)
            {
                PushToLeftMost(most_left->right);
            };
            return most_left->val;
        }
    };


    //不断压左节点
    int PushToLeftMost(TreeNode* node)
    {
        while(node)
        {
            s.push(node);
            node = node ->left;
        }
    };
    /** @return whether we have a next smallest number */
    bool hasNext() 
    {
        return !s.empty();
    };

private:
    stack<TreeNode*> s;
};

int main()
{
    TreeNode n7(7);
    TreeNode n3(3);
    TreeNode n15(15);
    TreeNode n9(9);
    TreeNode n20(20);

    n7.left = &n3;
    n7.right = &n15;
    n15.left = &n9;
    n15.right = &n20;

    BSTIterator iterator(&n7);
    int a = 0;
    cout << iterator.next() << endl;   // 返回 3
    cout << iterator.next() << endl;   // 返回 7
    iterator.hasNext(); // 返回 true
    cout << iterator.next() << endl;   // 返回 9
    iterator.hasNext(); // 返回 true
    cout << iterator.next() << endl;   // 返回 15
    iterator.hasNext(); // 返回 true
    cout << iterator.next() << endl;   // 返回 20
    iterator.hasNext(); // 返回 false

    return 0;
}