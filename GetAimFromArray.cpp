//数组中查找和为aim的数对
#include <algorithm>
#include <vector>
using namespace std;

 vector<vector<int>> pairSums(vector<int>& nums, int target) 
{
    vector<vector<int>> ret;
    if(nums.size() < 2)
    {
        return ret;
    };

    sort(nums.begin(), nums.end());
    int l_idx = 0;
    int r_idx = nums.size() - 1;
    while(l_idx < r_idx)
    {
        if(nums[l_idx] + nums[r_idx] == target)
        {
            ret.push_back({nums[l_idx], nums[r_idx]});
            l_idx++;
            r_idx--;
        }
        else if(nums[l_idx] + nums[r_idx] < target)
        {
            l_idx++;
        }
        else
        {
            r_idx--;
        };
    };

    return ret;
};

int main()
{
    vector a{5,6,5};
    auto ret  = pairSums(a,11);
    return 0;
}