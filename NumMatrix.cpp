// 二维区域和检索 - 矩阵不可变
// 给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2)。
// 计算子矩阵范围内和

//方法一： 计算每一行的累加和，进行逐行累加
//方法二：计算二维累加和，位置(i,j)相对(0,0)的累加和

#include <vector>
using namespace std;

class NumMatrix 
{
public:
    NumMatrix(vector<vector<int>>& matrix) 
    : sum_ij(matrix.size() + 1, vector<int>(matrix.empty() ? 0 :  matrix[0].size() + 1, 0))
    {
        //计算二维累加和
        for(int row = 1; row < sum_ij.size(); row++)
        {
            for(int col = 1; col < sum_ij[0].size(); col++)
            {
                sum_ij[row][col] = sum_ij[row - 1][col] + sum_ij[row][col - 1] -
                                   sum_ij[row - 1][col - 1] + matrix[row - 1][col - 1];
            }
        }
    };
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        return sum_ij[row2 + 1][col2 + 1] - sum_ij[row2 + 1][col1] - 
               sum_ij[row1][col2 + 1] + sum_ij[row1][col1];
    };

    vector<vector<int>> sum_ij;
};

int main()
{
    vector<vector<int>> matrix{
  {3, 0, 1, 4, 2},
  {5, 6, 3, 2, 1},
  {1, 2, 0, 1, 5},
  {4, 1, 0, 1, 7},
  {1, 0, 3, 0, 5}
};
    NumMatrix m(matrix);
    return 0;

}