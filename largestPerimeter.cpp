// 给定由一些正数（代表长度）组成的数组 A，返回由其中三个长度组成的、面积不为零的三角形的最大周长。
// 如果不能形成任何面积不为零的三角形，返回 0。

#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;


int largestPerimeter(vector<int>& A) 
{
    if(A.size() < 3)
    {
        return 0;
    };

    //从大到小排序
    sort(A.begin(), A.end(),greater<int>());
    for(int i = 0; i < A.size() - 2; i++)
    {
        if(A[i] < A[i + 1] + A[i + 2])
        {
            return A[i] + A[i + 1] +  A[i + 2];
        }
    };
    return 0;
}