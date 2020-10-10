// 给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


//递归, 放在哪个的问题 --超时
bool dp(const vector<int>& nums, int cur_idx, vector<int> cur_bags, int single_bag)
{
    bool is_active = true;
    for(auto b : cur_bags)
    {
        if(b != single_bag)
        {
            is_active = false;
            break;
        }
    };
    if(is_active)
    {
        return true;
    };

    if(cur_idx >= nums.size())
    {
        return false;
    };
    
    for(int i = 0; i < cur_bags.size(); i++)
    {
        auto bags_tmp = cur_bags;
        if(bags_tmp[i] + nums[cur_idx] <= single_bag)
        {
            bags_tmp[i] += nums[cur_idx];
            if(dp(nums, cur_idx + 1, bags_tmp, single_bag))
            {
                return true;
            }
        }
    };
    return false;
};

bool canPartitionKSubsets(vector<int>& nums, int k) 
{
    if(k < 1 || nums.size() < k)
    {
        return false;
    };

    if(k == 1)
    {
        return true;
    };

    int sum = accumulate(nums.begin(), nums.end(), 0);

    int single_bag = sum / k;
    vector<int> cur_bags(k,0);
    return dp(nums,0, cur_bags, single_bag);
};