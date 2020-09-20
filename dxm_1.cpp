#include <iostream>
using namespace std;

int main()
{
    int n;
    int m;
    cin >> n >> m;
    int tmp = m;
    long long ret = 0;
    for(int i = 0; i < 3 * n; i++)
    {
        ret += tmp;
        tmp += m;
    };
    cout << ret << endl;
    return 0;
}