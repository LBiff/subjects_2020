// nSum问题

#include <vector>
#include <algorithm>
using namespace std;

// 2数和-双指针
vector<int> twoSum(vector<int>& nums, int target) 
{
    int l_idx = 0;
    int r_idx = nums.size() - 1;
    while(l_idx < r_idx)
    {
        int sum = nums[l_idx] + nums[r_idx];
        if(sum == target)
        {
            return {nums[l_idx], nums[r_idx]};
        }
        else if(sum < target)
        {
            l_idx++;
        }
        else
        {
            r_idx--;
        }
    };
    return {-1,-1};
};

// 2数和，多对
// nums 中可能有多对儿元素之和都等于 target，请你的算法返回所有和为 target 的元素对儿，其中不能出现重复
vector<vector<int>> twoSumTarget(vector<int>& nums, int start, int target)
{
    vector<vector<int>> ret;
    if(start < 0 || start > nums.size() - 2)
    {
        return ret;
    }
    sort(nums.begin(), nums.end());
    int l_idx = start;
    int r_idx = nums.size() - 1;

    while(l_idx < r_idx)
    {
        int sum = nums[l_idx] + nums[r_idx];
        if(sum == target)
        {
            ret.push_back({nums[l_idx], nums[r_idx]});
            //跳过所有的相等的
            int left = nums[l_idx];
            while(nums[l_idx] == left)
            {
                l_idx++;
            };

            int right = nums[r_idx];
            while(nums[r_idx] == right)
            {
                r_idx--;
            }
        }
        else if(sum < target)
        {
            l_idx++;
        }
        else
        {
            r_idx--;
        }
    };
    return ret;
};

//3数和
// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
// 请你找出所有满足条件且不重复的三元组。

//三数和--固定一个数求解其他两数
vector<vector<int>> threeSum(vector<int>& nums, int target) 
{
    vector<vector<int>> ret;
    if(nums.size() < 3)
    {
        return ret;
    }
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++)
    {
        int tmp = nums[i];
        auto twoSum = twoSumTarget(nums, i + 1, target - tmp);
        for(auto t : twoSum)
        {
            vector<int> three{tmp,t[0], t[1]};
            ret.push_back(three);
        };

        while(nums[i] == tmp)
        {
            i++;
        };
        i--;
    };
    return ret;
};


//nsum
//按要与不要处理存在重复
// ****nums的输入时从小到大排序的
vector<vector<int>> NSum(const vector<int>& nums, int n, int start, int target)
{
    vector<vector<int>> ret;
    if(start < 0 || start > nums.size() - n || n < 2 || n > nums.size())
    {
        return ret;
    };

    if(n == 2) //2数和的双指针
    {
        int l_idx = start;
        int r_idx = nums.size() - 1;
        while(l_idx < r_idx)
        {
            int left = nums[l_idx];
            int right = nums[r_idx];
            int sum = left + right;
            if(sum < target)
            {
                while(l_idx < r_idx && nums[l_idx] == left) l_idx++;
            }
            else if(sum > target)
            {
                while(l_idx < r_idx && nums[r_idx] == right) r_idx--;
            }
            else
            {
                ret.push_back({nums[l_idx], nums[r_idx]});
                while(l_idx < r_idx && nums[l_idx] == left) l_idx++;
                while(l_idx < r_idx && nums[r_idx] == right) r_idx--;
            }
        }
    }
    else
    {
        for(int i = start; i < nums.size(); i++)
        {
            int tmp = nums[i];
            auto n_1_sum = NSum(nums,n - 1, i + 1, target - tmp);
            for(auto& n_i : n_1_sum)
            {
                n_i.push_back(tmp);
                ret.push_back(n_i);
            };

            while(i < nums.size() - 1 && nums[i] == nums[i + 1])
            {
                i++;
            };
        }; 
    }
    return ret;
}


int main()
{
    vector<int> nums{0,0,0};
    sort(nums.begin(), nums.end());
    auto ret = NSum(nums, 3, 0, 0);
    return 0;
}
