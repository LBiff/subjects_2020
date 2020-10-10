// 给定一个二叉树，原地将它展开为一个单链表。
// 例如，给定二叉树
//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
// 将其展开为：
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6


struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <unordered_set>
#include <stack>
using namespace std;

// 图的深度搜索
void flatten(TreeNode* root) 
{
    if(root)
    {
        stack<TreeNode*> stk;
        unordered_set<TreeNode*> st;
        stk.push(root);
        st.insert(root);
        auto pre = root;
        while(!stk.empty())
        {
            auto cur = stk.top();
            stk.pop();
            auto iter_l = st.find(cur->left);
            auto iter_r = st.find(cur->right);
            if(iter_r == st.end() && cur->right)
            {
                stk.push(cur->right);
                st.insert(cur->right);
            };
            if(iter_l == st.end() && cur->left)
            {
                stk.push(cur->left);
                st.insert(cur->left);
            };
            pre->right = cur;
            pre->left = nullptr;
            pre = cur;
        };
        pre->right = nullptr;
    };
};

int main()
{
    auto n1 = new TreeNode(1);
    auto n2 = new TreeNode(2);
    auto n3 = new TreeNode(3);
    auto n4 = new TreeNode(4);
    auto n5 = new TreeNode(5);
    auto n6 = new TreeNode(6);

    n1->left = n2;
    n1->right = n5;
    n2->left = n3;
    n2->right = n4;
    n5->left = nullptr;
    n5->right = n6;

    n3->left = nullptr;
    n3->right = nullptr;
    n4->left = nullptr;
    n4->right = nullptr;
    n6->left = nullptr;
    n6->right = nullptr;

    flatten(n1);
};

