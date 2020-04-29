// 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
// 返回被除数 dividend 除以除数 divisor 得到的商。
// 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
// 示例 1:
// 输入: dividend = 10, divisor = 3
// 输出: 3
// 解释: 10/3 = truncate(3.33333..) = truncate(3) = 3

#include <cstdlib>
#include <algorithm>
#include <cstdint>
using namespace std;
//Error
int divide(int dividend, int divisor) 
{
    bool is_negative = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) ?
                        true : false;
    //边界                   
    if(dividend == 0)
    {
        return 0;
    }
    else if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
    {
        return INT_MAX;
    }
    else if(dividend == INT_MIN && divisor == INT_MIN)
    {
        return 1;
    }
    else if(dividend == INT_MIN && divisor == 1)
    {
        return INT_MIN;
    }
    else if(divisor == INT_MIN)
    {
        return 0;
    };

    int ret = 0;

    if(dividend == INT_MIN)
    {
        if(divisor < 0)
        {
            dividend -= divisor;
            ret -=1 ;
        }
        else
        {
            dividend += divisor;
            ret +=1 ;
        }
    }
    else if(dividend == INT_MAX)
    {
        if(divisor > 0)
        {
            dividend -= divisor;
            ret +=1 ;
        }
        else
        {
            dividend += divisor;
            ret -=1 ;
        }
    };

    uint32_t a = abs(dividend);
    uint32_t b = abs(divisor);

    while(a >= b)
    {
        int shift = 0;
        while(a >= (b << shift))
        {
            int tmp = b << shift;
            shift++;
        };

        a -= b << (shift - 1);
        
        //溢出检测
        uint32_t tmp_add = 1 << (shift  - 1);
        if(tmp_add > INT_MAX - ret)
        {
            return INT_MAX;
        }
        ret += 1 << (shift  - 1);
    };

    return is_negative ? -ret : ret;
};

int main()
{
    int c = INT_MAX;
    auto a = divide(INT_MAX,1);
    return 0;
}
