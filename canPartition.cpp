// 子集背包问题
// 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
// 注意:
// 每个数组中的元素不会超过 100
// 数组的大小不会超过 200

#include <vector>
#include <numeric>
using namespace std;

// 动态规划，分类的问题，时间复杂度太高
bool Partition(const vector<int>& nums, int bag_1, int bag_2, int cur_idx, int sum)
{
    if(bag_1 > sum / 2 || bag_2 > sum / 2)
    {
        return false;
    }
    if(nums.size() < 2)
    {
        return false;
    }
    if(cur_idx >= nums.size())
    {
        return bag_1 == bag_2;
    };

    return Partition(nums,bag_1 + nums[cur_idx], bag_2, cur_idx + 1, sum) || 
           Partition(nums,bag_1, bag_2 + nums[cur_idx], cur_idx + 1, sum);
};

bool canPartition(vector<int>& nums) 
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum % 2 != 0)
    {
        return false;
    }
    return Partition(nums,0,0,0, sum);
};

// dp表
// 本质上是背包问题
// dp[i][j] = bool, 表示用前i个物品能否正好装满重量为j的背包（可以挑着装)
// 此问题就是所有的物品是否能够恰好装满重量为 sum / 2的背包

bool Bag(vector<int> nums, int bag_weight)
{
    vector<vector<bool>> dp(nums.size() + 1, vector<bool>(bag_weight + 1, false));
    //basecase
    // dp[i][0] = true;
    // dp[0][j] = false;
    for(int i = 0; i < nums.size() + 1; i++)
    {
        dp[i][0] = true;
    };
    //转移
    // dp[i][j] = dp[i - 1][j] || dp[i-1][j - nums[i]]
    for(int i = 1; i < nums.size() + 1; i++)
    {
        for(int j = 1; j < bag_weight + 1; j++)
        {
            if(j - nums[i - 1] < 0)  //容量不足，不能放下第i个东西
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    };

    return dp[nums.size()][bag_weight];
};

bool canPartition_2(vector<int>& nums) {
    if(nums.size() < 2)
    {
        return false;
    };
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum % 2 != 0)
    {
        return false;
    }
    return Bag(nums, sum / 2);
};


int main()
{
    vector<int> v{1, 2, 3, 5};
    auto ret = canPartition(v);
    return 0;
}