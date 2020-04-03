//　单链表的partition划分为　< = >给定值的区间
//　空间O(N) 将链表复制到数组中进行，后重新连接
//空间O(1) small, equ, greater三个结点指针，找出各自的第一个节点，再遍历往上挂，最后连接
//调整的是原链表的next

#include <forward_list>
#include <iostream>
using namespace std;


struct Node
{
    Node* _next;
    int _value;
    Node(Node* node = NULL, int value = -1)
    {
        _next = node;
        _value = value;
    }
};

//O(1)
void ListPartation(Node& head, int num)
{
    Node*first_small = NULL;
    Node* first_equ = NULL;
    Node* first_greater = NULL;
    //找出各自第一次出现的
    for (Node* np = const_cast<Node*>(&head); np != NULL; np = np->_next)
    {
        if(first_small && first_equ && first_greater)
        {
            break;
        }
        if(!first_small)
        {
            if(np->_value < num)
            {
                first_small = np;
            }
        };
        if(!first_equ)
        {
            if(np->_value == num)
            {
                first_equ = np;
            }
        };
        if(!first_greater)
        {
            if(np->_value > num)
            {
                first_greater = np;
            }
        };
    };

    //遍历往上挂
    Node* last_small = first_small;
    Node* last_equ = first_equ;
    Node* last_greater = first_greater;
    for (Node* np = const_cast<Node*>(&head); np != NULL; np = np->_next)
    {
        if(np->_value < num && np != first_small)
        {
                last_small->_next = np;
                last_small = np;
                continue;
        };

        if(np->_value == num && np != first_equ)
        {
            last_equ->_next = np;
            last_equ = np;
            continue;
        };

        if(np->_value > num && np != first_greater)
        {

                last_greater->_next = np;
                last_greater = np;
                continue;
        };
    };

    //连接
    if(first_small)
    {
        head = *first_small;
        if(first_equ)
        {
            last_small->_next = first_equ;
            if(first_greater)
            {
                last_equ->_next = first_greater;
                last_greater->_next = NULL;
            }
            else
            {
                last_equ->_next = NULL;
            }
        }
        else 
        {
            if(first_greater)
            {
                last_small->_next = first_greater;
                last_greater->_next = NULL;
            }
            else
            {
                last_small->_next = NULL;
            }
        }
    }
    else
    {
         if(first_equ)
        {
            head = *first_equ;
            if(first_greater)
            {
                last_equ->_next = first_greater;
                last_greater->_next = NULL;
            }
            else
            {
                last_equ->_next = NULL;
            }
        }
        else 
        {
            head = *first_greater;
            last_greater->_next = NULL;
        }
    }
}

void PrintList(const Node& head)
{
    Node* node =const_cast<Node*>(&head);
    while(node != NULL)
    {
        cout << node->_value << " ";
        node = node->_next;
    }
    cout << endl;

}
int main()
{
    Node n_1(NULL,1);
    cout << "1: " << &n_1 << endl;
    Node n_2(NULL,5);
    cout << "5: " << &n_2 << endl;
    Node n_3(NULL,2);
    cout << "2: " << &n_3 << endl;
    Node n_4(NULL,8);
    cout << "8: " << &n_4 << endl;
    Node n_5(NULL,4);
    cout << "4: " << &n_5 << endl;
    Node n_6(NULL,15);
    cout << "15: " << &n_6 << endl;
    Node n_7(NULL,9);
    cout << "9: " << &n_7 << endl;
    n_1._next = &n_2;
    n_2._next = &n_3;
    n_3._next = &n_4;
    n_4._next = &n_5;
    n_5._next = &n_6;
    n_6._next = &n_7;
    n_7._next = NULL;

    ListPartation(n_1,5);
    PrintList(n_1);
    return 0;
}