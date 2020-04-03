//打印含有父指针的二叉树的下一节点

#include<iostream>
#include <stdexcept>
using namespace std;

struct Node
{
    int _value;
    Node* _l;
    Node* _r;
    Node* _p;
    Node(int value)
    {
        _value = value;
        _r = nullptr;
        _l = nullptr;
        _p = nullptr;
    }
};

//中序遍历
void MiddleTraversal(const Node* root)
{
    if(!root)
    {
        return;
    }

    MiddleTraversal(root->_l);
    cout << root->_value << endl;
    MiddleTraversal(root->_r);
};

//查找中序遍历的下一节点
bool GetNextNodeByMedianOrder(const Node* node, int& ret_node_value)
{
    if(!node)
    {
        throw invalid_argument("node is nullptr.");
    };

    //有右子树
    if(node->_r)
    {
        //返回右子树的最左孩子
        Node* node_help = const_cast<Node*>(node->_r);
        while(node_help->_l != nullptr)
        {
            node_help  = node_help->_l;
        };
        ret_node_value = node_help->_value;
        return true;
    }
    else //没有右子树
    {
       if(node->_p)
       {
           if(node == node->_p->_l)  //如果是父节点的左孩子
           {
               ret_node_value = node->_p->_value;
               return true;
           }
           else //是其父节点的右孩子
           {
               //向上一直找
               Node* node_help = const_cast<Node*>(node);
               while(node_help->_p)
               {
                   if(node_help == node_help->_p->_l)
                   {
                       ret_node_value = node_help->_p->_value;
                       return true;
                   };
                   node_help = node_help->_p;
               }
           }
       }
    }

    return false;
}

int main()
{
    Node n_0{0};
    Node n_1{1};
    Node n_2{2};
    Node n_3{3};
    Node n_4{4};
    Node n_5{5};
    Node n_6{6};
    Node n_7{7};

    n_0._l = &n_1;
    n_0._r = &n_2;
    n_0._p = nullptr;

    n_1._l = &n_3;
    n_1._r = &n_4;
    n_1._p = &n_0;

    n_2._l = nullptr;
    n_2._r = &n_5;
    n_2._p = &n_0;


    n_3._l = &n_6;
    n_3._r = nullptr;
    n_3._p = &n_1;

    n_4._l = nullptr;
    n_4._r = nullptr;
    n_4._p = &n_1;


    n_5._l = &n_7;
    n_5._r = nullptr;
    n_5._p = &n_2;


    n_6._l = nullptr;
    n_6._r = nullptr;
    n_6._p = &n_3;

    
    n_7._l = nullptr;
    n_7._r = nullptr;
    n_7._p = &n_5;

    MiddleTraversal(&n_0);
    bool a;
    int v;
   a = GetNextNodeByMedianOrder(&n_0, v);
   a = GetNextNodeByMedianOrder(&n_1, v);
   a = GetNextNodeByMedianOrder(&n_2, v);
   a = GetNextNodeByMedianOrder(&n_3, v);
   a = GetNextNodeByMedianOrder(&n_4, v);
   a = GetNextNodeByMedianOrder(&n_5, v);
   a = GetNextNodeByMedianOrder(&n_6, v);
   a = GetNextNodeByMedianOrder(&n_7, v);

    return 0;
}