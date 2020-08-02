//HUAWEI
// 给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

#include <vector>
#include <algorithm>
using namespace std;

int removeDuplicates(vector<int>& nums) 
{
    if(nums.empty())
    {
        return 0;
    };

    int norepeat_last_idx = 0;
    int cur_idx = 0;
    int cur_v = nums[0];
    while(cur_idx < nums.size())
    {
        if(nums[cur_idx] != cur_v)
        {
            cur_v = nums[cur_idx];
            swap(nums[norepeat_last_idx + 1], nums[cur_idx]);
            norepeat_last_idx++;
        };
        cur_idx++;
    };
    return norepeat_last_idx + 1;
};

int main()
{
    vector<int> v{0,0,1,1,1,2,2,3,3,4};
    auto ret = removeDuplicates(v);
    return 0;
}
