// 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
// 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
// 注意:
// 假设字符串的长度不会超过 1010。

#include <string>
#include<unordered_map>
using namespace std;

int longestPalindrome(string s) 
{
    unordered_map<char,int> mp;
    for(auto c : s)
    {
        auto iter = mp.find(c);
        if(iter == mp.end())
        {
            mp.insert({c, 1});
        }
        else
        {
            iter -> second++;
        }
    };

    int ret = 0;
    //统计偶数的个数
    bool has_jishu = false;
    for(auto iter = mp.begin(); iter != mp.end(); iter++)
    {
        if(iter->second & 1 == 1) //计数
        {
            has_jishu = true;
            ret += iter->second - 1;
        }
        else
        {
            ret += iter -> second;
        }
    };

    ret += has_jishu ? 1 : 0;
    return ret;
};


int main()
{
    auto ret = longestPalindrome("abccccdd");
    return 0;
}