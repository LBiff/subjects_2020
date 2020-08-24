// 剑指 Offer 07. 重建二叉树
// 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

// 例如，给出

// 前序遍历 preorder = [3,9,20,15,7]
// 中序遍历 inorder = [9,3,15,20,7]
// 返回如下的二叉树：

//     3
//    / \
//   9  20
//     /  \
//    15   7
 
 struct TreeNode 
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };
 
 #include <vector>
 #include <map>
 using namespace std;


// [pre_start, pre_end]标记前序范围，in_map--中序的<int, idx>
TreeNode* buildTreeDp(const vector<int>& preorder, const vector<int>& inorder, 
                        int pre_start, int pre_end, int in_start, int in_end, const map<int, int>& in_map)
{
    if(pre_end - pre_start < 0 || pre_end - pre_start != in_end - in_start || pre_end > ((int)(preorder.size()) - 1))
    {
        return nullptr;
    };

    TreeNode* root = new TreeNode(preorder[pre_start]);
    if(pre_start == pre_end)
    {
        return root;
    };

    int in_root_idx = in_map.find(preorder[pre_start])->second;
    int left_count = in_root_idx - in_start;
    int pre_l_end_idx = pre_start + left_count;

    root->left = buildTreeDp(preorder, inorder, pre_start + 1, pre_l_end_idx, in_start, in_root_idx - 1, in_map);
    root -> right = buildTreeDp(preorder, inorder, pre_l_end_idx + 1, pre_end, in_root_idx + 1, in_end, in_map);
    return root;
};

// 返回root节点
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
    if(preorder.empty() || preorder.size() != inorder.size())
    {
        return nullptr;
    };
    map<int, int> in_map;
    for(int i = 0; i < inorder.size(); i++)
    {
        in_map.insert({inorder[i], i});
    };

    return buildTreeDp(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, in_map);
};



int main()
{
    vector<int> preorder{3,9,20,15,7};
    vector<int> inorder {9,3,15,20,7};
    auto ret = buildTree(preorder, inorder);
    return 0;
}