#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

typedef  long long _ll;

void TongYu(_ll a, _ll b, _ll& d, _ll& x, _ll& y)
{
    if(b == 0)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        TongYu(b, a % b, d, y, x);
        y -= x * (a / b);
    };
};

_ll Cal(_ll a, _ll b)
{
    _ll d;
    _ll x;
    _ll y;
    TongYu(a, b, d, x, y);

    _ll z = b / d;
    return (x % z + z) % z;
};



int main()
{
    _ll a;
    _ll b;
    cin >> a >> b;
    cout << Cal(a, b);
    return 0;
}