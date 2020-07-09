//求解完全二叉树最后一行最后一个节点
struct Node
{
    int _v;
    Node* _l;
    Node* _r;
};

//二分查找的思想
// lgN * lgN
Node* CalLastNode(Node* root)
{
    if(!root && !root->_l)
    {
        return const_cast<Node*>(root);
    };
    //求解左子树和右子树的高度
    int l_h = 0;
    int r_h = 0;
    
    Node* l_node = root ->_l;
    Node* r_node = root -> _r;
    while(l_node)
    {
        l_h++;
        l_node = l_node ->_l;
    };
    while(r_node)
    {
        r_h++;
        r_node = r_node ->_l;
    };
    //二分查找
    if(l_h > r_h)
    {
        return CalLastNode(root -> _l);
    }
    else if(l_h == r_h)
    {
        return CalLastNode(root -> _r);
    }
    //右子树的高度不可能大于左子树
    return nullptr;

};
