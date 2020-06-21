// //旋转矩阵
// 给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。
// 不占用额外内存空间能否做到？
// 给定 matrix = 
// [
//   [1,2,3],
//   [4,5,6],
//   [7,8,9]
// ],
// 原地旋转输入矩阵，使其变为:
// [
//   [7,4,1],
//   [8,5,2],
//   [9,6,3]
// ]

#include <vector>
using namespace std;

//顺时针旋转，先转置后左右列调换
void rotate(vector<vector<int>>& matrix) 
{
    auto swap_bit = [](int& i1, int& i2)
    {
        if(i1 == i2)
        {
            return;
        };
        i1 = i1 ^ i2;
        i2 = i1 ^ i2;
        i1 = i1 ^ i2;
    };

    //转置
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < i; j++)
        {
            swap_bit(matrix[i][j], matrix[j][i]);
        }
    };

    //左右交换
    for(int col = 0; col < matrix[0].size() / 2; col++)
    {
        for(int row = 0; row < matrix.size(); row++)
        {
            swap_bit(matrix[row][col], matrix[row][matrix[0].size() - 1 - col]);
        }
    }
};

int main()
{
    vector<vector<int>> vv{
    { 5, 1, 9,11},
    { 2, 4, 8,10},
    {13, 3, 6, 7},
    {15,14,12,16}
    };

    rotate(vv);
    return 0;

// 原地旋转输入矩阵，使其变为:
// [
//   [15,13, 2, 5],
//   [14, 3, 4, 1],
//   [12, 6, 8, 9],
//   [16, 7,10,11]
// ]

}