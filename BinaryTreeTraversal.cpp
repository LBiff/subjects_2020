//二叉树的递归和非递归的遍历
//前序遍历［中，左，右］　中［左，中，右］　后［左，右，中］

#include<iostream>
#include <stack>
using namespace std;

struct BinaryNode
{
    BinaryNode* _left; //左孩子
    BinaryNode* _right;
    uint64_t _value;

    BinaryNode(BinaryNode* l, BinaryNode* r, uint64_t v):
              _left(l), _right(r), _value(v){};
};

//递归版本的遍历
void FrontTraversal(const BinaryNode* root)
{
    if(!root)
    {
        return;
    };
    cout << root->_value << endl;
    FrontTraversal(root->_left);
    FrontTraversal(root->_right);
};

void MiddleTraversal(const BinaryNode* root)
{
    if(!root)
    {
        return;
    }

    MiddleTraversal(root->_left);
    cout << root->_value << endl;
    MiddleTraversal(root->_right);
};

void BackTraversal(const BinaryNode* root)
{
    if(!root)
    {
        return;
    };
    BackTraversal(root -> _left);
    BackTraversal(root -> _right);
    cout << root->_value << endl;
};

//非递归版的遍历时间O(N), 空间O(h)，h是树的高度
//非递归先序遍历
//先序 中左右 --栈实现， 入栈
void PreOrder(const BinaryNode* root)
{
    if(!root)
    {
        stack<BinaryNode*> s;
        s.push(const_cast<BinaryNode*>(root));

        while(!s.empty())
        {
            BinaryNode* cur_node = s.top();
            cout << cur_node->_value << endl;
            s.pop();

            //先右后左
            if(cur_node->_right)
            {
                s.push(cur_node->_right);
            };

            if(cur_node->_left)
            {
                s.push(cur_node->_left);
            }
        }
    }
}

//非递归中序遍历
//head的遍历过程
void MidOrder(const BinaryNode* root)
{
    if(root)
    {
        stack<BinaryNode*> stack;
        BinaryNode* head = const_cast<BinaryNode*>(root); //不需要先压root
        while(head || !stack.empty())
        {
            //整体流程： 先把中--左-左..所有的左节点入栈，弹出顺序是左中
            //弹一个左打印，head走到右节点
            if(head == nullptr)  //所有的左节点入栈后弹出一个打印，head走到右节点
            {
                uint64_t v = stack.top()->_value;
                head = stack.top();
                stack.pop();
                cout << v << endl;
                head = head->_right;
            }
            else  //节点不为空，压其所有的左节点
            {
                stack.push(head);
                head = head->_left;
            }
        }
    }
}

//非递归后序遍历
//先序中左右--中右左--左右中
void BackOrder(const BinaryNode* root)
{
    if(!root)
    {
        stack<BinaryNode*> s;
        stack<BinaryNode*> s_help;
        s.push(const_cast<BinaryNode*>(root));

        while(!s.empty())
        {
            BinaryNode* cur_node = s.top();
            s_help.push(cur_node);
            s.pop();

            //先左后右
            if(cur_node->_right)
            {
                s.push(cur_node->_left);
            };

            if(cur_node->_left)
            {
                s.push(cur_node->_right);
            }
        };

        while(!s_help.empty())
        {
            cout << s_help.top()->_value << endl;
            s_help.pop();
        }
    }
};


//Morris遍历, 时间O(N), 空间O(1),不属于任何一种遍历
//cur移动则打印
//实现的重点是，其实只是利用了最右节点的下一节点是null还是
//节点右移动，再也不会回到该节点
enum TraversalType
{
    Front,
    Mid,
    Back
};

//前序：有左子树，第一次来到打印，没有左子树也说明第一次来到
//中序， 有左子树，第2次来到打印，没有左子树 左中右，打印的是中，也打印
//M遍历只标记1,2次，没有第3次标记,后续是第3次标记
//后序， 当第二次来到，逆序打印左子树的右边界, 遍历完单独逆序打印整棵树的有边界
//后序中的逆序操作可以不用栈，直接树改逆序后调回来
//为什么选左子树最右子节点，因为遍历过程遍历完左树后回到该节点再右移

