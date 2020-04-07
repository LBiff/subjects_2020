//停在原地的方案数
// 有一个长度为 arrLen 的数组，开始有一个指针在索引 0 处。
// 每一步操作中，你可以将指针向左或向右移动 1 步，或者停在原地（指针不能被移动到数组范围外）。
// 给你两个整数 steps 和 arrLen ，请你计算并返回：在恰好执行 steps 次操作以后，指针仍然指向索引 0 处的方案数。
// 由于答案可能会很大，请返回方案数 模 10^9 + 7 后的结果。

#include <algorithm>
#include <vector>
using namespace std;

//动态规划
//从前一步右移，前一步不动，前一步左移
//f[i][j] = f[i - 1][j - 1] + f[i - 1][j] + f[i - 1][j + 1]
//f[0][0] = 1
const int mod = 1e9 + 7;
int numWays(int steps, int arrLen) 
{
    int arr_len = min(steps, arrLen);
    int step_len = steps + 1;
    //横arr,竖step, dp[i][j]表示通过i步数走到数组arr[j]位置的总方案数
    vector<vector<int>> dp(step_len, vector<int>(arr_len,0));
    dp[0][0] = 1;
    for(int step = 1; step < step_len; step++)
    {
        for(int arr_idx = 0; arr_idx < arr_len; arr_idx++)
        {
            if(arr_idx - 1 >= 0)
            {
                dp[step][arr_idx] = (dp[step][arr_idx] + dp[step - 1][arr_idx - 1]) % mod;
            }
            dp[step][arr_idx] = (dp[step][arr_idx] + dp[step - 1][arr_idx]) % mod;
            if(arr_idx < arr_len - 1)
            {
                dp[step][arr_idx] = (dp[step][arr_idx] + dp[step - 1][arr_idx + 1]) % mod;
            }
        }
    }
    return dp[steps][0];
};

int main()
{
    int s = 3;
    int a = 2;
    auto ret = numWays(s,a);
    return 0;
}