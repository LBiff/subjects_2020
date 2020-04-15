//岛屿问题--周长
// 给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。
// 网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，
// 但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。

#include <vector>
using namespace std;

//1.岛屿的周长
//如果一个单元岛上下左右哪一边没有岛则贡献那一条边，遍历求解
int islandPerimeter(vector<vector<int>>& grid)
{
    int ret = 0;
    for(int row =0; row < grid.size(); row++)
    {
        for(int col = 0; col < grid[0].size(); col++)
        {
            if(grid[row][col] == 1)
            {
                //上
                ret = ((row > 0 && grid[row - 1][col] != 1) || row == 0) 
                      ? ret + 1
                      : ret;
                //下
                ret = ((row < grid.size() - 1 && grid[row + 1][col] != 1) || row == grid.size() - 1)
                      ? ret + 1 
                      : ret;
                //左
                ret = ((col > 0 && grid[row][col - 1] != 1) || col == 0)
                      ? ret + 1 
                      : ret;
                //右
                ret = ((col < (grid[0].size() - 1) && grid[row][col + 1] != 1) || col == grid[0].size() - 1)
                      ? ret + 1 
                      : ret;
            }
        };
    };
    return ret;
};
