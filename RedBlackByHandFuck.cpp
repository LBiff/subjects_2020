// 手写红黑树，Fucking!!!

enum Color
{
    Red,
    Black
};

//定义节点
struct Node
{
    int _value;
    Color _color;
    Node* _l;
    Node* _r;
    Node* _p;
    Node(int v, Color c = Red) : _value(v), _color(c), _l(nullptr), _r(nullptr), _p(nullptr){};
};

class RedBlackTree
{
public:
    RedBlackTree(int v)
    {
        _root = new Node(v);
    };

    void insert(int v)
    {
        insert(_root, v);
    };

private:
    //将节点插入到root树中
    void insert(Node* root, int v)
    {
        if(!root)
        {
            root = new Node(v);
        };
        if(root->_value == v)
        {
            return;
        }
        else if(root -> _value < v) //插入到右子树
        {
            insert(root->_r, v);
        }
        else
        {
            insert(root->_l, v);
        }
    };
    
    //以n节点为旋转点进行左旋
    void LeftRoate(Node* n)
    {

    }


private:
    Node* _root;
};
