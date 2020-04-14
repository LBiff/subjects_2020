//maxEqualFreq
// 给出一个正整数数组 nums，请你帮忙从该数组中找出能满足下面要求的 最长 前缀，并返回其长度：
// 从前缀中 删除一个 元素后，使得所剩下的每个数字的出现次数相同。
// 如果删除这个元素后没有剩余元素存在，仍可认为每个数字都具有相同的出现次数（也就是 0 次）

//可以满足条件的情况讨论
// 能够满足答案的条件:
// 1、只有一种数字。如：1 1 1 1 1 
// 2、有多种数字，但每个数字只出现一次。 如：1 2 3 4 5
// 3、有多种数字，其中一种数字出现n+1次，其他出现n次。如：1 1 1 2 2 3 3 4 4
// 4、有多种数字，其中一种数字出现1次，其他出现n次。如：1 2 2 2 3 3 3 4 4 4
// 两个数组，arr_a 和 arr_b, arr_a[i]表示数字i出现次数，arr_b[i]表示出现频率为i的数字个数。
// 因此，成立条件为，arr_b[1]==n || 最高频次==1
//                 || (arr_b[最高频次]==1 && arr_b[最高频次-1]==(n-1))
//                 || (arr_b[最高频次]==(n-1) && arr_b[1]==1)
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int maxEqualFreq(vector<int>& nums) 
{
    
    unordered_map<int, unordered_set<int>> map_freq_nums; //<freq, nums>
    unordered_map<int, int> map_num_freq; //<num, freq> 数字,频率

    int max_right = 0;
    int max_freq = 0; //记录最高频次
    for(int i = 0; i < nums.size(); i++)
    {
        //先更新数据
        auto iter_freq = map_num_freq.find(nums[i]);
        int freq_i = 0; //本数的频率
        if(iter_freq != map_num_freq.end())
        {
            iter_freq->second++;
            max_freq = iter_freq->second > max_freq ? iter_freq->second : max_freq;
            freq_i = iter_freq->second;
        }
        else
        {
            map_num_freq.insert({nums[i], 1});
            max_freq = 1 > max_freq ? 1 : max_freq;
            freq_i = 1;
        };

        auto iter_size = map_freq_nums.find(freq_i);
        if(iter_size != map_freq_nums.end() && iter_size->second.find(nums[i]) == iter_size->second.end()) //存在这个频率
        {

            iter_size->second.insert(nums[i]);
        }
        else
        {
            map_freq_nums.insert({freq_i, {nums[i]}});
        };

        //将上频率删除
        auto iter_size_1 = map_freq_nums.find(freq_i - 1);
        if(freq_i > 1 && iter_size_1 != map_freq_nums.end() 
                        && iter_size_1->second.find(nums[i]) != iter_size_1->second.end())
        {
            iter_size_1->second.erase(nums[i]);
        }

        //进行四项判断
        if(map_num_freq.find(nums[i])->second == i + 1 //只有一种数字
            || max_freq == 1  //有多种数字，但每个数字只出现一次
            //有多种数字，其中一种数字出现n+1次，其他种类出现n次
            || (map_freq_nums.find(max_freq)->second.size() == 1 && max_freq > 1
                && map_freq_nums.find(max_freq - 1)->second.size() == map_num_freq.size() - 1)
            //有多种数字，其中一种数字出现1次，其他出现n次
            || (map_freq_nums.find(max_freq)->second.size() == map_num_freq.size() - 1
                && map_freq_nums.find(1)->second.size() == 1))
        {
            max_right = i;
        }
    };

    return max_right + 1;
};

int main()
{
    vector<int> v{2,2,1,1,5,3,3,5};
    auto ret = maxEqualFreq(v);
    return 0;
}
