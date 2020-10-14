// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//稳定性排序
// 输入: [0,1,0,3,12]
// 输出: [1,3,12,0,0]

#include <algorithm>
#include <vector>
using namespace std;

//思路：该元素是第几个非0就将其和第几个元素交换
void moveZeroes(vector<int>& nums) 
{
    int no_zero_idx = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] != 0)
        {
            swap(nums[i], nums[no_zero_idx++]);
        }
    }
};

