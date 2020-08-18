//股票问题汇总
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

//框架
//dp[i][k][j]表示 今天是第i天，至今最多进行了k次交易, j(0或1)表示今天有没有持有股票
// 交易次数： 买入算一次，抛出一算，因为买入后再卖出算一次交易
// base case：
// dp[-1][k][0] = dp[i][0][0] = 0
// dp[-1][k][1] = dp[i][0][1] = -infinity  负无穷表示不可能，，
// 一般不这么处理(i == -1)，解释性不是很好，直接初始化i=0，k >1表示之前不管怎么操作到0天这一天的积累，前面操作无效

// 状态转移方程：
// dp[i][k][0] = max(dp[i-1][k][0], //昨天手里没股票，今天休息
//              dp[i-1][k][1] + prices[i]) //昨天手里有股票，今天抛出
// dp[i][k][1] = max(dp[i-1][k][1], //昨天手里有，今天休息
//                  dp[i-1][k-1][0] - prices[i]) //昨天手里没有，今天买入
//

//买卖股票的最佳时机I--k==1
// 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
// 如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。
// 注意：你不能在买入股票前卖出股票。

//改写框架，k都是1，不会改变，去除影响
int maxProfit_k_1(vector<int>& prices)
{
    if(prices.size() < 2)
    {
        return 0;
    }
    int day_count = prices.size();
    //base case 
    // 初始化i0
    int dp_i_0 = 0;
    int dp_i_1 = -prices[0];
    for(int i = 1; i< prices.size(); i++)
    {
        dp_i_0 = max(dp_i_0,  //昨天没有股票今天休息
                    dp_i_1 + prices[i]); //昨天有股票，今天抛了
        dp_i_1 = max(dp_i_1, //昨天有股票，今天休息
                     0 - prices[i]); //昨天没有，今天买了说明之前没买，利润负值
    };
    return dp_i_0;
}

vector<int> a;
int b = *(min_element(a.begin(), a.end()));
// 买卖股票的最佳时机II--k==正无穷
// 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

//改写框架， k=无穷，可以认为k==k - 1, 不需要记录k
int maxProfit_k_inf(vector<int>& prices)
{
     if(prices.size() < 2)
    {
        return 0;
    }
    int day_count = prices.size();
    //base case 
    // 初始化i0
    int dp_i_0 = 0;
    int dp_i_1 = -prices[0];
    for(int i = 0; i < day_count; i++)
    {
        dp_i_1 = max(dp_i_1,  //昨天手里有，今天休息
                     dp_i_0 - prices[i]); //昨天手里没有，今天买入了
        dp_i_0 = max(dp_i_0, //昨天手里也没有，今天休息
                    dp_i_1 + prices[i]); //昨天手里有，今天抛了
        
    };
    return dp_i_0;
}

//最佳买卖股票实际含冷冻期III
// 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​
// 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
// 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。

//框架改写
// dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
// dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i])
// 解释：第 i 天选择 buy 的时候，要从 i-2 的状态转移，而不是 i-1 。
int maxProfit_soild(vector<int>& prices) 
{
    //直接初始化0天和1天，因为要从i-2进行转移
    if(prices.size() < 2)
    {
        return  0;
    }

    int dp_00 = 0;
    int dp_01 = -prices[0];
    int dp_10 = max(dp_00, dp_01 + prices[1]); //直接休息，因为不能卖
    int dp_11 = max(dp_01, //休息
                dp_00 -prices[1]); //买入

    if(prices.size() == 2)
    {
        return dp_10 < 0 ? 0 : dp_10;
    }

    int cur_v0 = 0;
    int cur_v1 = 0;
    for(int i = 2; i < prices.size(); i++)
    {
        cur_v0 = max(dp_10, dp_11 + prices[i]); //休息，卖出
        cur_v1 = max(dp_11, dp_00 - prices[i]); //休息，买入
        dp_00 = dp_10;
        dp_01 = dp_11;
        dp_10 = cur_v0;
        dp_11 = cur_v1;
    };
    return cur_v0;
};

//买卖股票的最佳时机含手续费
// 给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 
//代表了交易股票的手续费用。
// 你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，
//在卖出它之前你就不能再继续购买股票了。
// 返回获得利润的最大值。
// 注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

