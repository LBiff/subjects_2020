// 请在 n × n 的棋盘上，实现一个判定井字棋（Tic-Tac-Toe）胜负的神器，判断每一次玩家落子后，是否有胜出的玩家。
// 在这个井字棋游戏中，会有 2 名玩家，他们将轮流在棋盘上放置自己的棋子。
// 在实现这个判定器的过程中，你可以假设以下这些规则一定成立：
//       1. 每一步棋都是在棋盘内的，并且只能被放置在一个空的格子里；
//       2. 一旦游戏中有一名玩家胜出的话，游戏将不能再继续；
//       3. 一个玩家如果在同一行、同一列或者同一斜对角线上都放置了自己的棋子，那么他便获得胜利。
// 给定棋盘边长 n = 3, 玩家 1 的棋子符号是 "X"，玩家 2 的棋子符号是 "O"。

#include <string>
#include <vector>
using namespace std;

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : cur_n(n)
    {
        vs_h.resize(n);
        vs_v.resize(n);

        string s;
        for(int j = 0; j <n; j++)
        {
            s += '#';
        };

        for(int i = 0; i < n; i++)
        {
            vs_h[i] = s;
            vs_v[i] = s;
        };
        lu_rd = s;
        ld_ru = s;


        for(int i = 0; i < n; i++)
        {
            x_win += 'X';
            o_win += 'O';
        }
    };
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) 
    {
        char c = player == 1 ? 'X' : 'O';
        vs_h[row][col] = c;
        vs_v[col][row] = c;
        if(row == col)
        {
            lu_rd[col] = c;
        };
        if(row + col == cur_n - 1)
        {
            ld_ru[col] = c;
        };

        string& win_s = player == 1 ? x_win : o_win;
        if(vs_h[row] == win_s || vs_v[col] == win_s || lu_rd == win_s || ld_ru == win_s)
        {
            return player;
        }
        else
        {
            return 0;
        }
    };

private:
    vector<string> vs_h; //横向
    vector<string> vs_v; //纵向存储
    string lu_rd; //左上到右下的对角线
    string ld_ru; //左下到右上的对角线
    int cur_n;
    string x_win;
    string o_win;
};