//二分查找
#include <vector>
using namespace std;

int binarySearch(vector<int> nums, int target) 
{
    int left = 0; 
    int right = nums.size() - 1; // 注意

    while(left <= right) 
    {
        int mid = left + (right - left) / 2; //防止溢出
        if(nums[mid] == target) 
        {
            return mid; 
        }
        else if (nums[mid] < target)
        {
            left = mid + 1; // 注意
        }
        else if (nums[mid] > target)
        {
            right = mid - 1; // 注意
        }
    }
    return -1;
}

