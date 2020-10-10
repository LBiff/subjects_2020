// 在给定的网格中，每个单元格可以有以下三个值之一：
// 值 0 代表空单元格；
// 值 1 代表新鲜橘子；
// 值 2 代表腐烂的橘子。
// 每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。
// 返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。

#include <vector>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) 
{
    int cur_count = 0;

    while(1)
    {
        int new_ori = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j= 0; j< grid[0].size(); j++)
            {
                if(grid[i][j] == 2)
                {
                    //四个方向感染
                    //上
                    if(i > 0 && grid[i - 1][j] == 1)
                    {
                        grid[i - 1][j] = 2;
                    };
                     //下
                    if(i < grid.size() - 1 && grid[i + 1][j] == 1)
                    {
                        grid[i + 1][j] = 2;
                    };
                    //左
                    if(j > 0 && grid[i][j - 1] == 1)
                    {
                        grid[i][j - 1] = 2;
                    };
                    //右
                    if(j < grid[0].size() - 1 && grid[i][j + 1] == 1)
                    {
                        grid[i][j + 1] = 2;
                    }
                }
                else if(grid[i][j] == 1)
                {
                    new_ori++;
                }
            };

        };
        if(new_ori == 0)
        {
            break;
        };
        cur_count++;
    };

    return cur_count;
};

int main()
{
    vector<vector<int>> vv{{2,1,1},{1,1,0},{0,1,1}};
    auto ret = orangesRotting(vv);
    return 0;
}