//和为k的子数组
//哈希一遍
//记录从左到右累加和，和为k表示和为sum的从左开始的子数组-和为sum-k的左起左数组
#include <vector>
#include <unordered_map>
using namespace std;

//哈希一遍
class Solution 
{
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int> map; //<sum, count>
        map.insert({0,1});
        int sum = 0;
        int count = 0;
        for(auto i : nums)
        {
            sum += i;
            auto iter = map.find(sum - k);
            if(iter != map.end())
            {
                count += iter->second;
            };
            auto iter_2 = map.find(sum);
            if(iter_2 != map.end())
            {
                iter_2->second++;
            }
            else
            {
                map.insert({sum, 1});
            }
        };
        return count;
    }
};

