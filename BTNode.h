#ifndef BTNODE
#define BTNODE

struct Node
{
    int _v;
    Node* _l;
    Node* _r;
    Node(int v) :_v(v), _l(nullptr), _r(nullptr){};
};

#endif // !BTNODE