//框架改写： 每次交易扣除手续费
int maxProfit_fee(vector<int>& prices, int fee) 
{
    if(prices.size() < 2)
    {
        return 0;
    }
    //手续费在卖的时候付
    int day_count = prices.size();
    //初始化第0天
    int dp_i_0 = 0;
    int dp_i_1 = -prices[0];
    for(int i = 1; i < day_count; i++)
    {
        int tmp = dp_i_0;
        dp_i_0 = max(dp_i_0, //昨天手里也没有，今天休息
                    dp_i_1 + prices[i] - fee); //昨天手里有，今天抛了
        dp_i_1 = max(dp_i_1,  //昨天手里有，今天休息
                     tmp - prices[i]); //昨天手里没有，今天买入了
    };
    return dp_i_0;
};

//买卖股票的最佳时机III
// 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
// 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

//改写框架
//k=2,

int maxProfit_k_2(vector<int>& prices) 
{
    if(prices.size() < 2)
    {
        return 0;
    }
    int max_k = 2;
    //base case i=0时
    int dp_i10=0;
    int dp_i11 = -prices[0];
    int dp_i20 = 0;
    int dp_i21 = -prices[0];
    for(int i = 1; i < prices.size(); i++)
    {
        dp_i20 = max(dp_i20, //到昨天进行了2次，昨天没有股票，今天休息
                     dp_i21 + prices[i]); //昨天有，今天卖了
        dp_i21 = max(dp_i21, //昨天有，今天休息
                     dp_i10 - prices[i]); //昨天手里没有，今天买了
        dp_i10 = max(dp_i10, //昨天没有今天休息
                     dp_i11 + prices[i]); //今天卖了
        dp_i11 = max(dp_i11, //今天休息
                     -prices[i]); //如果是今天卖了，则昨天进行了0次买进，不对，则肯定是今天新买的
    };
    return dp_i20;
};

//买卖股票的最佳时机IV, k次交易
//如果k大于size() / 2 相当于是无穷
int maxProfit_k(int max_k, vector<int>& prices) 
{
    int n = prices.size();
    if (max_k > n / 2)
    {
        // maxProfit_k_inf(prices);
        int dp_i_0 = 0;
        int dp_i_1 = INT_MIN;
        for (int i = 0; i < n; i++) 
        {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - prices[i]);
        }
        return dp_i_0;
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(max_k + 1, vector<int>(2)));

    for (int i = 0; i < n; i++) 
        for (int k = max_k; k >= 1; k--) 
        {
            if (i - 1 == -1) 
            {
                dp[i][k][0] = 0;
                dp[i][k][1] = -prices[0];
                continue;  
            }
            dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
            dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);     
        }
    return dp[n - 1][max_k][0];
};

//maxProfit_k dp版本，存在效率问题
int max_v = 0;
void dp_maxProfit_k(const vector<int>prices, int total_k, int cur_day, int had_k_count, bool pre_is_own, int cur_v)
{
    if(cur_day >= prices.size())
    {
        max_v = max(max_v, cur_v);
        return;
    };
    //-----处理今天的并进入下一天的计算
    // 前一天手里没有
    if(!pre_is_own)
    {
        //今天休息, 明天的had_k_count不变, 对于明天来讲pre_is_own也没有，cur_v不变
        dp_maxProfit_k(prices, total_k, cur_day + 1, had_k_count, false, cur_v);
        //今天买入
        if(had_k_count < total_k)
        {
            dp_maxProfit_k(prices, total_k, cur_day + 1, had_k_count + 1, true, cur_v - prices[cur_day]);
        }
    }
    else // 前一天手里有
    {
        // 今天休息
        dp_maxProfit_k(prices, total_k, cur_day + 1, had_k_count, true, cur_v);
        //今天抛出
        dp_maxProfit_k(prices, total_k, cur_day + 1, had_k_count, false, cur_v + prices[cur_day]);
    }
}


int main()
{
    vector<int> v{1,2,4,2,5,7,2,4,9,0};
    auto ret = maxProfit_k(4, v);
    return 0;
}