//杨辉三角
// 1. 第n行的m个数可表示为 C(n-1，m-1)，即为从n-1个不同元素中取m-1个元素的组合数。 C(n+1,i)=C(n,i)+C(n,i-1)。

// 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。

#include <vector>
using namespace std;

// 如果输入的行数是n(从1计数)， 第一个是1，第i个是 ret(i - 1) * (n - i) / i;
vector<int> getRow(int rowIndex) 
{
    rowIndex++;
    vector<int> ret(rowIndex, 0);
    ret[0] = 1;
    for(int i = 1; i < rowIndex; i++)
    {
        long long int tmp =  ((long long int)ret[i - 1]) * ((long long int)(rowIndex - i)) / i;
        ret[i] = tmp;
    };
    return ret;
}