#include <iostream>
using namespace std;

void func1()
{
    cout << "call func1";
};
void func2()
{
    cout << "call func2";
};

int main() 
{
    atexit(func1);
    atexit(func2);
    cout << "hello" << endl;
    return 0;
}