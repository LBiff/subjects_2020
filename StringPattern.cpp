//字符串匹配
//给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
#include <string>
using namespace std;

//1) *不能开头 2) 不能**连接  3)str中不能有* 和 .
bool IsValid(const string& s, const string& p)
{
    if(s.find('*') != std::string::npos || s.find('.')!=std::string::npos)
    {
        return false;
    };
    if(!p.empty())
    {
        if(p[0] == '*')
        {
            return false;
        };

        int idx = 1;
        
        for(;idx < p.length();idx++)
        {
            if(p[idx] == '*')
            {
                if(idx + 1 < p.length() && p[idx + 1] == '*')
                {
                    return false;
                }
            }
        }
    };

    return true;
};


//递归
//s从s_idx到结尾，p从p_idx到结尾进行匹配
//短的匹配长的，P匹配S
bool Process(const string& s, const string& p, int s_idx, int p_idx)
{
    //匹配同时终止
    if(p_idx == p.length())
    {
        return s_idx == s.length();
    };

}


int IsPalindrome(const string& s, const string& p)
{
    //一方为空
    if(s.empty() || p.empty())
    { 
        return false;
    };
    return IsValid(s,p) ? Process(s,p,0,0) : false;
}
