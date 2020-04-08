//正则表达式的匹配
// 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
// '.' 匹配任意单个字符
// '*' 匹配零个或多个前面的那一个元素
// 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
// 说明:
// s 可能为空，且只包含从 a-z 的小写字母。
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。


#include <string>
#include <vector>
using namespace std;

bool isMatch(string s, string p) 
{
    int a_length = s.length();
    int b_length = p.length();
    vector<vector<bool>> dp(a_length + 1,vector<bool>(b_length+ 1, false)); //00为空串，考虑空串的情况

    //填充第一列和第一行
    //空正则与空字符串匹配
    dp[0][0] = true;
    //空正则与非空字符串不匹配
    //空字符串与非空正则，需要正则是 a*a*a*a*的形式
    for(int col = 1; col < b_length + 1; col ++)
    {
        if(p[col - 1] == '*' && dp[0][col - 2])
        {
            dp[0][col] = true;
        }
    };

    for(int row = 1; row < a_length + 1; row++)
    {
        for(int col = 1; col < b_length + 1; col++)
        {
            char s_c = s[row - 1];
            char p_c = p[col - 1];
            if(s_c == p_c) //直接匹配
            {
                dp[row][col] = dp[row - 1][col - 1];
            }
            else
            {
                if(p_c == '.')
                {
                    dp[row][col] = dp[row - 1][col - 1]; //可以直接匹配
                }
                else if(p_c == '*')
                {
                    if(col >= 2) //需要查看dp[col - 2],当前是p[col - 1]
                    {
                        //p[col - 2] == s_c
                        if(p[col - 2] == s_c || p[col-2] == '.') //可以匹配， *可以取1个或者多个前字符
                        {
                            //s和p减一个，以及*==0匹配的匹配度和目前是一样的
                            dp[row][col] = dp[row - 1][col] || //取1个字符
                                           dp[row][col - 1];
                        };
                        //不论p[col - 2]是否等于s_c,都可以删除col- 1和 col - 2处字符
                        dp[row][col] =  dp[row][col] || dp[row][col - 2];
                    }
                }
                else
                {
                    dp[row][col] = false;
                }
            }
        }
    };
    return dp[a_length][b_length];
};

int main()
{
    string s ="ab";
    string p = ".*";
    auto ret = isMatch(s,p);
    return ret;
}

