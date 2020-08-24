#include <iostream>
using namespace std;

class Base
{
public:
    Base(){cout << "构造 B" << endl;}
    ~Base(){cout << "系统 B" << endl;}
};

class D : public Base
{
public:
    D(){cout << "构造 D" << endl;}
    ~D(){cout << "系统 D" << endl;}
};

int main()
{
    Base* d = new(D)；
    delete d;
}