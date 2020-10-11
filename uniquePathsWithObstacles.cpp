// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
// 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
// 网格中的障碍物和空位置分别用 1 和 0 来表示。

#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
{
    int row_count = obstacleGrid.size();
    int col_count = obstacleGrid[0].size();
    vector<vector<int>> dp(row_count,vector<int>(col_count,0)); //dp[i][j]表示从从dp[0][0]走到dp[i][j]的最小步数
    //转移: dp[i][j] = dp[i - 1][j] + 1 +  dp[i][j - 1]
    //初始化
    dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;

    for(int col = 1; col < col_count; col++)
    {
        dp[0][col] = obstacleGrid[0][col] == 1 ? 0 : dp[0][col - 1];
    };
    for(int row = 1; row < row_count; row++)
    {
        dp[row][0] = obstacleGrid[row][0] == 1 ? 0 : dp[row - 1][0];
    };

    for(int i = 1; i < row_count; i++)
    {
        for(int j= 1; j < col_count; j++)
        {
            if(obstacleGrid[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] += obstacleGrid[i - 1][j] == 1 ? 0 : dp[i - 1][j];
                dp[i][j] += obstacleGrid[i][j - 1] == 1 ? 0 : dp[i][j - 1];
            }
        }
    };
    return dp.back().back();
};

int main()
{
    vector<vector<int>> vv{{0,1}};
    auto ret = uniquePathsWithObstacles(vv);
    return 0;
}
