//岛屿数量问题
//深度遍历，广度遍历，并查集
#include <vector>
#include <unordered_map>
using namespace std;

class Solution 
{
public:
    int numIslands()
    {
       
    };

private:
    void UnionFindSetInit(vector<vector<char>>& grid)
    {
         _grid = grid;
        //各自为政
        for(int i =0; i<_grid.size(); i++)
        {
            for(int j =0; j < _grid[i].size(); j++)
            {
                _represent_map.insert(make_pair(i,j), make_pair(i,j));
                _map_size.insert.insert(make_pair(i,j), 1);
            }
        }
    };


private:
    unordered_map<pair<int, int>, vector<pair<int, int>>> _represent_map; //代表结点
    unordered_map<pair<int,int>, int> _map_size; //代表结点，大小
    vector<vector<char>>& _grid;
};

