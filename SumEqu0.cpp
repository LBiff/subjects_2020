//和0问题
//数组中两数和，入哈希，o(n)查询

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

//三和问题
//排序后，从左到右选定一个“可能的三个中的最小”，后面的左右指针查找2和，重复的跳过
vector<vector<int>> threeSum(vector<int>& nums) 
{
    vector<vector<int>> ret;
    if(nums.size() <3)
    {
        return ret;
    };

    sort(nums.begin(), nums.end());
    if(nums.front() == nums.back())
    {
        if(nums[0] == 0)
        {
            return {{0,0,0}};
        }
        else
        {
            return ret;
        }
    };

    int c = 0;  //最小的

    auto l_plus = [&](int&  l, int l_end)
    {
        while(l < l_end && nums[l + 1]  == nums[l])
        {
            l++;
        };
        l++;
    };

    auto r_reduce= [&](int& r, int r_end)
    {
        while(r > r_end && nums[r - 1]  == nums[r])
        {
            r--;
        };
        r--;
    };

    while(c < (static_cast<int>(nums.size()) - 2))
    {
        if(nums[c] > 0)
        {
            break;
        }
        int l = c +1;
        int r = nums.size() - 1;
        while(l < r)
        {
            int sum = nums[l] + nums[r] + nums[c];
            if(sum > 0)
            {
                r_reduce(r, l);
            }
            else if(sum < 0)
            {
                l_plus(l, r);
            }
            else 
            {
                ret.push_back({nums[c], nums[l], nums[r]});
                r_reduce(r, l);
                l_plus(l, r);
            }
        }
        l_plus(c, nums.size() - 1);
    };

    return ret;
}
int main()
{
    vector<int> a{-2,-3,0,0,-2};
    threeSum(a);
    return 0;
}