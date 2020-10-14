#include <iostream>
using namespace std;

int Add(int a, int b)
{
    return a + b;
};


int main()
{
    auto ret = Add(1,2);
    cout << ret <<endl;
    return 0;
}