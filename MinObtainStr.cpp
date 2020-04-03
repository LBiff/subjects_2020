//最小覆盖字符串
//给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。

#include <string>
#include <cstdlib>
#include <vector>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t) 
{
    string ret;
    if(s.empty() || t.empty() || t.length() > s.length())
    {
        return ret;
    };

    int l = 0;
    int r = 0;
    int min_len = INT_MAX;
    pair<int, int> min_idx = {0,0};
    int s_need_match = t.length();
    //t字符数全部加入map，数组避免哈希碰撞
    vector<int> t_need_map_v(256, 0);

    //字符计算索引
    for(auto c : t)
    {
       t_need_map_v[c]++;
    };

    //处理一个的情况
    if(t.length() == 1)
    {
        
        return s.find(t[0], 0) >= s.length() ? string() : string() += t[0];
    }

    //循环体整体向右扩张寻找，但是当match_count =0 时停下来缩小。
    //循环进来考虑当前状态，r为待考察
    while(r < s.length())
    {
        //校验r
        t_need_map_v[s[r]]--;
        if(t_need_map_v[s[r]] >= 0)
        {
            s_need_match--;
        }
        
        //如果匹配完则向左查找最小
        if(s_need_match == 0)
        {
            //从左去除给多了的
            while(t_need_map_v[s[l]]  < 0)
            {
                t_need_map_v[s[l++]]++;
            }; 

            //计算当前长度
            if(r - l + 1 < min_len)
            {
                min_len = r - l + 1;
                min_idx = {l,r};
            };
            t_need_map_v[s[l++]]++; //l++的引入导致需要再还一个
            s_need_match++; //跳转到的当前l归还一个
        };
        r++; //r继续扩展
    };

    if(min_len == INT_MAX)
    {
        return string();
    }
    else //t至少有两个
    {
       string tmp = s.substr(min_idx.first, min_len);
       return tmp;
    }
};

int main()
{
    string s = "aa";
    string t = "aa";
    string c = minWindow(s,t);
    return 0;
}
