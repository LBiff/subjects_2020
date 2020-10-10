// 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
// ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
// 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
// 你可以假设数组中不存在重复的元素。
// 你的算法时间复杂度必须是 O(log n) 级别。

#include <vector>
using namespace std;


// 技巧: 首先判断target的左右，后面动态计算mid的左右进行分类计算
int search(vector<int>& nums, int target) 
{
    int l_idx = 0;
    int r_idx = nums.size() - 1;
    bool target_left = target >= nums[0];
    bool mid_left;  //mid指针在左半边
    while(l_idx <= r_idx)
    {
        int mid = l_idx + (r_idx - l_idx) / 2;
        mid_left = nums[mid] >= nums[0];
        if(nums[mid] == target)
        {
            return mid;
        };
        if(target_left)
        {
           if(mid_left)
           {
               if(nums[mid] < target)
               {
                   l_idx = mid + 1;
               }
               else
               {
                   r_idx = mid - 1;
               }
           }
           else
           {
               r_idx = mid - 1;
           }
        }
        else
        {
            if(!mid_left)
            {
                if(nums[mid] < target)
               {
                   l_idx = mid + 1;
               }
               else
               {
                   r_idx = mid - 1;
               } 
            }
            else
            {
                l_idx = mid + 1;
            }
        }
    };
    return -1;
}