//n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
// 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
// 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

#include <string>
#include <vector>
using namespace std;


bool isVaild(vector<string> cur_board, int x, int y, int n)
{
    //检查当前行
    for(int col = 0; col < n; col++)
    {
        if(col != y && cur_board[x][col] != '.')
        {
            return false;
        }
    };

    //检查当前列
    for(int row = 0; row < n; row++)
    {
        if(row != x && cur_board[row][y] != '.')
        {
            return false;
        }
    };

    //检查对角线
    int cur_col = y + 1;
    for(int row = x -1; row >= 0 && cur_col < n; row--, cur_col++)
    {
        if(cur_board[row][cur_col] != '.')
        {
            return false;
        }
    };
    cur_col = y - 1;
    for(int row = x + 1; row < n && cur_col >= 0; row++, cur_col--)
    {
        if(cur_board[row][cur_col] != '.')
        {
            return false;
        }
    };
    cur_col = y - 1;
    for(int row = x - 1; row >= 0 && cur_col >= 0; row--, cur_col--)
    {
        if(cur_board[row][cur_col] != '.')
        {
            return false;
        }
    };
    cur_col = y + 1;
    for(int row = x + 1; row < n && cur_col < n; row++, cur_col++)
    {
        if(cur_board[row][cur_col] != '.')
        {
            return false;
        }
    };
    return true;
};
//labuladong回溯模板
//cur_board当前的棋盘状态, cur_row当前处理的行索引
void backTrace(vector<string> cur_board, int cur_row, int n, vector<vector<string>>& ret)
{
    //结束条件
    if(cur_row == n)
    {
        ret.push_back(cur_board);
        return;
    };

    //回溯
    for(int col = 0; col < n; col++)
    {
        //做选择
        cur_board[cur_row][col] = 'Q';
        if(isVaild(cur_board, cur_row, col, n))
        {
            backTrace(cur_board, cur_row + 1, n, ret);
        };
        //撤销选择
        cur_board[cur_row][col] = '.';
    };
}


vector<vector<string>> solveNQueens(int n) 
{
    vector<vector<string>> ret;
    if(n <= 0)
    {
        return ret;
    }
    //初始化棋盘
    string row(n,'.');
    vector<string> cur_board(n,row);
    backTrace(cur_board, 0,n,ret);
    return ret;
};

int main()
{
    auto ret = solveNQueens(4);
    return 0;
}