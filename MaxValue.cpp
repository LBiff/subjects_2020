// 礼物的最大价值
// 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
// 你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
// 给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
class Solution 
{
public:
    int maxValue(vector<vector<int>>& grid) 
    {
        if(grid.empty())
        {
            return 0;
        }
        unordered_map<string ,int> mp; //傻缓存
        return dp(0,0,grid.size() - 1, grid[0].size() - 1, 0, mp, grid);
    };

    //定义：当前来到<x,y>,[<0,0>,<x,y>)的所获得的为cur_value,
    // 计算在当前来打<x,y>的情况下走到<end_x, end_y>所能获得的最大价值
    int dp(int x, int y, int end_x, int end_y, int cur_value,
            unordered_map<string ,int>& mp, const vector<vector<int>>& grid)
    {
        if(x == end_x && y == end_y)
        {
            return cur_value + grid[x][y];
        };
        //max_v表示[<x,y>,<end_x,end_y>]的最大
        int max_v = 0;
        bool can_right = y < end_y;
        bool can_down = x < end_x;
        if(can_right)
        {
            auto iter_r = mp.find(to_string(x) + "_" + to_string(y + 1));
            int max_r = 0;
            if(iter_r != mp.end())
            {
                max_r = iter_r->second;
            }
            else
            {
                max_r = dp(x, y + 1, end_x, end_y, cur_value + grid[x][y], mp, grid);
                mp.insert({to_string(x) + "_" + to_string(y + 1), max_r});
            }
            max_v = max(max_v, max_r);
        };
        if(can_down)
        {
            auto iter_d = mp.find(to_string(x + 1) + "_" + to_string(y));
            int max_d = 0;
            if(iter_d != mp.end())
            {
                max_d = iter_d->second;
            }
            else
            {
                max_d = dp(x + 1, y, end_x, end_y, cur_value + grid[x][y], mp, grid);
                mp.insert({to_string(x + 1) + "_" + to_string(y), max_d});
            }
            max_v = max(max_v, max_d);
        };
        return max_v;
    };
};