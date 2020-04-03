//同构字符串
// 给定两个字符串 s 和 t，判断它们是否是同构的。
// 如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
// 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身
#include <string>
#include <unordered_map>
using namespace std;

//3个条件： 1.长度相等，相等字符数相等 3.映射同步
class Solution 
{
public:
    bool isIsomorphic(string s, string t) 
    {
        if(s.size() != t.size())
        {
            return false;
        }
        //不同字符数应该相等
        unordered_map<char, int> map_1;
        unordered_map<char,int> map_2;
        for(auto s_i : s)
        {
            auto iter = map_1.find(s_i);
            if(iter != map_1.end())
            {
                iter->second++;
            }
            else
            {
                map_1.insert({s_i, 1});
            }
        };

        for(auto t_i : t)
        {
            auto iter = map_2.find(t_i);
            if(iter != map_2.end())
            {
                iter->second++;
            }
            else
            {
                map_2.insert({t_i, 1});
            }
        };

        if(map_1.size() != map_2.size())
        {
            return false;
        };
        //建立相对映射
        unordered_map<char,char> map_3;

        for(int i =0; i< s.size(); i++)
        {
            auto iter = map_3.find(s[i]);
            if(iter == map_3.end())
            {
                map_3.insert({s[i], t[i]});
            }
            else
            {
                if(iter->second != t[i])
                {
                    return false;
                }
            }
        };
        return true;
    }
};