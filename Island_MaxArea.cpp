//岛屿的最大面积

#include <vector>
using namespace std;

int maxAreaOfIsland(vector<vector<int>>& grid) 
{
    if(grid.empty())
    {
        return 0;
    }
    int row_size = grid.size();
    int col_size = grid[0].size();
    vector<vector<bool>> is_vistived(row_size, vector<bool>(col_size, false));
    int max_area = 0;
    for(int row = 0; row < row_size;  row++)
    {
        for(int col = 0; col < col_size; col++)
        {
            //没有访问过并且是陆地
            if(!is_vistived[row][col] && grid[row][col] == 1) 
            {
                is_vistived[row][col] = true;
                max_area = max(max_area, dfs_recursion(grid, row, col,is_vistived));
            }
        }
    };

    return max_area;
};

//递归探测标记
int dfs_recursion(const vector<vector<int>>& _grid, const int _row, const int _col, vector<vector<bool>>& _is_vistived)
{
    int ret = 1;
    vector<pair<int,int>> vp{{-1,0},{1,0},{0,-1},{0,1}};
    for(int i = 0; i < 4; i++)
    {
        int row = _row + vp[i].first;
        int col = _col + vp[i].second;
        if(row >= 0  && row < _grid.size() && col >= 0 && col < _grid[0].size())
        {
                if(_grid[row][col] == 1 && !_is_vistived[row][col])
                {
                    ret += 1;
                    _is_vistived[row][col] = true;
                    ret += dfs_recursion(_grid,row,col,_is_vistived);
                }
        }
    };
    return ret;
};