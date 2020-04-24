// 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
// 说明：每次只能向下或者向右移动一步。

#include <vector>
using namespace std;


int minPathSum(vector<vector<int>>& grid) 
{
    if(grid.empty())
    {
        return 0;
    }
    return dp_1(grid, 0,0); 
};

//当前到达的位置还没有统计
int dp_1(const vector<vector<int>>& g, int cur_x, int cur_y)
{
    //边界
    if(cur_x == g.size() - 1 && cur_y == g[0].size() - 1)
    {
        return g[g.size() - 1][g[0].size() - 1];
    }

    int cur_get = g[cur_x][cur_y];
    if(cur_x < g.size() - 1 && cur_y < g[0].size() - 1)
    {
        return cur_get + min(dp_1(g,cur_x, cur_y  + 1) , dp_1(g,cur_x + 1, cur_y)); //向下走
    }
    else if(cur_y < g[0].size() - 1) //只能向右走
    {
        return cur_get + dp_1(g,cur_x, cur_y  + 1); //向右走
    }
    else
    {
        return cur_get + dp_1(g,cur_x + 1, cur_y); //向右走
    }
};

int dp_table(const vector<vector<int>>& g)
{
    int row_count = g.size();
    int col_count = g[0].size();
    int dp[row_count][col_count];
    //Base case
    dp[row_count - 1][col_count - 1] = g[row_count - 1][col_count - 1];
    //最下边
    for(int col = col_count - 2; col >= 0; col--)
    {
        dp[row_count - 1][col] = g[row_count - 1][col] + dp[row_count - 1][col + 1];
    };

    //最右边
    for(int row = row_count - 2; row >= 0; row--)
    {
        dp[row][col_count - 1] = g[row][col_count - 1] + dp[row + 1][col_count - 1];
    };

    //一般位置
    for(int row = row_count -2; row >= 0; row--)
    {
        for(int col = col_count - 2; col >=0; col--)
        {
            dp[row][col] = std::min(g[row][col] + dp[row][col + 1], 
                                    g[row][col] + dp[row +1][col]);
        }
    };

    return dp[0][0];
}

