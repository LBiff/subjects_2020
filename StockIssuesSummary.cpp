//股票问题汇总
#include <vector>
#include <cstdlib>
using namespace std;

//框架
//dp[i][k][j]表示 今天是第i天，至今最多进行了k次交易, j(0或1)表示今天有没有持有股票
// base case：
// dp[-1][k][0] = dp[i][0][0] = 0
// dp[-1][k][1] = dp[i][0][1] = -infinity  负无穷表示不可能

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
    int day_count = prices.size();
    //base case 
    //dp[-1][0]=0 因为还没有开始，利润为0
    int dp_i_0 = 0;
    //dp[-1][1] = INT_MIN  还没有开始，手里不可能有股票，INT_MIN表示不可能
    int dp_i_1 = INT_MIN;
    for(int i = 0; i< prices.size(); i++)
    {
        dp_i_0 = max(dp_i_0,  //昨天没有股票今天休息
                    dp_i_1 + prices[i]); //昨天有股票，今天抛了
        dp_i_1 = max(dp_i_1, //昨天有股票，今天休息
                     0 - prices[i]); //昨天没有，今天买了说明之前没买，利润负值
    };
    return dp_i_0;
}

// 买卖股票的最佳时机II--k==正无穷
// 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

//改写框架， k=无穷，可以认为k==k - 1, 不需要记录k
int maxProfit_k_inf(vector<int>& prices)
{
    int day_count = prices.size();
    int dp_i_0 = 0;
    int dp_i_1 = INT_MIN;
    for(int i = 0; i < day_count; i++)
    {
        int tmp = dp_i_0;
        dp_i_0 = max(dp_i_0, //昨天手里也没有，今天休息
                    dp_i_1 + prices[i]); //昨天手里有，今天抛了
        dp_i_1 = max(dp_i_1,  //昨天手里有，今天休息
                     tmp - prices[i]); //昨天手里没有，今天买入了
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
    int day_count = prices.size();
    int dp_pre_0 = 0; //代表dp[i - 2][0]
    int dp_i_0 = 0;
    int dp_i_1 = INT_MIN;
    for(int i = 0; i < day_count; i++)
    {
        int tmp = dp_i_0;
        dp_i_0 = max(dp_i_0, //昨天手里也没有，今天休息
                    dp_i_1 + prices[i]); //昨天手里有，今天抛了
        dp_i_1 = max(dp_i_1,  //昨天手里有，今天休息
                     dp_pre_0 - prices[i]); //昨天手里没有，今天买入了
        dp_pre_0 = tmp;
    };
    return dp_i_0;
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
    int day_count = prices.size();
    int dp_i_0 = 0;
    int dp_i_1 = INT_MIN;
    for(int i = 0; i < day_count; i++)
    {
        int tmp = dp_i_0;
        dp_i_0 = max(dp_i_0, //昨天手里也没有，今天休息
                    dp_i_1 + prices[i]); //昨天手里有，今天抛了
        dp_i_1 = max(dp_i_1,  //昨天手里有，今天休息
                     tmp - prices[i] - fee); //昨天手里没有，今天买入了
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
    int max_k = 2;
    //base case i=-1时
    int dp_i10=0;
    int dp_i11 = INT_MIN;
    int dp_i20 = 0;
    int dp_i21 = INT_MIN;
    for(auto p : prices)
    {
        dp_i20 = max(dp_i20, //到昨天进行了2次，昨天没有股票，今天休息
                     dp_i21 + p); //昨天有，今天卖了
        dp_i21 = max(dp_i21, //昨天有，今天休息
                     dp_i10 - p); //昨天手里没有，今天买了
        dp_i10 = max(dp_i10, //昨天没有今天休息
                     dp_i11 + p); //今天卖了
        dp_i11 = max(dp_i11, //今天休息
                     -p); //如果是今天卖了，则昨天进行了0次买进，不对，则肯定是今天新买的
    };
    return dp_i20;
};

//买卖股票的最佳时机IV, k次交易
//如果k大于size() / 2 相当于是无穷
//Error: 测例过不完
int maxProfit_k(int max_k, vector<int>& prices) 
{
    
    if(max_k > prices.size() / 2)
    {
        //return maxProfit_k_inf(prices);
        int day_count = prices.size();
        int dp_i_0 = 0;
        int dp_i_1 = INT_MIN;
        for(int i = 0; i < day_count; i++)
        {
            int tmp = dp_i_0;
            dp_i_0 = max(dp_i_0, //昨天手里也没有，今天休息
                        dp_i_1 + prices[i]); //昨天手里有，今天抛了
            dp_i_1 = max(dp_i_1,  //昨天手里有，今天休息
                        tmp - prices[i]); //昨天手里没有，今天买入了
        };
        return dp_i_0;
    };
    //dp[i][k][j]表示 今天是第i天，至今最多进行了k次交易, j(0或1)表示今天有没有持有股票
    vector<vector<vector<pair<int, bool>>>> dp(prices.size(), vector<vector<pair<int, bool>>>(max_k + 1, vector<pair<int, bool>>(2,{0,false})));
    //边界case
    // dp[-1][k][0] = dp[i][0][0] = 0
    // dp[-1][k][1] = dp[i][0][1] = -infinity  负无穷表示不可能
    dp[0][0][0].first = 0;
    dp[0][0][0].second = true;

    dp[0][0][1].second = false;

    dp[0][1][0].first = 0;
    dp[0][1][0].second = true;

    dp[0][1][1].first = - prices[0]; //买进
    dp[0][1][1].second = true;

    for(int i = 1; i < prices.size(); i++)
    {
        dp[i][0][0].first = 0;
        dp[i][0][0].second = true;

        dp[i][0][1].second = false;
        for(int k = max_k; k >= 1; k--)
        {
            dp[i][k][0].second = dp[i -1][k][0].second || dp[i - 1][k][1].second;
            dp[i][k][0].first = max(dp[i -1][k][0].second ? dp[i -1][k][0].first : INT_MIN, //今天休息
                                dp[i - 1][k][1].second ?  dp[i - 1][k][1].first + prices[i] : INT_MIN); //卖出
            dp[i][k][1].second = dp[i -1][k][1].second || dp[i - 1][k - 1][0].second;
            dp[i][k][1].first = max(dp[i -1][k][1].second ? dp[i -1][k][1].first : INT_MIN, //今天休息
                                    dp[i - 1][k - 1][0].second  ?  dp[i - 1][k - 1][0].first - prices[i] : INT_MIN); //买进
        }
    };

    return dp[prices.size() - 1][max_k][0].first;
};

int main()
{
    vector<int> v{1,2,4,2,5,7,2,4,9,0};
    auto ret = maxProfit_k(4, v);
    return 0;
}