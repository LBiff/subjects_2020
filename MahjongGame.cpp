//【字节】麻将游戏--雀魂
// 总共有36张牌，每张牌是1~9。每个数字4张牌。
// 你手里有其中的14张牌，如果这14张牌满足如下条件，即算作和牌
// 14张牌中有2张相同数字的牌，称为雀头。
// 除去上述2张牌，剩下12张牌可以组成4个顺子或刻子。顺子的意思是递增的连续3个数字牌（例如234,567等），
// 刻子的意思是相同数字的3个数字牌（例如111,777）
// 现在，小包从36张牌中抽取了13张牌，他想知道在剩下的23张牌中，再取一张牌，取到哪几种数字牌可以和牌。

#include <unordered_map>
#include <vector>
using namespace std;

vector<int> GetAnother(vector<int> nums)
{
    //统计
    unordered_map<int, int> map; //<value, count>
    for(auto i : nums)
    {
        auto iter = map.find(i);
        if(iter != map.end()) //存在
        {
            iter->second++;
        }
        else
        {
            map.insert({i,1});
        }
    };

    //雀头肯定满足
    //想要顺子缺什么
    //想要刻子缺什么
    //代码没必要写
    // int s = 1;
    // int shunzi = 0;
    // vector<vector<int>> need_sz; //想要满足顺子缺什么
    // while(s < 8)
    // {
    //     vector<int> tmp;
    //     auto iter_s = map.find(s);
    //     auto iter_s_1 = map.find(s + 1);
    //     auto iter_s_2 = map.find(s + 2);
    //     if(iter_s == map.end())
    //     {
    //         tmp.push_back(s);
    //     };
    //     if(iter_s_1 == map.end())
    //     {
    //         tmp = s + 1;
    //     }
    //     else if(iter_s_2 == map.end())
    //     {
    //         tmp = s + 2;
    //     }
    //     else
    //     {
    //         shunzi++;
    //     }
    //     if(tmp != 0) need_sz.push_back(tmp);
    // };

    // int kezi_count = 0;
    // vector<int> need_kz;
    // for(int i = 1; i<=9; i++)
    // {
    //     auto iter = map.find(i);
    //     if(iter != map.end())
    //     {
    //         if(iter->second >= 3)
    //         {
    //             kezi_count++;
    //         }
    //         else if(iter->second == 2)
    //         {
    //             need_kz.push_back(i);
    //         }
    //     }
    // };



}


