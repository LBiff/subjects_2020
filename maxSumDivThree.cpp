// 给你一个整数数组 nums，请你找出并返回能被三整除的元素最大和。
// 输入：nums = [3,6,5,1,8]
// 输出：18
// 解释：选出数字 3, 6, 1 和 8，它们的和是 18（可被 3 整除的最大和）。

#include <vector>
using namespace std;

// dp
int maxSumDivThree(vector<int>& nums) {
    if(nums.empty())
    {
        return 0;
    }
    vector<int> dp{0,0,0}; //表示[0,cur]的数字mod 3 == 0, 1, 2的最大和
    dp[nums[0] % 3] = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] < 0)
        {
            continue;
        }
        int mod = nums[i] % 3;

        // 前期备份，防止采用修改后的值*********
        int d0 = dp[0];
        int d1 = dp[1];
        int d2 = dp[2];
        if(mod == 0)
        {
            
            dp[0] += nums[i];
            if(d1 > 0)  //有效性判断******,因为0并不是有效值
            {
                dp[1] += nums[i];
                
            }
            if(d2 > 0)
            {
                dp[2] += nums[i];
            }
        }
        else if(mod == 1)
        {
            if(d2 > 0)
            {
                dp[0] = max(dp[0], d2 + nums[i]);
            }
            dp[1] = max(dp[1], d0 + nums[i]);
            if(d1 > 0)
            {
                dp[2] = max(dp[2], d1 + nums[i]);
            }
        }
        else if(mod == 2)
        {
            if(d1 > 0)
            {
                dp[0] = max(dp[0], d1 + nums[i]);
            }
            if(d2 > 0)
            {
                dp[1] = max(dp[1], d2 + nums[i]);
            }
            dp[2] = max(dp[2], d0 + nums[i]);
        }
    };
    return dp[0];
};




int main()
{
    vector<int> v{1,2,3,4,4};
    auto ret = maxSumDivThree(v);
    return 0;
}