// 76. 最小覆盖子串
// 给你一个字符串 S、一个字符串 T 。请你设计一种算法，可以在 O(n) 的时间复杂度内，
// 从字符串 S 里面找出：包含 T 所有字符的最小子串。

// 滑动窗口法

#include <string>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t) 
{
    if(s.empty() || t.empty())
    {
        return "";
    };
    
    unordered_map<char,int> need, window;
    for(auto t_i :t)
    {
        auto iter = need.find(t_i);
        if(iter == need.end())
        {
            need.insert({t_i, 1});
        }
        else
        {
            iter->second++;
        }
    };

    //滑动窗口[l_idx, r_idx)
    int l_idx = 0;
    int r_idx = 0;
    // 内部操作： r_idx右扩寻找更大的区间，满足则左缩
    int vaild = 0; // window中字符数满足need的字符的数目

    int min_len = INT_MAX;
    int start_idx = 0;
    while(r_idx < s.size())
    {
        // 右边即将扩进来的字符
        char r_c = s[r_idx];
        r_idx++;

        auto iter_n = need.find(r_c);
        if(iter_n != need.end())  //只有相等的时候才加一回
        {
            auto iter_w = window.find(r_c);
            if(iter_w == window.end())
            {
                window.insert({r_c, 1});
            }
            else
            {
                iter_w->second++;
            };

            if(window.find(r_c)->second == need.find(r_c)->second)
            {
                vaild++;
            }
        };

        // 满足则尝试左缩
        while(vaild == need.size())
        {
            // 更新
            if(r_idx - l_idx < min_len)
            {
                min_len = r_idx - l_idx;
                start_idx = l_idx;
            }

            char l_c = s[l_idx];
            l_idx++;
            if(need.find(l_c) != need.end())
            {
                if(window.find(l_c)->second == need.find(l_c)->second)
                {
                    vaild--;
                }
                window.find(l_c)->second--;
            };
        }
    };

    return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
};

int main()
{
    string S = "ADOBECODEBANC";
    string T = "ABC";
    auto ret = minWindow(S,T);
    return 0;
}

