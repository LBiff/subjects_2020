// 逐步求和得到正数的最小值
// 给你一个整数数组 nums 。你可以选定任意的 正数 startValue 作为初始值。
// 你需要从左到右遍历 nums 数组，并将 startValue 依次累加上 nums 数组中的值。
// 请你在确保累加和始终大于等于 1 的前提下，选出一个最小的 正数 作为 startValue 

#include <vector>
#include <cstdlib>
using namespace std;

//min_set求出累计最小，用1-
int minStartValue(vector<int>& nums) 
{
    if(nums.empty())
    {
        return 0;
    }
    int min_sum = nums[0];
    int sum = 0;
    for(auto i : nums)
    {
        sum += i;
        min_sum = min(min_sum, sum);
    };
    if(min_sum < 1)
    {
        return 1 - min_sum;
    }
    else
    {
        return 0;
    }
}