// //删除与获得的点数
// nums的长度最大为20000。
// 每个整数nums[i]的大小都在[1, 10000]范围内。
// 给定一个整数数组 nums ，你可以对它进行一些操作。
// 每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除每个等于 nums[i] - 1 或 nums[i] + 1 的元素。
// 开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。

#include <vector>
#include <cstdlib>
using namespace std;

//dp[i]表示nums的最大值
//对于求出dp[i - 1]的时候，考虑dp[i]：
// dp[i]是被动删除的：
//      只能由dp[i - 1]被动删除，则不累加点数，有无dp[i]和dp[i - 1]是一样的
// dp[i]如果是主动删除的，累加点数
//       dp[i - 1]被dp[i]主动删除，则dp[i - 2]是被动删除的
//       dp[i - 1]被dp[i - 2]主动删除, 说明dp[i - 1]是被动删除的，在只有dp[i - 1]的情况dp[i - 1] 
//

//Thinking
int deleteAndEarn(vector<int>& nums) 
{
    if(nums.empty())
    {
        return 0;
    }
    vector<int> counter(10001,0); //因为nums[i]在[1,10000]之间
    //统计
    int max_v = INT_MIN;
    for(auto i : nums)
    {
        if(i > max_v) max_v = i;
        counter[i]++;
    };
    //nums的最大值为dp[i]
    vector<int> dp(10001,0);
    dp[1] = counter[1]; //在只要几个1的时候，只能各个删除
    for(int i = 2; i <= max_v; i++)
    {
        //dp[i -1]是主动删除的则会把dp[i]一块删了不累加点数
        //如果dp[i - 1]是被dp[i -2]删除，则只能主动删除dp[i],dp[i]的删除不会删除其他节点
        dp[i] = max(dp[i -1], dp[i - 2] + i * counter[i]);
    };

    return dp[max_v];
};
