//最接近的3个数
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <functional>
using namespace std;

//从左到右遍历确定一个数，后面的双指针寻找另外两个
int threeSumClosest(vector<int>& nums, int target) 
{
    int ret;
    int min_diff = INT_MAX;
    sort(nums.begin(), nums.end(),less<int>());
    for(int i =0;i <nums.size(); i++)
    {
        int first = nums[i];
        int l_idx = i + 1;
        int r_idx = nums.size() - 1;
        while(l_idx < r_idx)
        {
            int sum = nums[l_idx] + nums[r_idx] + first;
            int abs_diff = abs(target - sum);
            if(abs_diff < min_diff)
            {
                min_diff = abs_diff;
                ret = sum;
            };

            if(sum < target)
            {
                l_idx++;
            }
            else if(sum > target)
            {
                r_idx--;
            }
            else
            {
                return target;
            }
        }
    };
    return ret;
};

int main()
{
    vector<int> v{-1,2,1,-4};
    auto ret = threeSumClosest(v, 1);
    return 0;
}