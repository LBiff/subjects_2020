// 给你一个整数数组 arr 和一个整数 d 。每一步你可以从下标 i 跳到：
// i + x ，其中 i + x < arr.length 且 0 < x <= d 。
// i - x ，其中 i - x >= 0 且 0 < x <= d 。
// 除此以外，你从下标 i 跳到下标 j 需要满足：arr[i] > arr[j] 且 arr[i] > arr[k] ，
// 其中下标 k 是所有 i 到 j 之间的数字（更正式的，min(i, j) < k < max(i, j)）。
// 你可以选择数组的任意下标开始跳跃。请你返回你 最多 可以访问多少个下标。
// 请注意，任何时刻你都不能跳到数组的外面。

#include <vector>
#include <algorithm>
using namespace std;

//获取idx处的最大的
void GetIdxMaxJump(vector<int>& dp, vector<int>& arr, int idx, int d)
{
    if(idx < 0 || idx >= dp.size() || dp[idx] != -1)
    {
        return;
    };

    //左边检索
    dp[idx] = 1;
    for(int w= 1; w <= d && idx - w >= 0 && arr[idx - w] < arr[idx]; w++)
    {
        GetIdxMaxJump(dp, arr, idx - w, d);
        dp[idx] = max(dp[idx - w] + 1, dp[idx]);
    };

    //右边检索
    for(int w= 1; w <= d && idx + w < arr.size() && arr[idx + w] < arr[idx]; w++)
    {
        GetIdxMaxJump(dp, arr, idx + w, d);
        dp[idx] = max(dp[idx + w] + 1, dp[idx]);
    };
}
//设置dp[i]表示从下标i处开始起跳能够访问的最多下标
int maxJumps(vector<int>& arr, int d) 
{
    vector<int> dp(arr.size(), -1);
    int max_v = 0;
    for(int idx = 0; idx < arr.size(); idx++)
    {
        GetIdxMaxJump(dp, arr, idx, d);
        max_v = max(max_v, dp[idx]);
    };
    return max_v;
};

int main()
{
    vector<int> arr{7,6,5,4,3,2,1};
    int d = 1;
    auto ret = maxJumps(arr, d);
    return 0;
}