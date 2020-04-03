//下一个排列
//实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
//如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
//必须原地修改，只允许使用额外常数空间。
#include <vector>
#include <stdexcept>
using namespace std;

class Solution 
{
public:
    void nextPermutation(vector<int>& nums) 
    {
        if(nums.size() < 2)
        {
            return;
        };

        //从右开始找出第一个不升数
        int r = nums.size() - 1;
        while(r > 0 && nums[r - 1] >=  nums[r]){r--;}; 
        if(r == 0) //全部升序
        {
            //直接翻转
            exchange_vec(nums, 0, nums.size() - 1);
        }
        else
        {
            int aim = nums[r - 1];
            int greater_aim_idx = r;
            while(greater_aim_idx < nums.size() && nums[greater_aim_idx] > aim)
            {
                greater_aim_idx++;
            };
            greater_aim_idx--;
            
            //交换aim和greater_aim
            nums[r - 1] = nums[greater_aim_idx];
            nums[greater_aim_idx] = aim;

            //aim后逆序
            exchange_vec(nums, r, nums.size() - 1);
        }
    };

    //原地逆转数组，[begin, end]
    void exchange_vec(vector<int>& nums, int begin, int end)
    {
        if(begin < 0 || end > nums.size() - 1 || end < begin )
        {
            throw invalid_argument("exchange_vec(...) invaild_argument...");
        };
        while(begin < end)
        {
            int tmp = nums[begin];
            nums[begin] = nums[end];
            nums[end] = tmp;
            begin++;
            end--;
        }
    };

};


int main()
{
    vector<int> nums{5,1,1};
    Solution s;
    s.nextPermutation(nums);
    return 0;
}