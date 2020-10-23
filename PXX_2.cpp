
// 给定一个由a-z构成的字符串S, 找S的一个子串，满足P包含S中出现的所有字符
// 找到字典序最小且起始位置更大的子串P

#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

pair<int,int> GetPair(const string& s)
{
    unordered_set<char> st_all;
    unordered_map<char, int> mp; //char, count
    for(auto i : s)
    {
        auto iter = st_all.find(i);
        if(iter == st_all.end())
        {
            st_all.insert(i);
        }
    };

    int total_count = st_all.size();
    int cur_count = 1;
    int l_idx = 0;
    int r_idx = 0;
    mp.insert({s[0], 1});
    pair<int,int> ret{-1,-1};
    while(r_idx < s.size())
    {
        if(cur_count < total_count)
        {
            r_idx++;
            auto iter = mp.find(s[r_idx]);
            if(iter == mp.end())
            {
                mp.insert({s[r_idx], 1});
                cur_count++;
            }
            else
            {
                iter->second++;
            };
        }
        else if(cur_count == total_count)
        {
            if(ret.first == -1)
            {
                ret = {l_idx, r_idx};
            }
            else
            {
                auto ret_s = s.substr(ret.first, ret.second - ret.first + 1);
                auto cur_s = s.substr(l_idx, r_idx - l_idx + 1);
                if(ret_s > cur_s || 
                   (ret_s == cur_s && l_idx > ret.first))
                {
                    ret = {l_idx, r_idx};
                }
            }
            
            
            while(1)
            {
                auto iter = mp.find(s[l_idx]);
                if(iter->second == 1)
                {
                    mp.erase(s[l_idx]);
                    cur_count--;
                    l_idx++;
                    break;
                }
                else
                {
                   iter->second--;
                };
                l_idx++;

                if(ret.first == -1)
                {
                    ret = {l_idx, r_idx};
                }
                else
                {
                    auto ret_s = s.substr(ret.first, ret.second - ret.first + 1);
                    auto cur_s = s.substr(l_idx, r_idx - l_idx + 1);
                    if(ret_s > cur_s || 
                    (ret_s == cur_s && l_idx > ret.first))
                    {
                        ret = {l_idx, r_idx};
                    }
                }
            }
        }
        else
        {
            auto iter = mp.find(s[l_idx]);
            if(iter->second == 1)
            {
                mp.erase(s[l_idx]);
                cur_count--;
            }
            else
            {
                iter->second--;
            };
            l_idx++;
        };
    };
    return ret;
};

int main()
{
    auto ret = GetPair("abcdeee");
    return 0;
};

// abcdeee
// 0 5
// dcdcazazazdcdc
// 1 5
// 