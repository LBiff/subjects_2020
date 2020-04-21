//零钱兑换
// 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。
// 如果没有任何一种硬币组合能组成总金额，返回 -1。

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <functional>
using namespace std;

//直接贪婪求解
//Warning!!!!!
///该思路是错的!!!!,因为不能覆盖所所有的情况，本次是一道动态规划的问题
// int coinChange(vector<int>& coins, int amount) 
// {
//     //降序排列
//     sort(coins.begin(), coins.end(), greater<int>());

//     int ret = 0;
//     for(auto i : coins)
//     {
//         if(amount == 0)
//         {
//             return ret;
//         }
//         ret += amount / i;
//         amount %= i;
//     };
//     if(amount == 0)
//     {
//         return ret;
//     };

//     return -1;
// };

int coinChange(vector<int>& coins, int amount) 
{ 
    if(coins.empty() || amount < 0)
    {
        return -1;
    };
    if(amount == 0)
    {
        return 0;
    };
    //dp[n]--总金额是n的需要的硬币数，至少比前面+1, 从前面累加而来
    vector<int> dp(amount + 1, 0);
    for(int i = 1; i < dp.size(); i++)
    {
        bool is_change = false;
        int tmp = INT_MAX;
        for(auto c : coins)
        {
            if(i - c >= 0 && dp[i - c] != -1)
            {
                is_change = true;
                tmp = min(tmp, dp[i - c] + 1);
            }  
        };
        dp[i] = is_change ? tmp : -1;
    };
    return dp.back();
};

int main()
{
    vector<int> v{1,2,5};
    auto ret = coinChange(v,11);
    return 0;
}