//岛屿问题--
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
        vector<vector<int>> vv{{-1, 0}, {1,0}, {0, -1}, {0, 1}};
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size();j++)
            {
                if(grid[i][j] == 1) //只有是岛屿才统计
                {
                    for(auto xy : vv)
                    {
                        int x_idx = i + xy[0];
                        int y_idx = j + xy[1];
                        if(x_idx >= 0 && x_idx < grid.size() && y_idx >= 0 && y_idx < grid[0].size())
                        {
                            if(grid[x_idx][y_idx] == 0)
                            {
                                ret++;
                            }
                        }
                        else //如果越界还是要统计一条边
                        {
                             ret++;
                        }
                    }
                }

            }
        };
        return ret;
    }
