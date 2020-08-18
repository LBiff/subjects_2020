// 312. 戳气球
// 有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
// 现在要求你戳破所有的气球。如果你戳破气球 i ，就可以获得 nums[left] * nums[i] * nums[right] 个硬币。 
// 这里的 left 和 right 代表和 i 相邻的两个气球的序号。注意当你戳破了气球 i 后，气球 left 和气球 right 就变成了相邻的气球。
// 求所能获得硬币的最大数量。
// 说明:
// 你可以假设 nums[-1] = nums[n] = 1，但注意它们不是真实存在的所以并不能被戳破。
// 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

#include <vector>
#include <algorithm>
using namespace std;

//可以用回溯做，但是复杂度太高
// dp表
int maxCoins(vector<int>& nums) 
{
    // 左右加1
    vector<int> points;
    points.push_back(1);
    points.insert(points.end(), nums.begin(), nums.end());
    points.push_back(1);

    int sz = points.size();
    //dp[i][j]表示将(i,j)区间内所有气球戳完所得到的最大值
    vector<vector<int>> dp(sz, vector<int>(sz));
    //basecase dp[i][i+1] = 0;因为没有气球可以戳,已经初始化
    //转移--肯定存在最后一个被戳破的，设为k, k戳破的获得肯定是k_v = points[i] * points[j] * points[k]
    // dp[i][j] = dp[i][k] + k_v + dp[k][j]

    // 因为依赖关系，选择从下往上从左往右算
    //最终要求的是dp[0][sz - 1]
    for(int i = nums.size(); i >= 0; i--)
    {
        for(int j = i + 1; j < sz; j++)
        {
            for(int k = i + 1; k < j; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + points[i] * points[j] * points[k]);
            }
        }
    };

    return dp[0][sz - 1];
};
