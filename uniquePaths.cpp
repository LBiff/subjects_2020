// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
// 问总共有多少条不同的路径？

#include <vector>
using namespace std;

int uniquePaths(int m, int n) 
{
    vector<vector<int>> dp(m,vector<int>(n,0)); //dp[i][j]表示从从dp[0][0]走到dp[i][j]的最小步数
    //转移: dp[i][j] = dp[i - 1][j] + 1 +  dp[i][j - 1]
    //初始化
    for(int col = 0; col < n; col++)
    {
        dp[0][col] = 1;
    };
    for(int row = 0; row < m; row++)
    {
        dp[row][0] = 1;
    };

    for(int i = 1; i < m; i++)
    {
        for(int j= 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    };

    return dp.back().back();
}