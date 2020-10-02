//质因数分解
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//找出n以内的质数
vector<int> PrimeNumber(const int n)
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

void GetV(const vector<int>& zhishu, int cur_idx, int cur_n, vector<int>& cur_v)
{
    if(cur_idx >= zhishu.size())
    {
        return;
    };
    int cur_zhishu_idx = -1;
    for(int i = cur_idx; i < zhishu.size(); i++)
    {
        if(cur_n % zhishu[i] == 0)
        {
            cur_v.push_back(zhishu[i]);
            cur_zhishu_idx = i;
            break;
        }
    };
    if(cur_zhishu_idx != -1)
    {
        GetV(zhishu,cur_zhishu_idx, cur_n / zhishu[cur_zhishu_idx], cur_v);
    }
};

int main()
{
    int n;
    cin >> n;
    auto zhishu = PrimeNumber(n);
    if(zhishu.back() == n)
    {
        cout << n;
        return 0;
    }
    vector<int> cur_v;
    GetV(zhishu, 1,n,cur_v);
    cout << cur_v[0];
    for(int i = 1; i < cur_v.size(); i++)
    {
        cout << "*" << cur_v[i];
    }
    return 0;
}