// 287. 寻找重复数
// 给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），
// 可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) 
{
    if(nums.size() < 2)
    {
        return -1;
    };

    //闭区间查找，这里的二分不是索引的二分， 是值的二分
    int left = 1;
    int right = nums.size() - 1;
    while(left < right)
    {
        int mid = left + ((right - left) >> 1);
        // 大于等于left 并且小于mid的数， 不重复的话最多有 mid - left和，重复的话肯定大于mid-left
        int mid_count = 0;
        for(auto n : nums)
        {
            // [1, mid] 正常来讲数目不超过mid，超过则重复
           if(n <= mid)
           {
               mid_count++;
           }
        };
        if(mid_count > mid)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    };
    return left;
}