//n以内的质数计数
//依次删除质数的倍数
//注意3次加速
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


vector<int> PrimeNumber(int n)
{
    if(n < 2)
    {
        return vector<int>{1};
    };

    vector<bool> b_v(n, true);
    auto is_prime = [](const int n)
    {
        int sq = floor(sqrt(n));
        for(int i = 2; i <= sq; i++) //加速1
        {
            if(n % i == 0)
            {
                return false;
            }
        };
        return true;
    };
    //删除法
    int sq_n = floor(sqrt(n));
    for(int i = 2; i <= sq_n; i++) //加速2
    {
        if(is_prime(i))
        {
            for(int j = i * i; j <= n; j += i) //加速3
            {
                b_v[j - 1] = false;
            };
        }
    };
    vector<int> ret;
    for(int i =0; i< b_v.size(); i++)
    {
        if(b_v[i])
        {
            ret.push_back(i + 1);
        }
    };
    return ret;
};

int main()
{
    auto ret = PrimeNumber(10);
    return 0;
}