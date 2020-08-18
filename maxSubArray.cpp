// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
// 示例:
// 输入: [-2,1,-3,4,-1,2,1,-5,4]
// 输出: 6
// 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) 
{
    int max_v = 0;

    // dp[i]表示以nums[i]结尾的具有最大和的连续子数组的和
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    max_v = dp[0];
    for(int i = 1; i < nums.size(); i++)
    {
        // 要么与前面相连，要么自己组成一个
        dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        max_v = max(max_v, dp[i]);
    };

    return max_v;
}
