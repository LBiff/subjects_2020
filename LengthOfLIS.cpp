//最长递增子序列（不连续），子串是连续的
// 给定一个无序的整数数组，找到其中最长上升子序列的长度。
// 示例:
// 输入: [10,9,2,5,3,7,101,18]
// 输出: 4 
// 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
// 说明:
// 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
// 你算法的时间复杂度应该为 O(n2) 。
// 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?

#include <vector>
#include <stack>
using namespace std;

//动态规划O(n^2)
//dp[i]表示以nums[i]结尾的最长子序列的长度
int lengthOfLIS_dp(vector<int>& nums) 
{
    if(nums.empty())
    {
        return 0;
    }
    vector<int> dp(nums.size(), 1); //至少包含自己
    int max_v = 1;
    for(int i = 1; i < nums.size(); i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(nums[i] > nums[j])
            {
                dp[i] = dp[j] + 1 > dp[i] ? dp[j] + 1 : dp[i];
            }
        };
        max_v = max(max_v, dp[i]);
    };
    return max_v;
}


//二分O(nlgn)
// 首先，给你一排扑克牌，我们像遍历数组那样从左到右一张一张处理这些扑克牌，最终要把这些牌分成若干堆。
// 处理这些扑克牌要遵循以下规则：
// 只能把点数小的牌压到点数比它大的牌上。如果当前牌点数较大没有可以放置的堆，则新建一个堆，把这张牌放进去。
// 如果当前牌有多个堆可供选择，则选择最左边的堆放置。
// 比如说上述的扑克牌最终会被分成这样 5 堆（我们认为 A 的值是最大的，而不是 1）。
// 为什么遇到多个可选择堆的时候要放到最左边的堆上呢？因为这样可以保证牌堆顶的牌有序（2, 4, 7, 8, Q），证明略。
// 按照上述规则执行，可以算出最长递增子序列，牌的堆数就是最长递增子序列的长度，证明略。
// 我们只要把处理扑克牌的过程编程写出来即可。每次处理一张扑克牌不是要找一个合适的牌堆顶来放吗，
// 牌堆顶的牌不是有序吗，这就能用到二分查找了：用二分查找来搜索当前牌应放置的位置。

int lengthOfLIS_patience_sort(vector<int>& nums) 
{
    if(nums.empty())
    {
        return 0;
    };
    vector<int> v; //只记录牌顶最小值
    for(auto n : nums)
    {
        bool is_put = false;
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i] >= n)
            {
                v[i] = n;
                is_put = true;
                break;
            }
        };
        if(!is_put)
        {
            v.push_back(n);
        }
    };
    return v.size();
};




int main()
{
    vector<int> v{1,3,6,7,9,4,10,5,6};
    auto ret = lengthOfLIS_dp(v);
    return 0;
}


