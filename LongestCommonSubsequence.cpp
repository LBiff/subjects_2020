//最长公共子序列
// 求两个字符串的 LCS 长度

#include <string>
#include <vector>
using namespace std;

//dp[i][j]表示s1[0..i] 和 s2[0...j]的最长公共子序列长度
// 递归版本
int GetLCS(const string& s1, const string& s2, int idx_1, int idx_2, vector<vector<int>>& dp)
{
    if(idx_1 == 0 || idx_2 == 0)
    {
        return 0;
    };
    if(s1[idx_1 - 1] == s2[idx_2 - 1])
    {
        dp[idx_1 - 1][idx_2 - 1] = dp[idx_1 - 1][idx_2 - 1] != -1 ? dp[idx_1 - 1][idx_2 - 1]
                                                                    :GetLCS(s1,s2,idx_1 - 1, idx_2 - 1, dp);

        return dp[idx_1 - 1][idx_2 - 1] + 1;
    }
    else
    {
        dp[idx_1 - 1][idx_2] = dp[idx_1 - 1][idx_2] == -1 ? GetLCS(s1,s2,idx_1 - 1, idx_2,dp)
                                                            : dp[idx_1 - 1][idx_2];
        dp[idx_1][idx_2 - 1] = dp[idx_1][idx_2 - 1] == -1 ? GetLCS(s1,s2,idx_1, idx_2 - 1,dp)
                                : dp[idx_1][idx_2 - 1];
        return max(dp[idx_1 - 1][idx_2], dp[idx_1][idx_2 - 1]);
    }
};

int longestCommonSubsequence(string s1, string s2) 
{
    //从后往前遍历
    //dp[i][j]表示 s1[0, i]和s2[0,j]的 LCS的长度
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
    return GetLCS(s1,s2,s1.length(), s2.length(), dp);
};

//dp表版本
int LCS_DP(string s1, string s2)
{
    //dp[i][j]表示s1[0,i]和s2[0,j]区间的最长公共子序列的长度, [0,0]表示空串

    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    // basecase dp[0][j]和dp[i][0] = 0; 已经初始化
    //转移
    // dp[i][j] = s1[i] == s2[j] ? dp[i - 1][j - 1] + 1 : 
    //                           max(dp[i - 1][j], dp[i][j - 1])
    // 选择从上到下从左到右的顺序
    for(int i = 1; i < s1.size() + 1; i++)
    {
        for(int j = 1; j < s2.size() + 1; j ++)
        {
            if(s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }   
        }
    };

    return dp[s1.size()][s2.size()];
}


