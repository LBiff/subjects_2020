//在排序数组中查找元素的第一个和最后一个位置
//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//你的算法时间复杂度必须是 O(log n) 级别。
//如果数组中不存在目标值，返回 [-1, -1]。
#include <vector>
#include <cstdlib>
using namespace std;


//左边界的问题:正常二分查找，找到更新，向左压缩区间
int GetLeftBound(vector<int> v, int target)
{
    if(v.empty())
    {
        return -1;
    }
    int min_l = INT_MAX;
    //[]区间
    int l = 0;
    int r = v.size() - 1;
    int mid = l + (r - l) / 2;
    while(l <= r)
    {
        mid =  l + (r - l) / 2;
        if(v[mid] == target)  //找到区间向左压缩继续找
        {
///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            r = mid - 1;    //重点！！！！！！！！！
///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            if(mid < min_l)
            {
                min_l = mid;
            }
        }
        else if(v[mid] > target)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    };

    return min_l == INT_MAX ? -1 : min_l;
};

//右边界的问题:正常二分查找，找到更新，向右压缩区间
int GetRightBound(vector<int> v, int target)
{
    if(v.empty())
    {
        return -1;
    }
    int min_r = INT_MIN;
    //[]区间
    int l = 0;
    int r = v.size() - 1;
    int mid = l + (r - l) / 2;
    while(l <= r)
    {
        mid =  l + (r - l) / 2;
        if(v[mid] == target)  //找到区间向左压缩继续找
        {
///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            l = mid + 1;    //重点！！！！！！！！！
///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            if(mid > min_r)
            {
                min_r = mid;
            }
        }
        else if(v[mid] > target)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    };

    return min_r == INT_MIN ? -1 : min_r;
};


vector<int> searchRange(vector<int>& nums, int target) 
{
    if(nums.empty())
    {
        return {-1,-1};
    };
    int l_bound = GetLeftBound(nums,target);
    int r_bound = GetRightBound(nums, target);
    return {l_bound, r_bound};
};

   
    // auto BinarySearch = [&](vector<int>& nums, int target, int l, int r) -> int
    // {
    //     int mid = (l + r) / 2;
    //     while(0 <= l && l <= mid && mid <= r &&  r < nums.size())
    //     {
    //         if(nums[mid] == target)
    //         {
    //             return mid;
    //         };
    //         if(l == r)
    //         {
    //             break;
    //         };
    //         if(nums[mid] > target)
    //         {
    //             r = mid - 1;
    //         }
    //         else
    //         {
    //             l = mid + 1;
    //         }
    //     };
    //     return -1;
    // };

    // while(0 <= l && l <= mid && mid <= r &&  r < nums.size())
    // {
    //     //查找到不终止
    //     bool is_set = false;
    //     if(nums[mid] == target)
    //     {
    //         is_set = true;
    //         if(mid > idx_max)
    //         {
    //             idx_max = mid;
    //         }
    //         if (mid < idx_min)
    //         {
    //             idx_min = mid;
    //         };
    //     };
    //     //考察左边
    //     if(is_set && mid - 1 >= 0 && nums[mid - 1] == target)
    //     {
    //         int l_ret = BinarySearch(nums,target,l,mid - 1);
    //         if(l_ret != -1)
    //         {
    //             if(l_ret > idx_max)
    //             {
    //                 idx_max = l_ret;
    //             };
    //             if (l_ret < idx_min)
    //             {
    //                 idx_min = l_ret;
    //             };
    //         }
    //     };
    //     //考察右边
    //     if(is_set && mid + 1 < nums.size() && nums[mid + 1] == target)
    //     {
    //         int r_ret = BinarySearch(nums,target,mid + 1,r);
    //         if(r_ret != -1)
    //         {
    //             if(r_ret > idx_max)
    //             {
    //                 idx_max = r_ret;
    //             };
    //             if (r_ret < idx_min)
    //             {
    //                 idx_min = r_ret;
    //             };
    //         }
    //     };
    //     //左右均没有则结束
    //     if(!is_set)
    //     {
    //         break;
    //     }
    // };

    // return (idx_min == INT_MAX && idx_max == INT_MIN) ? {-1,-1} : {idx_min, idx_max};