void Morris(const BinaryNode* root, TraversalType type)
{
    BinaryNode* cur = const_cast<BinaryNode*>(root);
    while(cur)
    {
        if(cur->_left)  //有左子树，找到左子树的最右节点mostright，如果mostright右节点为Null,指向cur,cur向左
                        //mostright右节点为cur, mostright右孩子指回null,cur向右

        {
            BinaryNode* most_right = cur -> _left;
            while(most_right -> _right && most_right->_right != cur)
            {
                most_right = most_right -> _right;
            };
            if(!most_right -> _right)  //右孩子为空,第1次来到
            {
                if(type == Front)  //前序打印
                {
                    cout << cur->_value <<endl;
                };
                most_right -> _right = cur;
                cur = cur->_left;
            }
            else  //右孩子为cur, , 遍历左子树到最后，遍历右子树，第2次来到
            {
                if(type == Mid)  //前序打印，第2次来到cur
                {
                    cout << cur->_value <<endl;
                };


                most_right -> _right = nullptr;

                if(type == Back) //当第二次来到，逆序打印左子树的右边界
                {
                    BinaryNode* r = cur->_left;
                    stack<BinaryNode*> s;
                    s.push(r);
                    while(r->_right)
                    {
                        s.push(r->_right);
                        r = r->_right;
                    };
                    while(!s.empty())
                    {
                        cout << s.top()->_value << endl;
                        s.pop();
                    }
                }
                cur = cur -> _right;
            }

           
        }
        else //无左子树，修改最右子节点，向左，第1次来到
        {
            if(type == Front || type == Mid)  //前序打印
            {
                cout << cur->_value <<endl;
            };
            cur = cur->_right;

        }
    };

//遍历完，后续打印整颗树的右边界
    cur = const_cast<BinaryNode*>(root);
    if(type == Back) //当第二次来到，逆序打印左子树的右边界
    {
        stack<BinaryNode*> s;
        s.push(cur);
        while(cur->_right)
        {
            s.push(cur->_right);
            cur = cur->_right;
        };
        while(!s.empty()) 
        {
            cout << s.top()->_value << endl;
            s.pop();
        }
    }
};

int main()
{
    BinaryNode n_0{nullptr,nullptr,0};
    BinaryNode n_1{nullptr,nullptr,1};
    BinaryNode n_2{nullptr,nullptr,2};
    BinaryNode n_3{nullptr,nullptr,3};
    BinaryNode n_4{nullptr,nullptr,4};
    BinaryNode n_5{nullptr,nullptr,5};
    BinaryNode n_6{nullptr,nullptr,6};
    BinaryNode n_7{nullptr,nullptr,7};

    n_0._left = &n_1;
    n_0._right = &n_2;

    n_1._left = &n_3;
    n_1._right = &n_4;

    n_2._left = nullptr;
    n_2._right = &n_5;

    n_3._left = &n_6;
    n_3._right = nullptr;

    n_4._left = nullptr;
    n_4._right = nullptr;

    n_5._left = &n_7;
    n_5._right = nullptr;

    n_6._left = nullptr;
    n_6._right = nullptr;
    
    n_7._left = nullptr;
    n_7._right = nullptr;

    //前序
    cout << "前序" << endl;
    FrontTraversal(&n_0);
    cout << "前序Morris" << endl;
    Morris(&n_0, Front);

    cout <<"-----" << endl;
    //中序
    cout << "中序" << endl;
    MiddleTraversal(&n_0);
    cout << "中Morris" << endl;
    Morris(&n_0, Mid);

    cout <<"-----" << endl;
    //中序
    cout << "后序" << endl;
    BackTraversal(&n_0);
    cout << "后Morris" << endl;
    Morris(&n_0, Back);

    // //后序
    // cout << "后序" << endl;
    // BackTraversal(&n_0);
    // cout << "后Morris" << endl;
    // Morris(&n_0, Back);


    // //M测试
    // BinaryNode n_1{nullptr,nullptr,1};
    // BinaryNode n_2{nullptr,nullptr,2};
    // BinaryNode n_3{nullptr,nullptr,3};
    // BinaryNode n_4{nullptr,nullptr,4};
    // BinaryNode n_5{nullptr,nullptr,5};
    // BinaryNode n_6{nullptr,nullptr,6};
    // BinaryNode n_7{nullptr,nullptr,7};

    // n_1._left = &n_2;
    // n_1._right = &n_3;

    // n_2._left = &n_4;
    // n_2._right = &n_5;

    // n_3._left = &n_6;
    // n_3._right = &n_7;

    // n_4._left = nullptr;
    // n_4._right = nullptr;

    // n_5._left = nullptr;
    // n_5._right = nullptr;

    // n_6._left = nullptr;
    // n_6._right = nullptr;

    // n_7._left = nullptr;
    // n_7._right = nullptr;

    // Morris(&n_1);

    // int a = 1;
    // int n = 3;
    return 0;
    
}