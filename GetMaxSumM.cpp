// 在n个正整数中，任意挑选k个(不可重复挑选，0<=k<=n), 数字的和记为sum, 另有一个正整数m, 请问sum % m 的最大值是多少。

#include <iostream>
#include <vector>
using namespace std;


//全局更新
int max_ret = 0;

void GetMax(const vector<int> n_v, int cur_idx, int m, int cur_sum)
{
    string s = to_string(cur_idx) + "_" + to_string(cur_sum);

    if(cur_sum % m > max_ret)
    {
        max_ret = cur_sum % m;
    };

    if(cur_idx >= n_v.size())
    {
        return;
    };
    //递归
    GetMax(n_v, cur_idx + 1,m,cur_sum + n_v[cur_idx]);
    //递归
    GetMax(n_v, cur_idx + 1, m, cur_sum);
}

int GetMaxSumM(vector<int> n_v, int m)
{
    if(n_v.empty())
    {
        return 0;
    };
    if(n_v.size() == 1)
    {
        return n_v[0] % m;
    }
    GetMax(n_v, 0, m,0);
    return max_ret;
};

int main()
{
    vector<int> n_v{1, 2, 3, 4, 5};
    auto ret = GetMaxSumM(n_v, 5);
    return 0;
}