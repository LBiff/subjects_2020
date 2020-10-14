// 给定一个二进制数组, 找到含有相同数量的 0 和 1 的最长连续子数组（的长度）。

#include <vector>
#include <unordered_map>
using namespace std;

int findMaxLength(vector<int>& nums) 
{
    //0改-1
    for(auto& n : nums)
    {
        n = n == 0 ? -1 : n;
    };

    //求前缀和
    unordered_map<int,int> mp; //<前缀和，最早的索引
    mp.insert({0, -1});
    int max_len = 0;
    int cur_sum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        cur_sum += nums[i];
        auto iter = mp.find(cur_sum);
        if(iter == mp.end())
        {
            mp.insert({cur_sum, i});
        };
        auto iter_2 = mp.find(cur_sum);
        if(iter_2 != mp.end())
        {
            if(i - iter_2->second > 1)
            {
                max_len = max(max_len, i - iter_2->second);
            }
            
        }
    };
    return max_len;
};

int main()
{
    vector<int> v{0,0,1,0,0,0,1,1};
    auto ret = findMaxLength(v);
    return 0;
}
