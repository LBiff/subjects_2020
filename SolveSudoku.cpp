//数独回溯
// 编写一个程序，通过已填充的空格来解决数独问题。
// 一个数独的解法需遵循如下规则：
// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
// 空白格用 '.' 表示。
#include <vector>
using namespace std;
//当前填充的有效性判定
bool CurIsEffective(vector<vector<char>>& board, int x, int y)
{
    if(0 <= x && x < board.size() && y >= 0 && y < board[0].size())
    {
        //行判定
        for(int col = 0; col < board[0].size(); col++)
        {
            if(board[x][col] == board[x][y] && col != y)
            {
                return false;
            }
        }
        //列判定
        for(int row = 0; row < board.size(); row++)
        {
            if(board[row][y] == board[x][y] && row != x)
            {
                return false;
            }
        };

        //块内判定
        int block_most_up_x = (x / 3) * 3; //块内最小行
        int block_most_down_x = block_most_up_x + 2; //块内最小行
        int block_most_left_y = (y / 3) * 3; //块内最小列
        int block_most_right_y = block_most_left_y + 2;
        for(int row = block_most_up_x; row <= block_most_down_x; row++)
        {
            for(int col = block_most_left_y; col <= block_most_right_y; col++)
            {
                if(board[row][col] == board[x][y] && row != x && col != y)
                {
                    return false;
                }
            }
        };
        return true;
    };
    return false;
};


bool dfs(vector<vector<char>>& board, int cur_x, int cur_y)
{
    //去下一行找
    if(cur_y == board[0].size())
    {
        cur_y = 0;
        cur_x++;
    };
    //查找完成
    if(cur_x > board.size() - 1)
    {
        return true;
    };
    //跳过已经解决的点
    if(board[cur_x][cur_y] != '.')
    {
        return dfs(board, cur_x, cur_y + 1);
    };

    //该点没有解决进行解决
    for(char c = '1'; c <= '9'; c++)
    {
        board[cur_x][cur_y] = c;
        if(CurIsEffective(board,cur_x, cur_y) && dfs(board, cur_x, cur_y + 1))
        {
            return true;
        };
        board[cur_x][cur_y] = '.';
    };

    return false;
};


void solveSudoku(vector<vector<char>>& board) 
{
    dfs(board, 0, 0);
};