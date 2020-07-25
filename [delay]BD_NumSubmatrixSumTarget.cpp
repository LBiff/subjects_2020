// 给出矩阵 matrix 和目标值 target，返回元素总和等于目标值的非空子矩阵的数量。
// 子矩阵 x1, y1, x2, y2 是满足 x1 <= x <= x2 且 y1 <= y <= y2 的所有单元 matrix[x][y] 的集合。
// 如果 (x1, y1, x2, y2) 和 (x1', y1', x2', y2') 两个子矩阵中部分坐标不同（如：x1 != x1'），
// 那么这两个子矩阵也不同。

#include <vector>
using namespace std;

int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
{
};

int main()
{
    vector<int> a{1,2,3,4};
    a.insert(a.begin() + 1, {5});
    return 0;
}