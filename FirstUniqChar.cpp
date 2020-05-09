//字符串中的第一个唯一字符
// 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

//map存储字符出现的次数以及第一次出现的idx
//查找次数==1 的Min_idx
#include <string>
#include <cstdlib>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s) 
{
    unordered_map <char,pair<int, int>> map; //<char, pair<count, min_idx>>
    for(int i = 0; i < s.size(); i++)
    {
        auto iter = map.find(s[i]);
        if(iter != map.end())
        {
            iter->second.first++;
        }
        else
        {
            map.insert({s[i],{1, i}});
        }
    };

    size_t min_idx = s.size();
    for(auto iter = map.begin(); iter != map.end(); iter++)
    {
        if(iter->second.first == 1)
        {
            min_idx = min(min_idx, (size_t)iter->second.second);
        }
    };

    return min_idx == s.size() ? -1 : min_idx;
}