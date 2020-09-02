// 剑指 Offer 42. 连续子数组的最大和
// 输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
// 要求时间复杂度为O(n)。

// 要求输出子数组

#include <vector>
#include <cstdlib>
using namespace std;

// 关键点：区分输出最大和，dp[i]另外存一下以[i]结束为最大和子数组的最前索引
vector<int> maxSubArrayPath(vector<int>& nums) 
{
    if(nums.empty())
    {
        return {};
    }
    vector<pair<int, int>> dp(nums.size(), {0, 0}); //sum, 子数组的前面的索引
    dp[0] = {nums[0], 0};
    for(int i = 1; i < nums.size(); i++)
    {
        if(dp[i - 1].first + nums[i] > nums[i])
        {
            dp[i] = {dp[i - 1].first + nums[i], dp[i-1].second};
        }
        else
        {
            dp[i] = {nums[i], i};
        }
    };

    pair<int,int> ret;
    int max_v = INT_MIN;
    for(int i = 0; i < dp.size(); i++)
    {
        if(dp[i].first > max_v)
        {
            max_v = dp[i].first;
            ret = {dp[i].second, i};
        };
    };

    vector<int> ret_v;
    ret_v.insert(ret_v.end(), nums.begin() + ret.first, nums.begin() + ret.second + 1);
    return ret_v;
};

int main()
{
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    auto ret = maxSubArrayPath(nums);
    return 0;
}

 