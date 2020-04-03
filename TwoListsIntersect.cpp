//两链表的相交问题，链表可能成环，时间O(M+N),空间O(1)
//如果相交返回相交节点
//可将一链表入hash_set,另一个查询，但若有环则无线循环，需要判断

#include <iostream>
using namespace std;

struct Node
{
    Node* _next;
    int _value;
    Node( int value, Node* node = nullptr)
    {
        _next = node;
        _value = value;
    };
};

//是否相交，相交返回相交节点
bool  TwoListsIntersect(const Node* head1, const Node*  head2, Node*& intersect_node)
{
    //判断是否有环，　方法１：hash_set, 方法２：快慢指针
    //有环求出入环节点
    auto HasCircle = [](const Node* head, Node*& entry_node)->bool
    {
        if(!head || !(head->_next) || !(head->_next->_next))
        {
            return false;
        }
        Node* low = head->_next;
        Node* fast = head->_next->_next;
        while(fast != low)
        {
          if(!(fast->_next) || !(fast->_next->_next))
          {
              return false;
          };
          low = low->_next;
          fast = fast->_next->_next;
        };
        
        fast = const_cast<Node*>(head);
        while(fast != low)
        {
            fast = fast->_next;
            low = low->_next;
        };
        return low;
    };

    Node* head1_entry;
    Node* head2_entry;
    bool head1_has_circle = HasCircle(head1, head1_entry);
    bool head2_has_circle = HasCircle(head2, head2_entry);

    //两个均无环
    Node* head1_last;
    Node* head2_last;
    uint64_t head1_length = 1;
    uint64_t head2_length = 1;
    if(!head1_has_circle && !head2_has_circle)
    {
        head1_last = const_cast<Node*>(head1);
        head2_last = const_cast<Node*>(head2);

        
        while(head1_last->_next != nullptr)
        {
            head1_length++;
            head1_last  = head1_last->_next;
        };
        head1_length++;

        while(head2_last->_next != nullptr)
        {
            head2_last  = head1_last->_next;
        };
        head1_length++;

        if(head1_last == head2_last) //相交
        {
            Node* n1 = const_cast<Node*>(head1);
            Node* n2 = const_cast<Node*>(head2);
            if(head1_length > head2_length)
            {
                uint64_t forward_step = 0;
                while((forward_step++) < (head1_length - head2_length))
                {
                    n1 = n1->_next;
                }
            }
            else
            {
                uint64_t forward_step = 0;
                while((forward_step++) < (head2_length - head1_length))
                {
                    n2 = n2->_next;
                }
            };

            while(n1 != n2)
            {
                n1 = n1 -> _next;
                n2 = n2 -> _next;
            };

            intersect_node = n1;
            return true;
        }
        else
        {
            return false; //不相交
        }
    };

    if(head1_has_circle && head2_has_circle) //均有环
    {
        if(head1_entry == head2_entry) //入环节点相同可能相交于入环节点或者枝干
        {
            Node* h1_tmp = const_cast<Node*>(head1);
            Node* h2_tmp = const_cast<Node*>(head2);
            uint64_t h1_length_tmp = 0;
            uint64_t h2_length_tmp = 0;

            while(h1_tmp != head1_entry)
            {
                h1_length_tmp++;
                h1_tmp = h1_tmp->_next;
            };
            h1_length_tmp += 2;

            while(h2_tmp != head2_entry)
            {
                h2_length_tmp++;
                h2_tmp = h2_tmp->_next;
            };
            h2_length_tmp += 2;

            h1_tmp = const_cast<Node*>(head1);
            h2_tmp = const_cast<Node*>(head2);
            if(h1_length_tmp > h2_length_tmp)
            {
                while(h1_length_tmp > 0)
                {
                    h1_tmp = h1_tmp->_next;
                    h1_length_tmp--;
                }
            }
            else
            {
                 while(h2_length_tmp > 0)
                {
                    h2_tmp = h2_tmp->_next;
                    h2_length_tmp--;
                }
            }
            
            while(h1_tmp != h2_tmp)
            {
                h1_tmp = h1_tmp->_next;
                h2_tmp = h2_tmp->_next;
            };

            intersect_node = h1_tmp;
            return true;
        };

        bool intersect_circle = false; //判断是否相交到环上
        Node* inter_1 = head1_entry;
        while(inter_1->_next != head1_entry)
        {
            if(inter_1 == head2_entry)
            {
                intersect_circle = true;
                break;
            };
            inter_1 = inter_1->_next;
        };

        if(intersect_circle)  //相交到环上
        {
            intersect_node = head1_entry;
            return true;
        }

       return false;
    };
 
    return false; //一个有环一个无环，不可能相交
};


