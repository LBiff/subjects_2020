//岛屿问题-数量

#include <vector>
using namespace std;

//dfs
class IslanCountDfs
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        if(grid.empty())
        {
            return 0;
        }
        int row_size = grid.size();
        int col_size = grid[0].size();
        vector<vector<bool>> is_vistived(row_size, vector<bool>(col_size, false));
        int total = 0;
        for(int row = 0; row < row_size;  row++)
        {
            for(int col = 0; col < col_size; col++)
            {
                //没有访问过并且是陆地
                if(!is_vistived[row][col] && grid[row][col] == '1') 
                {
                    total++;
                    is_vistived[row][col] = true;
                    dfs_recursion(grid, row, col,is_vistived);
                }
            }
        };

        return total;
    };

    //递归探测标记
    void dfs_recursion(const vector<vector<char>>& _grid, const int _row, const int _col, vector<vector<bool>>& _is_vistived)
    {
        vector<pair<int,int>> vp{{-1,0},{1,0},{0,-1},{0,1}};
        for(int i = 0; i < 4; i++)
        {
            int row = _row + vp[i].first;
            int col = _col + vp[i].second;
            if(row >= 0  && row < _grid.size() && col >= 0 && col < _grid[0].size())
            {
                 if(_grid[row][col] == '1' && !_is_vistived[row][col])
                 {
                    _is_vistived[row][col] = true;
                    dfs_recursion(_grid,row,col,_is_vistived);
                 }
            }
        }
    };
};
class UnionFind 
{
public:
  UnionFind(vector<vector<char>>& grid) : count(0)
  {
    int row_count = grid.size();
    int col_count = grid[0].size();
    //初始化，岛屿代表结点是自己，水的代表结点-1
    for (int row = 0; row < row_count; row++) 
    {
        for (int col = 0; col < col_count; col++) 
        {
            if (grid[row][col] == '1') 
            {
                represent_node.push_back(row * col_count + col);
                ++count;
            }
            else 
            {
                represent_node.push_back(-1);
            };
            group_size.push_back(1);
        }
    }
  };

  int find(int i) 
  { //链的打平操作
    if (represent_node[i] != i) 
    {
        represent_node[i] = find(represent_node[i]);
    }
    return represent_node[i];
  }

  void Union(int x, int y) 
  { // union with group_size
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty) 
    {
        if(group_size[rootx] >= group_size[rooty]) 
        {
            represent_node[rooty] = rootx;
            group_size[rootx] += group_size[rooty];
            group_size[rooty] = 0;
        }
        else
        {
            represent_node[rootx] = rooty;
            group_size[rooty] += group_size[rootx];
            group_size[rootx] = 0;
        }
        --count;
    }
  }

  int getCount() const 
  {
    return count;
  }

private:
  vector<int> represent_node;
  vector<int> group_size; //只有代表结点有效
  int count; // #岛屿数量
};

class Solution 
{
public:
  int numIslands(vector<vector<char>>& grid) 
  {
      //边界
    if (grid.empty())
    {
        return 0;
    };

    int row_count = grid.size();
    int col_count = grid[0].size();

    UnionFind uf (grid);
    int num_islands = 0;
    for (int row = 0; row < row_count; row++) 
    {
      for (int col = 0; col < col_count; col++) 
      {
        if (grid[row][col] == '1') 
        {
          grid[row][col] = '0'; //标记被访问过
          //上下左右合并,可只进行右下的合并
          //if (row - 1 >= 0 && grid[row-1][col] == '1') uf.Union(row * col_count + col, (row-1) * col_count + col);
          if (row + 1 < row_count && grid[row+1][col] == '1') uf.Union(row * col_count + col, (row+1) * col_count + col);
          //if (col - 1 >= 0 && grid[row][col-1] == '1') uf.Union(row * col_count + col, row * col_count + col - 1);
          if (col + 1 < col_count && grid[row][col+1] == '1') uf.Union(row * col_count + col, row * col_count + col + 1);
        }
      }
    }
    return uf.getCount();
  }
};
