// 给你一个整数数组 nums 和一个正整数 threshold  ，你需要选择一个正整数作为除数，然后将数组里每个数都除以它，并对除法结果求和。
// 请你找出能够使上述结果小于等于阈值 threshold 的除数中 最小 的那个。
// 每个数除以除数后都向上取整，比方说 7/3 = 3 ， 10/2 = 5 。
// 题目保证一定有解。

// 1 <= nums.length <= 5 * 10^4
// 1 <= nums[i] <= 10^6
// nums.length <= threshold <= 10^6

#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//二分查找
//上界1， 下界max(nums)
int smallestDivisor(vector<int>& nums, int threshold) 
{
    int l_idx = 1;
    int r_idx = *max_element(nums.begin(), nums.end());
    int min_d = INT_MAX;
    while(l_idx <= r_idx)
    {
        int mid = l_idx + (r_idx - l_idx) / 2;
        int cur_v = 0;
        for(auto n : nums)
        {
            cur_v += ceil((double)(n) / mid);
        }
        if(cur_v <= threshold)
        {
            min_d = min(min_d, mid);
            r_idx = mid - 1;
        }
        else
        {
            l_idx = mid + 1;
        }
    };

    return min_d;
}