//HUAWEI
// 给定两个字符串 s 和 t，它们只包含小写字母。
// 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
// 请找出在 t 中被添加的字母。


//实质是找出字符个数不同的字符
//或者直接排序
#include <string>
#include <unordered_map>
using namespace std;

char findTheDifference(string s, string t) 
{
    unordered_map<char, int> map; //char, count
    for(auto c : s)
    {
        auto iter = map.find(c);
        if(iter != map.end())
        {
            iter->second++;
        }
        else
        {
            map.insert({c,1});
        }
    };
    unordered_map<char, int> t_map; //char, count
    for(auto t_c : t)
    {
        auto iter_t = t_map.find(t_c);
        if(iter_t != t_map.end())
        {
            iter_t->second++;
        }
        else
        {
            t_map.insert({t_c,1});
        };

        auto iter_s = map.find(t_c);
        if(iter_s == map.end() || t_map.find(t_c)->second > iter_s->second)
        {
            return t_c;
        }
    };

    return '0';
};