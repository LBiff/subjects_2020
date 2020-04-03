//查找数组中未出现的数
// 给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
// 找到所有在 [1, n] 范围之间没有出现在数组中的数字。
// 您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

//1.哈希检查
//2.将索引作为标记，比如nums[i] = 2,我们知道2出现过了，则我们将nums[2 - 1] 标记为负的，最后遍历谁是正的谁就没出现过
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        for(int i = 0; i < nums.size(); i++)
        {
            int flag = nums[i] < 0 ? -nums[i] : nums[i];
             //标记
            if(nums[flag - 1] > 0)
            {
                nums[flag - 1] *= -1;
            };
        };
        vector<int> ret;
        for(int i =0; i< nums.size(); i++)
        {
            if(nums[i] > 0)
            {
                ret.push_back(i + 1);
            }
        };
        return ret;
    }
};