//最长回文子序列
#include <string>
#include <vector>
using namespace std;

//dp[i][j]表示s[i...j]内最长回文子序列
int dp(const string& s, int l, int r, vector<vector<int>>& vv)
{
    if(l > r)
    {
        return 0;
    }
    if(l == r)
    {
        return 1;
    };
    if(s[l] == s[r])
    {
        vv[l + 1][r - 1] = vv[l + 1][r - 1] == -1 ? dp(s,l + 1, r - 1, vv) : vv[l + 1][r - 1];
        return vv[l + 1][r - 1] + 2;
    }
    else
    {
        vv[l + 1][r] = vv[l + 1][r] == -1 ? dp(s,l + 1, r, vv) : vv[l + 1][r];
        vv[l][r - 1] = vv[l][r - 1] == -1 ? dp(s,l, r - 1, vv) : vv[l][r - 1];
        return max(vv[l + 1][r], vv[l][r - 1]);
    }
};

int dp_table(const string& s)
{
    //dp[i][j]表示s[i...j]内最长回文子序列
    vector<vector<int>> dp_v(s.length(), vector<int>(s.length(), 0));
    //边界， i==j 为1, i > j == 0
    for(int i = 0; i < s.length(); i++)
    {
        dp_v[i][i] = 1;
    };
    //从下往上从左往右
    for(int row = s.length() - 2; row >= 0; row--)
    {
        for(int col = row + 1; col < s.length(); col++)
        {

            dp_v[row][col] = s[row] == s[col] ? dp_v[row + 1][col - 1] + 2
                                              : max(dp_v[row + 1][col], dp_v[row][col - 1]);
        }
    };
    return dp_v[0][s.length() - 1];
}
int longestPalindromeSubseq(string s) 
{
    vector<vector<int>> vv(s.length(), vector<int>(s.length(), -1));
    return dp(s, 0, s.length() - 1, vv);
};

int main()
{
    auto ret = longestPalindromeSubseq("cbbd");
    return 0;
}