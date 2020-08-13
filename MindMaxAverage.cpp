// 给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。

// 示例 1:
// 输入: [1,12,-5,-6,50,3], k = 4
// 输出: 12.75
// 解释: 最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
 
// 注意:
// 1 <= k <= n <= 30,000。
// 所给数据范围 [-10,000，10,000]。

#include <vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) 
{
    //前缀和
    int sum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        nums[i] = sum;
    };
    int max_sum = nums[k - 1];
    for(int i = k; i < nums.size(); i++)
    {
        max_sum = max(max_sum, nums[i] - nums[i - k]);
    };
    return (double)max_sum / k;
};

int main()
{
    vector<int> v{1,12,-5,-6,50,3};
    auto ret = findMaxAverage(v,4);
    return 0;
}
