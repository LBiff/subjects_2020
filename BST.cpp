// 二叉搜索树
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr){};
};
// 1. 在 BST 中查找一个数是否存在
bool isInBST(TreeNode* root, int target) 
{
    if (root == nullptr) return false;
    if (root->val == target) return true;

    return isInBST(root->left, target)
        || isInBST(root->right, target);
};

// 2. 在 BST 中插入一个数
TreeNode* insertIntoBST(TreeNode* root, int val) 
{
    // 找到空位置插入新节点
    if (root == nullptr) return new TreeNode(val);
    // if (root->val == val)
    //     BST 中一般不会插入已存在元素
    if (root->val < val) 
        root->right = insertIntoBST(root->right, val);
    if (root->val > val) 
        root->left = insertIntoBST(root->left, val);
    return root;
};

// 3. 在 BST 中删除一个数

TreeNode* getMin(TreeNode* node) {
    // BST 最左边的就是最小的
    while (node->left != nullptr) node = node->left;
    return node;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return nullptr;
    if (root->val == key) {
        // 这两个 if 把情况 1 和 2 都正确处理了
        // 1. A 恰好是末端节点，两个子节点都为空，那么它可以当场去世了。
        // 2. A 只有一个非空子节点，那么它要让这个孩子接替自己的位置。
        if (root->left == nullptr) return root->right;
        if (root->right == nullptr) return root->left;
        // 处理情况 3
        // 3. A 有两个子节点，麻烦了，为了不破坏 BST 的性质，A 必须找到左子树中最大的那个节点，
        // 或者右子树中最小的那个节点来接替自己
        TreeNode* minNode = getMin(root->right);
        root->val = minNode->val;
        root->right = deleteNode(root->right, minNode->val);
    } else if (root->val > key) {
        root->left = deleteNode(root->left, key);
    } else if (root->val < key) {
        root->right = deleteNode(root->right, key);
    }
    return root;
}