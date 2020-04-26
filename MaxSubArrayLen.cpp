//HUAWEI
// 给定一个数组 nums 和一个目标值 k，找到和等于 k 的最长子数组长度。
// 如果不存在任意一个符合要求的子数组，则返回 0。
// 注意:
//  nums 数组的总和是一定在 32 位有符号整数范围之内的。
#include <vector>
#include <unordered_map>
using namespace std;
//map不可添加(-1,0)，因为索引计算不一样
int maxSubArrayLen(vector<int>& nums, int k) 
{
    unordered_map<int, vector<int>> map; //sum, pre_sum_idx
    int sum = 0;
    for(int i = 0; i< nums.size(); i++)
    {
        sum += nums[i];
        auto iter = map.find(sum);
        if(iter != map.end())
        {
            iter->second.push_back(i);
        }
        else
        {
            vector<int> tmp(1,i);
            map.insert({sum, tmp});
        }
    };

    int max_len = 0;
    sum = 0;
    for(int i =0; i < nums.size(); i++)
    {
        sum += nums[i];
        if(sum == k)
        {
           max_len = max(max_len, i + 1); 
        };
        int remain = sum - k;
        auto iter = map.find(remain);
        if(iter != map.end())
        {
            for(int j = 0; j < iter->second.size(); j++)
            {
                if(iter->second[j] <= i)
                {
                    max_len = max(max_len, i - iter->second[j]);
                }
            }
        }
    };
    return max_len;
};

int main()
{
    vector<int> v{1,-1,5,-2,3};
    auto ret = maxSubArrayLen(v, 3);
    return 0;
}