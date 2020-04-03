//基础搜索二叉树,不具备平衡性质
#include <cstdlib>
using namespace std;


struct Node
{
    Node* _l;
    Node* _r;
    Node* _p;
    int _v;
    Node(Node* l, Node* r , Node* p, int v):_l(l),_r(r),_p(p),_v(v)
    {
    };
};


class SearchBinaryTree
{
public:
    SearchBinaryTree():_root(nullptr),_size(0)
    {
    };


    void Insert(int i_n_v)
    {
        if(Search(i_n_v))
        {
            return;
        };

        Node* node = new Node(nullptr,nullptr,nullptr,i_n_v);
        Node* t_n = _root;
        if(!_root)
        {
           _root = node;
        }
        while(t_n)
        {
            if(t_n->_v == node->_v)
            {
                return;
            }
            else if(node->_v < t_n->_v)
            {
                if(!t_n->_l)
                {
                    t_n->_l = node;
                    return;
                }
                t_n = t_n->_l;
            }
            else
            {
                if(!t_n->_r)
                {
                    t_n->_r = node;
                    return;
                }
                t_n = t_n->_r;
            };
        };
        node->_p = t_n;
    };

    Node* Search(int s_n_v)
    {
        Node* t_n = _root;
        while(t_n)
        {
            if(s_n_v == t_n->_v)
            {
                return t_n;
            };
            if(s_n_v < t_n->_v)
            {
                t_n = t_n -> _l;
            }
            else
            {
                t_n = t_n -> _r;
            }
        };
        return nullptr;
    };

//如果没有左孩子，用右孩子替换其，环境替换
//如果没有右孩子，用其左孩子替换，环境替换
//有左右孩子，用其右子树的最左节点替换，最左节点的右孩子挂在其父左孩子处，
//或者用其左子树最右节点替换，最右节点的左孩子挂在其父右
    void Del(int del_node_v) 
    {
    }

private:
    Node* _root;
    size_t _size;

};