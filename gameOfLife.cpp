// 根据 百度百科 ，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。
// 给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态：1 即为活细胞（live），
// 或 0 即为死细胞（dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
// 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
// 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
// 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
// 如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
// 根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，
// 其中细胞的出生和死亡是同时发生的。

#include <vector>
using namespace std;

void gameOfLife(vector<vector<int>>& board) 
{
    auto bak = board;
    vector<pair<int,int>> vp{{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    for(int i = 0; i <board.size(); i++)
    {
        for(int j = 0; j < board[i].size(); j++)
        {
            bool is_active = board[i][j];
            int active_count = 0;
            for(int k = 0; k < vp.size(); k++)
            {
                int cur_x = i + vp[k].first;
                int cur_y = j + vp[k].second;
                if(cur_x >= 0 && cur_x < board.size() && cur_y >= 0 && cur_y < board[i].size() && board[cur_x][cur_y] == 1)
                {
                    active_count++;
                }
            };
            if(is_active)
            {
                if(active_count < 2 || active_count > 3)
                {
                    bak[i][j] = 0;
                }
            }
            else
            {
                if(active_count == 3)
                {
                    bak[i][j] = 1;
                }
            }
        }
    };

    board = bak;
};

int main()
{
    vector<vector<int>> board{
                                {0,1,0},
                                {0,0,1},
                                {1,1,1},
                                {0,0,0}
                            };
    gameOfLife(board);
    return 0;
};