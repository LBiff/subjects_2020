//岛屿问题： 统计封闭岛屿的数量
// 有一个二维矩阵 grid ，每个位置要么是陆地（记号为 0 ）要么是水域（记号为 1 ）。
// 我们从一块陆地出发，每次可以往上下左右 4 个方向相邻区域走，能走到的所有陆地区域，
// 如果一座岛屿 完全 由水域包围，即陆地边缘上下左右所有相邻区域都是水域，那么我们将其称为
// 请返回封闭岛屿的数目。
#include <vector>
#include <stack>
using namespace std;

int dfs(vector<vector<int>>& _grid, int _row, int _col)
{
    //从当前深搜遇到边界说明不是封闭
    if(_row < 0 || _row >= _grid.size() || _col < 0 || _col >= _grid[0].size() )
    {
        return 0;
    };
    //如果碰到水域说明【可能】是一个封闭岛屿
    if(_grid[_row][_col] == 1)
    {
        return 1;
    }
    else  //陆地
    {
        //先行标记表示已经搜索过
        _grid[_row][_col] = 1;
        int ret = 1;
        vector<pair<int,int>> vp{{-1,0},{1,0},{0,-1},{0,1}};
        for(int i = 0; i < 4; i++)
        {
            ret = min(dfs(_grid, _row + vp[i].first, _col + vp[i].second), ret);
        };

        return ret;
    }
};

int dfs(vector<vector<int>>& _grid, int _row, int _col)
{
    //从当前深搜遇到边界说明不是封闭
    if(_row < 0 || _row >= _grid.size() || _col < 0 || _col >= _grid[0].size() )
    {
        return 0;
    };
    //如果碰到水域说明【可能】是一个封闭岛屿
    if(_grid[_row][_col] == 1)
    {
        return 1;
    }
    else  //陆地
    {
        //先行标记表示已经搜索过
        _grid[_row][_col] = 1;
        int ret = 1;
        vector<pair<int,int>> vp{{-1,0},{1,0},{0,-1},{0,1}};
        for(int i = 0; i < 4; i++)
        {
            ret = min(dfs(_grid, _row + vp[i].first, _col + vp[i].second), ret);
        };

        return ret;
    }
};

//非递归版本
//dfs的非递归版本用栈
int dfs_no_recursion(vector<vector<int>>& grid, int row, int col)
{
    if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
    {
        return 0;
    };

    stack<pair<int,int>> s;
    s.push({row,col});
    int ret = 1;
    while(!s.empty())
    {
        auto top = s.top();
        s.pop();

        //对遍历到的进行校验
        int row = top.first;
        int col = top.second;
        //从当前深搜遇到边界说明不是封闭
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() )
        {
           ret = min(0,ret);
        }
        //如果碰到水域说明【可能】是一个封闭岛屿
        else if(grid[row][col] == 1)    
        {
            ret =min(1,ret);
        }
        else  //陆地
        {
            //先行标记表示已经搜索过
            grid[row][col] = 1;
            vector<pair<int,int>> vp{{-1,0},{1,0},{0,-1},{0,1}};
            for(int i = 0; i< 4; i++)
            {
                s.push({row + vp[i].first, col + vp[i].second});
            }
        }
    };

    return ret;
};

int closedIsland(vector<vector<int>>& grid) 
{
    if(grid.empty())
    {
        return 0;
    };

    int row_count = grid.size();
    int col_count = grid[0].size();
    int total = 0;
    for(int row = 0; row < row_count; row++)
    {
        for(int col = 0; col < col_count; col++)
        {
            if(grid[row][col] == 0)
            {
                total += dfs_no_recursion(grid,row,col);
            }
        }
    };

    return total;
};



