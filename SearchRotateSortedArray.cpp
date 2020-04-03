//搜索旋转排序数组
//假设按照升序排序的数组在预先未知的某个点上进行了旋转。
//( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
//搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
//你可以假设数组中不存在重复的元素。
//你的算法时间复杂度必须是 O(log n) 级别。
//https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/yi-bian-er-fen-cha-zhao-c-by-biff/

#include <vector>
using namespace std;

int search(vector<int>& nums, int target) 
{
    //边界条件
    if(nums.empty())
    {
        return -1;
    }
    
    int l = 0;
    int r = nums.size() - 1;
    int mid = l + (r - l) / 2;
    while(l <= r)
    {
        mid = l + (r - l) / 2;
        if(nums[mid] == target)
        {
            return mid;
        };
        if(nums[mid] < nums[l])  //前半部分无序
        {
            //现在后半有序查找，后半有序查找不存在，前半查找
            //nums[mid] > target ? r = mid - 1 :  l = mid + 1;
            //先在后半部分查找
            if(nums[mid] <= target && target <= nums[r])  //肯定在后半部分
            {
                l = mid + 1;
            }
            else //有可能在前部分
            {
                r = mid - 1;
            }
            
        }
        else if(nums[mid] > nums[r]) // 后半部分无序
        {
            //现在前半有序查找，前半有序查找不存在, 后半查找
            //nums[mid] < target ?  l = mid + 1 : r = mid - 1;
            //先在前半部分查找
            if(nums[l] <= target && target <= nums[mid]) //肯定在前半部分
            {
                r = mid - 1;
            }
            else  //有可能在后半部分
            {
                l = mid + 1;
            }
        }
        else //整体有序
        {
            if(target < nums[mid]) //有可能在前半部分
            {
                r = mid - 1;
            }
            else  //有可能在后半部分
            {
                l = mid + 1;
            }
        };
    };
    return -1;
};

int search(vector<int>& nums, int target) 
{
    if(nums.empty()){return -1;};
    int l = 0;
    int r = nums.size() - 1;
    int mid = (l + r) / 2;
    while(l <= r && 0 <= mid  && mid < nums.size() && l >= 0 && r < nums.size())
    {
        mid = (l + r) / 2;
        if(nums[mid] == target){return mid;};
        if(l == r){
return -1;
        };
        nums[mid] < nums[l] ? (nums[mid] <= target && target <= nums[r] ?  l = mid + 1 : r = mid - 1) 
                            : (nums[mid] > nums[r] ? (nums[l] <= target && target <= nums[mid] ? r = mid - 1 : l = mid + 1)
                                : (target < nums[mid] ? r = mid - 1 : l = mid + 1));
    };
    return -1;
};


int main()
{
    vector<int> a{4,5,6,7,0,1,2};
    int b = search(a, 0);
    return 0;
}

