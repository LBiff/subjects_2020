//先看下题目：给你 k 种面值的硬币，面值分别为 c1, c2 ... ck，每种硬币的数量无限，
// 再给一个总金额 amount，问你最少需要几枚硬币凑出这个金额，如果不可能凑出，算法返回 -1 。

#include <vector>
#include <limits>
#include <algorithm>
using namespace std;


//动态规划
//dp[i]表示凑出金额i的最少的金币数
//和跳楼梯很相似
int coinChange(vector<int>& coins, int amount) 
{
    if(amount == 0)
    {
        return 0;
    }
    vector<int> dp(amount + 1, -1); //-1表示无效
    //初始化
    for(auto c : coins)
    {
        if(c <= amount && c > 0)
        {
            dp[c] = 1;
        }
    };

    for(int i = 1; i < amount + 1; i++)
    {
        //没有计算过
        if(dp[i] == -1)
        {
            int min_v = -1;
            for(auto c : coins)
            {
                if(i - c >= 0)
                {
                    if(min_v != -1 && dp[i - c] != -1)
                    {
                        min_v =  min(min_v, dp[i - c] + 1) ;
                    }
                    else if(min_v == -1 && dp[i - c] != -1)
                    {
                        min_v = dp[i - c] + 1;
                    }
                }
            };
            dp[i] = min_v;
        }
    };

    return dp[amount];
};

int main()
{
    vector<int>coins{1};
    int amount = 1;
    auto ret = coinChange(coins, amount);
    return 0;
}