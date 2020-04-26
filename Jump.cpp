//数组跳跃
// 给定一个非负整数数组，你最初位于数组的第一个位置。
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。
// 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
// 示例:
// 输入: [2,3,1,1,4]
// 输出: 2
// 解释: 跳到最后一个位置的最小跳跃数是 2。
//      从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

#include <vector>
using namespace std;

int jump(vector<int>& nums) 
{
    if(nums.empty())
    {
        return 0;
    }
    int size = nums.size();
    vector<int> dp(size, size); //dp[i]表示从i位置到最后的的最少步数
    dp[size - 1] = 0; //最后是不用跳的
    for(int i = size - 2; i >= 0; i--)
    {
        for(int step = nums[i]; step > 0 ; step--)
        {
            if(i + step > size - 1)
            {
                continue;
            }
            dp[i] = min(dp[i], dp[i + step] + 1);
        }
    };

    return dp[0];
};