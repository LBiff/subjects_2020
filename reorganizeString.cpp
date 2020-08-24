// 给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。
// 若可行，输出任意可行的结果。若不可行，返回空字符串。

#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

// 核心： 任何一种字符串不能超过 (n + 1) / 2才能重构成功
// ERR
string reorganizeString(string S) 
{
    if(S.empty())
    {
        return "";
    }
    double max_count = (S.size() + 1) / 2.0;
    map<char,int> mp;
    for(auto c : S)
    {
        auto iter = mp.find(c);
        if(iter == mp.end())
        {
            mp.insert({c, 1});
        }
        else
        {
            iter -> second++;
            if(iter->second > max_count)
            {
                return "";
            }
        }
    };

    //能够重构
    string s;
    for(auto iter = mp.begin(); iter != mp.end(); iter++)
    {
        string tmp_s;
        int s_idx = 0;
        int tmp_idx = 0;
        while(s_idx < s.size() && tmp_idx < iter -> second)
        {
            tmp_s.push_back(s[s_idx]);
            tmp_s.push_back(iter->first);
            s_idx++;
            tmp_idx++;
        };
        while(s_idx < s.size())
        {
            tmp_s.push_back(s[s_idx++]);
        };
        while(tmp_idx < iter -> second)
        {
            tmp_s.push_back(iter -> first);
            tmp_idx++;
        };
        s = tmp_s;
    };

    return s;
};


int main()
{
    string S = "vvvlo";
    auto ret = reorganizeString(S);
    return 0;
}
