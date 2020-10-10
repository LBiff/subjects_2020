// 给定一个包含 非负数 的数组和一个目标 整数 k，编写一个函数来判断该数组是否含有连续的子数组，其大小至少为 2，
// 且总和为 k 的倍数，即总和为 n*k，其中 n 也是一个整数。

#include <vector>
#include <unordered_map>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) 
{
    if(nums.size() < 2)
    {
        return false;
    };

    unordered_map<int,int> mp; //<前缀和 % k, idx>, 只有在不存在的时候才插入，插入后不更新，即取最前
    mp.insert({0, -1});
    int sum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if(k != 0)
        {
            sum = sum % k;
        }
        
        auto iter = mp.find(sum);
        if(iter != mp.end() && i - iter->second >= 2)
        {
            return true;
        };

        if(iter == mp.end())
        {
            mp.insert({sum, i});
        };
    };
    return false;
};

int main()
{
    vector<int> v{5,0,0};
    auto ret = checkSubarraySum(v, 0);
    return 0;
}