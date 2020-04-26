// HUAWEI
// 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

//数学原理 https://leetcode-cn.com/problems/integer-break/solution/343-zheng-shu-chai-fen-tan-xin-by-jyd/

#include <cmath>
using namespace std;

int integerBreak(int n) 
{
    if(n <= 3)
    {
        return n - 1;
    };

    //优先拆分为3，
    int three_count = n / 3;
    int remain = n % 3;
    if(remain == 1)
    {
        return pow(3, three_count - 1) * 4; //3和1拆分为2 * 2
    }
    else if(remain == 2)
    {
        return pow(3, three_count) * remain;
    }
    else
    {
        return pow(3, three_count);
    }
};