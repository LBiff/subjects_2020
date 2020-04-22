//最长公共子序列

#include <string>
#include <vector>
using namespace std;

//dp[i][j]表示s1[0..i] 和 s2[0...j]的最长公共子序列
int dp(const string& s1, const string& s2, int idx_1, int idx_2, vector<vector<int>>& mem)
{
    if(idx_1 == 0 || idx_2 == 0)
    {
        return 0;
    };
    if(s1[idx_1 - 1] == s2[idx_2 - 1])
    {
        mem[idx_1 - 1][idx_2 - 1] = mem[idx_1 - 1][idx_2 - 1] != -1 ? mem[idx_1 - 1][idx_2 - 1]
                                                                    :dp(s1,s2,idx_1 - 1, idx_2 - 1, mem);

        return mem[idx_1 - 1][idx_2 - 1] + 1;
    }
    else
    {
        mem[idx_1 - 1][idx_2] = mem[idx_1 - 1][idx_2] == -1 ? dp(s1,s2,idx_1 - 1, idx_2,mem)
                                                            : mem[idx_1 - 1][idx_2];
        mem[idx_1][idx_2 - 1] = mem[idx_1][idx_2 - 1] == -1 ? dp(s1,s2,idx_1, idx_2 - 1,mem)
                                : mem[idx_1][idx_2 - 1];
        return max(mem[idx_1 - 1][idx_2], dp(s1,s2,idx_1, idx_2 - 1,mem));
    }
};

int longestCommonSubsequence(string s1, string s2) 
{
    //从后往前遍历
    //傻缓存
    vector<vector<int>> mem(s1.length() + 1, vector<int>(s2.length() + 1, -1));
    return dp(s1,s2,s1.length(), s2.length(), mem);
};



