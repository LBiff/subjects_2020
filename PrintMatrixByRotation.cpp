//转圈打印矩阵
//花式打印矩阵数组等问题，不要陷入局部的坐标变换一次性打印，观察整体规律,
//寻找组件（矩形)
//矩阵转置后上下翻转即逆时针旋转90度
//矩阵上下翻转后转置即瞬时真旋转90度

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

//螺旋打印，即矩形打印
vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    vector<int> ret;
    if(matrix.empty())
    {
        return ret;
    }
    //打印矩形
    auto PrintRetangle = [&](int lu_x, int lu_y, int rd_x, int rd_y)
    {
        if(lu_x <= rd_x && lu_y <= rd_y 
            && 0 <= lu_x  && rd_x < matrix.size()
            && 0 <= lu_y  && rd_y < matrix[0].size())
        {
            //不用while循环，正常打印，不出错，容易看
            for(int y = lu_y; y <= rd_y; y++)
            {
                ret.push_back(matrix[lu_x][y]);
            };
            
            if(rd_x > lu_x)  //列拉开！！！！！！！！！！！！！！
            {
                for(int x = lu_x + 1; x <= rd_x; x++)
                {
                    ret.push_back(matrix[x][rd_y]);
                };
            }
            else
            {
                return;
            }
            
            if(rd_y > lu_y) //行拉开！！！！！！！！！！！！！！！！！！！
            {
                for(int y = rd_y - 1; y >= lu_y; y--)
                {
                    ret.push_back(matrix[rd_x][y]);
                };
            }
            else
            {
                return;
            };

            for(int x = rd_x - 1; x > lu_x; x--)
            {
                ret.push_back(matrix[x][lu_y]);
            };
        }
    };
    
    
    int lu_x = 0;
    int lu_y = 0;
    int rd_x = matrix.size() -1;
    int rd_y = matrix[0].size() - 1;
    while(lu_x <= rd_x && lu_y <= rd_y)
    {
        PrintRetangle(lu_x,lu_y, rd_x,rd_y);
        lu_x++;
        lu_y++;
        rd_x--;
        rd_y--;
    };
    
    return ret;
}

// "之"字形打印
// 聚焦全局，寻找组件(对角线)
//打印对角线　左下到右上
void PrintLevel(const vector<vector<int>>& vec, const uint64_t ld_row, const uint64_t ld_col, 
                const uint64_t ru_row, const uint64_t ru_col, const bool ld_to_ru)
{
    assert(ld_row >= ru_row && ld_col <= ru_col);
    //左下到右上打印
    if(ld_to_ru)
    {
        uint64_t ld_row_tmp = ld_row;
        uint64_t ld_col_tmp = ld_col;
        while(ld_row_tmp >= ru_row && ld_col_tmp <= ru_col)
        {
            cout << vec[ld_row_tmp][ld_col_tmp] << " ";
            ld_row_tmp--;
            ld_col_tmp++;
        }
    }
    else  //右上到左下打印
    {
        uint64_t ru_row_tmp = ru_row;
        uint64_t ru_col_tmp = ru_col;
        while(ru_row_tmp <= ld_row && ru_col_tmp >= ld_col)
        {
            cout << vec[ru_row_tmp][ru_col_tmp] << " ";
            ru_row_tmp++;
            ru_col_tmp--;
        }
    };
    cout << endl;
};

void PrintZhiMatrix(const vector<vector<int>>& vec, uint64_t row_count, uint64_t col_count)
{
    uint64_t ld_row = 0;
    uint64_t ld_col = 0;
    uint64_t ru_row = 0;
    uint64_t ru_col = 0;
    
    bool ld_to_ru = true;
    while(ld_row >= ru_row && ld_col <= ru_col)
    {
        PrintLevel(vec,ld_row,ld_col, ru_row, ru_col,ld_to_ru);
        ld_to_ru = !ld_to_ru;
        ld_row + 1 > row_count - 1 ? ld_col++ : ld_row++;
        ru_col + 1 > col_count - 1 ? ru_row++ : ru_col++;
    }
}




int main()
{
    //1  2  3  4
    //5  6  7  8
    //9  10 11 12
    //13 14 15 16
    vector<vector<int>> m{{7},{9},{6}};
    // PrintMatrixByRotaion(m, 4,4);
    auto a = spiralOrder(m);
    return 0;
}