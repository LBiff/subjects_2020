// 给定一个01矩阵 M，找到矩阵中最长的连续1线段。这条线段可以是水平的、垂直的、对角线的或者反对角线的。

#include <vector>
using namespace std;

int longestLine(vector<vector<int>>& M) 
{   
    int row_count = M.size();
    int max_len = 0;
    //水平计算
    auto level_cal = [&](const int row) -> int
    {
        if(row >= row_count || row < 0)
        {
            return 0;
        };

        int ret = 0;

        int cur_len = 0;
        for(int col = 0; col < M[row].size(); col++)
        {
            if(M[row][col] == 0)
            {
                ret = max(ret, cur_len);
                cur_len = 0;
            }
            else
            {
                cur_len++;
            }
        };

        ret = max(ret, cur_len);
        return ret;
    };

    //垂直计算
    //斜着计算

}