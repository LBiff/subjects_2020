//  有序矩阵中第K小的元素
// 给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
// 请注意，它是排序后的第 k 小元素，而不是第 k 个不同的元素。

#include <vector>
using namespace std;

// 查找矩阵中小于等于mid的数目
// 从左下角开始搜
int CalLessEquMidNum(vector<vector<int>>& vv, int mid, int n)
{
    int i = n - 1;
    int j = 0;
    int ret = 0;
    while(i >= 0 && j < n)
    {
        if(vv[i][j] <= mid)
        {
            ret += i + 1; //包括ij在内上面的列都小于等于mid
            j++;
        }
        else
        {
            i--; //包括ij在内的右边的行都大于mid
        }
    };

    return ret;
};

// 计算排序后的第k小元素
// 二分搜
int kthSmallest(vector<vector<int>>& matrix, int k) 
{
    int sz = matrix.size();
    if(matrix.empty() || sz*sz < k || k < 1)
    {
        return 0;
    };
    if(sz == 1 && k == 1)
    {
        return matrix[0][0];
    }

    int left = matrix[0][0];
    int right = matrix[sz - 1][sz - 1];
    while(left < right)
    {   
        int mid = left + ((right - left) >> 1);
        int tmp = CalLessEquMidNum(matrix, mid, sz);
        if(tmp >= k)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    };

    return left;
};

int main()
{
    vector<vector<int>> matrix{
    { 1,2},
    {1,3}};
    int k = 4;
    auto ret = kthSmallest(matrix, k);
    return 0;
}