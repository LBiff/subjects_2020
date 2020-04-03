// 给你一个无序的数组 nums, 将该数字 原地 重排后使得 nums[0] <= nums[1] >= nums[2] <= nums[3]...
// 示例:
// 输入: nums = [3,5,2,1,6,4]
// 输出: 一个可能的解答是 [3,5,1,6,2,4]
#include <vector>
using namespace std;
class Solution 
{
public:
    //不符合规则的直接交换，，直接遍历就行
    void wiggleSort(vector<int>& nums) 
    {
        if(nums.size() < 2)
        {
            return;
        }
        bool less = true; //v[i]与v[i+1]小于等于的关系
        for(int i =1; i<nums.size(); i++)
        {
            if((less && nums[i-1] > nums[i]) || (!less && nums[i-1] < nums[i]))
            {
                swap(nums[i - 1], nums[i]);
            };
            less = !less;
        }
    }
};