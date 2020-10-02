
#include <iostream>
using namespace std;
class A
{
public:
    A(){cout << "A()" << endl;};
    A(float _a, float _b) : a(_a), b(_b) {cout << "A(float _a, float _b)" << endl;}
private:
    float a;
    float b;

};

int main()
{
    A a();
    cout << "---------" << endl;
    A b(1,2);
    return 0;
};


