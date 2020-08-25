// . 有效三角形的个数
// 给定一个包含非负整数的数组，你的任务是统计其中可以组成三角形三条边的三元组个数。

#include <vector>
#include <algorithm>
using namespace std;

int triangleNumber(vector<int>& nums) 
{
    if(nums.size() < 3)
    {
        return 0;
    }
    sort(nums.begin(), nums.end());
    //枚举i,j, 求k
    int ret = 0;
    for(int i = 0; i < nums.size() - 2; i++)
    {
        for(int j = i + 1; j < nums.size() - 1 && nums[i] != 0; j++)
        {
            int k = j + 1;
            while(k < nums.size() && nums[i] + nums[j] > nums[k])
            {
                k++;
            };
            ret += k - j - 1;
        }
    };

    return ret;
}