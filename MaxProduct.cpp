//数组中乘积最大的连续子数组
//dp[i]记录最小最大
//dp[i+1]_max = max(v[i+1] * dp[i]_max, v[i+1]*dp[i]_min, v[i+1]);
//dp[i+1]_min = max(v[i+1] * dp[i]_max, v[i+1]*dp[i]_min, v[i+1]);
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int maxProduct(vector<int>& nums) 
{
    if(nums.size() < 2)
    {
        return nums.empty() ? 0 : nums[0];
    }
    int max_pre = nums[0];
    int min_pre = nums[0];
    int max_v = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {
        int max_tmp = max_pre;  //重要
        max_pre = max(nums[i] * max_pre, max(nums[i] * min_pre, nums[i]));
        min_pre = min(nums[i] * max_tmp, min(nums[i] * min_pre, nums[i]));
        max_v = max(max_v, max_pre);
    };
    return max_v;
};

int main()
{
    vector<int> v{-4,-3,-2};
    maxProduct(v);
}


