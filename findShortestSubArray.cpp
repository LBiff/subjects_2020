// 给定一个非空且只包含非负数的整数数组 nums, 数组的度的定义是指数组里任一元素出现频数的最大值。
// 你的任务是找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。

#include <vector>
#include <unordered_map>
using namespace std;

int findShortestSubArray(vector<int>& nums) 
{
    unordered_map<int, pair<int, pair<int,int>>> mp; //{num,{count,{fir_idx, end_idx}})
    int max_count = 0; //最大的出现次数
    pair<int,int> max_count_idxs{-1,-1}; //最左和最右索引
    for(int i = 0; i < nums.size(); i++)
    {
        int n = nums[i];
        auto iter = mp.find(n);
        if(iter == mp.end())
        {
            mp.insert({n, {1, {i,i}}});
            if(1 > max_count)
            {
                max_count = 1;
                max_count_idxs = {i,i};
            }
        }
        else
        {
            iter->second.first++;
            iter->second.second.second = i;
            int len = iter->second.second.second - iter->second.second.first + 1;
            if(iter->second.first > max_count)
            {
                max_count = iter->second.first;
                max_count_idxs = iter->second.second;
            }
            else if(iter->second.first == max_count)
            {
                if(len < (max_count_idxs.second - max_count_idxs.first + 1))
                {
                    max_count_idxs = iter->second.second;
                }
            }
        }
    };

    return max_count_idxs.second - max_count_idxs.first + 1;
};

int main()
{
    vector<int> v{1, 2, 2, 3, 1};
    auto ret = findShortestSubArray(v);
    return 0;
}
