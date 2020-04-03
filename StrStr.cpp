//实现 strStr() 函数。
// 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 
// 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
#include <string>
#include <vector>
using namespace std;
 
class Solution
{
public:
    int strStr(string haystack, string needle) 
    {
        vector<int> next = GetNext(needle);
        int s1_idx = 0;
        int s2_idx = 0;
        while(s1_idx < haystack.length() && s2_idx < needle.length())
        {
            if(haystack[s1_idx] == needle[s2_idx])
            {
                s1_idx++;
                s2_idx++;
            }
            else if(next[s2_idx] == -1)
            {
                s1_idx++;
            }
            else
            {
                s2_idx = next[s2_idx];
            }
        };
        return s2_idx == needle.size() ? s1_idx - s2_idx : -1;
    };  

    //获取待匹配字符串的next数组
    vector<int> GetNext(string s_2)
    {
        if(s_2.empty())
        {
            return vector<int>();
        }
        else if(s_2.size() == 1)
        {
            return {-1};
        };
        vector<int> next(s_2.size());
        //强行规定
        next[0] = -1;
        next[1] = 0;
        int pre = 0;

        int idx = 2;
        while(idx < s_2.size())
        {
            if(s_2[idx] == s_2[pre])
            {
                next[idx++] = ++pre;
            }
            else if(pre > 0)
            {
                pre = next[pre];
            }
            else
            {
                next[idx++] = 0;
            }
        };
        return next;
    };
};

int main()
{
    Solution s;
    string s_1 = "mississippi";
    string s_2 = "issip";
    auto ret = s.strStr(s_1,s_2);
    return 0;
}
