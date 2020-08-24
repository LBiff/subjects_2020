#include <string>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

int calSum(int v)
{
    if(v < 10)
    {
        return v;
    }
    int i = 1;
    int bits = 0;
    while(i <= v)
    {
        bits++;
        i *= 10;
    };

    int sum = 0;
    while( bits > 0 && v > 0)
    {
        int k  = pow(10, bits - 1);
        sum += (v / k);
        v = v % k;
        bits--;
    };

    return sum;
};

int GetSum(int n)
{
    int half = n / 2;
    return calSum(half) + calSum(n - half);
};


int main()
{
    string tmp;
    getline(cin, tmp);
    int test_count = atoi(tmp.c_str());
    while(test_count-- > 0)
    {
        getline(cin, tmp);
        int n = atoi(tmp.c_str());
        cout << GetSum(n) << endl;
    };
    return 0;
};


// 数字之和： 拆分成两个a和b， 求各位相加最大的值
// 刷板子，最少次数
// 第k小字符串
// 最少回文