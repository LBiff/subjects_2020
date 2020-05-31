//有序数组中的缺失元素
// 给出一个有序数组 A，数组中的每个数字都是 独一无二的，找出从数组最左边开始的第 K 个缺失数字。
// 示例 1：
// 输入：A = [4,7,9,10], K = 1
// 输出：5
// 解释：
// 第一个缺失数字为 5 。
#include <vector>
using namespace std;

//细节题
int missingElement(vector<int>& nums, int k)
{
    if(nums.size() == 1)
    {
        return nums[0] + k;
    };
    int del_count = 0;
    int idx = 0; //起点
    while(idx < nums.size())
    {
        if(idx + 1 < nums.size())
        {
            int diff = nums[idx + 1] - nums[idx];
            del_count += diff > 1 ? diff - 1 : 0;
            if(del_count >= k)
            {
                break;
            };
            idx++;
        }
        else //到达终点
        {
            return nums.back() + k - del_count;
        };
    };
    return nums[idx + 1] - (del_count - k) - 1;
};

int main()
{
    vector<int> v{4,7,9,10};
    auto ret = missingElement(v,3);
    return 0;
}