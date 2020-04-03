//行和列都升序排好序的矩阵(N*M)找数，要求时间复杂度O(N+M),空间复杂度O(1)
//解：根据排好序这一点排除数，从右上角找起,右上角两条路可走

#include <vector>
#include <iostream>
using namespace std;


// 0 1 2 5
// 2 3 4 7
// 4 4 4 8
// 5 7 7 9  从右上角找起（或者左下）
pair<int, int> FindFromSortedMatrix(const vector<vector<int>>& vec, 
                          int row_count, int col_count, int num)
{
    int row = 0;
    int col = col_count - 1;
    while(row < row_count && col >= 0)
    {
        if(vec[row][col] == num)
        {
            return make_pair(row,col);
        }
        else if(vec[row][col] < num)
        {
            col--;
        }
        else
        {
            row++;
        }
    };

    return make_pair(-1,-1);
};


int main()
{
    vector<vector<int>> vec{{0,1,2,5},{2,3,4,7},{4,4,4,8},{5,7,7,9}};
    auto a = FindFromSortedMatrix(vec, 4, 4, 6);
    auto b = FindFromSortedMatrix(vec, 4, 4, 5);
}