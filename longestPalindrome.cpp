// 最长回文子串
// 马拉车 O(N)

// 动态规划
// dp[i][j]表示[i,j]是否是

#include <string>
#include <vector>
using namespace std;

string longestPalindrome(string s) 
{
    if(s.size() < 2)
    {
        return s;
    }
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
    // 一个数肯定是
    for(int i = 0; i < s.size(); i++)
    {
        dp[i][i] = true;
    };
    for(int i = 0; i < s.size() - 1; i++)
    {
        dp[i][i + 1] = s[i] == s[i + 1];
    };

    // 斜着遍历
    for(int j = 2; j < s.size(); j++)
    {
        int row = 0;
        int col = j;
        while(col < s.size())
        {
            if(s[row] == s[col])
            {
                dp[row][col] = dp[row + 1][col - 1] ? true : false;
            }
            else
            {
                dp[row][col] = false;
            };
            row++;
            col++;
        };
    };

    int max_v = 1;
    string ret;
    ret.push_back(s[0]);
    for(int i = 0; i < s.size(); i++)
    {
        for(int j = 0; j < s.size(); j++)
        {
            if(dp[i][j])
            {
                if(j - i + 1 > max_v)
                {
                    max_v = max(max_v, j - i + 1);
                    ret = s.substr(i, j - i + 1);
                }
               
            }
        }
    };

    return ret;
}

int main()
{
    auto ret = longestPalindrome("babad");
    return 0;
}
