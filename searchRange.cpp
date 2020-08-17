// 34. 在排序数组中查找元素的第一个和最后一个位置
// 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
// 你的算法时间复杂度必须是 O(log n) 级别。
// 如果数组中不存在目标值，返回 [-1, -1]。

#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        FindTarget(nums,target,0, nums.size() - 1);
        if(l == INT_MAX || r == -1)
        {
            return {-1,-1};
        };
        return {l,r};
    };

    int l = INT_MAX;
    int r = -1;

    //递归更新
    void FindTarget(const vector<int>& nums, int target, int start_idx, int end_idx)
    {
        if(start_idx > end_idx || start_idx < 0 || end_idx >= nums.size())
        {
            return;
        };
        int l_idx = start_idx;
        int r_idx = end_idx;
        while(l_idx <= r_idx)
        {
            int mid = l_idx + (r_idx - l_idx) / 2;
            if(nums[mid] == target)
            {
                l = min(l, mid);
                r = max(r, mid);
                FindTarget(nums,target,start_idx, mid - 1);
                FindTarget(nums,target,mid + 1, end_idx);
                return;
            }
            else if(nums[mid] > target)
            {
                r_idx = mid - 1;
            }
            else
            {
                l_idx = mid + 1;
            }
        };
    }
};