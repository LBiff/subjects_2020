//最短路径和问题
//二维数组最短路径和：正二维数组，从左上到右下，每次只能向右或者向下，求最短路径和

#include <stdexcept>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <numeric>

using namespace std;

//递归求解
//求解从s_row,s_col到右下角的最短路径

uint64_t GetMinRouteSum_2(const vector<vector<uint64_t>>& vv, uint64_t s_row, uint64_t s_col,
                        uint64_t row_count, uint64_t col_count)
{
    if(s_row == row_count - 1 && s_col == col_count - 1)  //到达右下角
    {
        cout << vv[s_row][s_col] << endl;
        return vv[s_row][s_col];
    };

    if(s_row == row_count - 1)  //行到达边界,只能向右走
    {
        return vv[s_row][s_col] + GetMinRouteSum_2(vv,s_row, s_col+ 1, row_count, col_count);
    }
    if(s_col == col_count - 1)  //列到达右边界，只能向下走
    {
        return vv[s_row][s_col] + GetMinRouteSum_2(vv,s_row+1, s_col, row_count, col_count);
    }
    
   return vv[s_row][s_col] + std::min(GetMinRouteSum_2(vv,s_row, s_col+ 1, row_count, col_count),
                        GetMinRouteSum_2(vv,s_row+1, s_col, row_count, col_count));
}


//动态规划的过程就是递归解空间填写的过程
uint64_t GetMinRouteSum_3(const vector<vector<uint64_t>>& vv, uint64_t s_row, uint64_t s_col,
                        uint64_t row_count, uint64_t col_count)
{
    uint64_t dp[row_count][col_count];
    //Basecase
    dp[row_count - 1][col_count - 1] = vv[row_count - 1][col_count - 1];
    //最下边
    for(int col = col_count - 2; col >= 0; col--)
    {
        dp[row_count - 1][col] = vv[row_count - 1][col] + dp[row_count - 1][col + 1];
    };

    //最右边
    for(int row = row_count - 2; row >= 0; row--)
    {
        dp[row][col_count - 1] = vv[row][col_count - 1] + dp[row + 1][col_count - 1];
    };

    //一般位置
    for(int row = row_count -2; row >= 0; row--)
    {
        for(int col = col_count - 2; col >=0; col--)
        {
            dp[row][col] = std::min(vv[row][col] + dp[row][col + 1], 
                                    vv[row][col] + dp[row +1][col]);
        }
    };

    return dp[0][0];
    
    

}

int main()
{
    //1 3 2    8 9 6
    //0 3 4    7 7 4
    //5 7 0   12 7 0
    vector<vector<uint64_t>> a{{1,3,2}, {0, 3, 4},{5, 7, 0}};
    auto b = GetMinRouteSum_3(a, 0, 0, 3,3);
    return 0;

} 