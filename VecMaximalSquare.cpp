//矩阵的最大的1组成的正方形的面积
#include <vector>
using namespace std;

//动态规划
// 若某格子值为 1 ，则以此为右下角的正方形的、最大边长为：上面的正方形、左面的正方形或左上的正方形中，
// 最小的那个，再加上此格。
// 先来阐述简单共识:
// 若形成正方形（非单 1），以当前为右下角的视角看，则需要：当前格、上、左、左上都是 1
// 可以换个角度：当前格、上、左、左上都不能受 0 的限制，才能成为正方形
int maximalSquare(vector<vector<char>>& matrix) 
{
    if(matrix.empty())
    {
        return 0;
    }
    //dp[i][j]表示以(i,j)为右下角的最大的正方形的边长
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));

    
    //第一行初始化
    dp[0][0] = matrix[0][0] == '1' ? 1 : 0;
    int max_radius = dp[0][0];

    //后面的 dp[i][j] = matrix[i][j] == '1' ? min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) : 0;
}