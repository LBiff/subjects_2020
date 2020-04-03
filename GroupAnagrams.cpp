//字母异位词
//关键： 字母异位：排序后相等或者字母计数相等
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        
        unordered_map<string, vector<string>> map;
        for(auto s : strs)
        {
            vector<int> f_v(26,0);
            for(auto c : s)
            {
                f_v[c - 'a']++;
            };
            
            string flag;
            for(auto v : f_v)
            {
                flag += to_string(v);
                flag += "#";
            };
            auto iter = map.find(flag);
            if(iter != map.end())
            {
                iter->second.push_back(s);
            }
            else
            {
                map.insert({flag, {s}});
            }
        };
        
        vector<vector<string>> ret;
        for(auto iter = map.begin(); iter != map.end(); iter++)
        {
            ret.push_back(iter->second);
        };
        
        return ret;
    }
};