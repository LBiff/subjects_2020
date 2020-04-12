//斐波那契数列问题: 本数是前两个数的和
#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <iostream>
using namespace std;

//暴力递归O(2^N)
int FibonacciSeries_1(uint64_t n)
{
    if(n < 3)
    {
        return n;
    };
    return FibonacciSeries_1(n - 1) + FibonacciSeries_1(n -2);
};

//依次求解 O(N)
int FibonacciSeries_2(uint64_t n)
{
    if(n < 1)
    {
        return 0;
    };
    int res = 1;
    int pre = 1;
    int tmp = 0;
    for(int i = 3; i <= n; i++)
    {
        tmp = res;
        res = res + pre;
        pre = tmp;
    };

    return res;
};
//数学法可以将时间降低至(lgN)
//递归式严格遵循F(n) = F(n - 1) + F(n -2)
//可转换为[F(n), F(n - 1)] = [F(n - 1), F(n - 2)] * [[1,1],[1,0]]
//则后续递推可转换为:
//[F(3), F(2)] = [F(2), F(1)] * [[1,1],[1,0]] = [1,1] * [[1,1],[1,0]] 
//[F(4), F(3)] = [F(3), F(2)] * [[1,1],[1,0]] = [1,1] * [[1,1],[1,0]]^2
//[F(5), F(4)] = [F(4), F(3)] = [1,1] * [[1,1],[1,0]]^3

//则转换为求n次方的问题

//先理解求整数m的n次方的O(lgN)的解法
//n的二进制哪一位是1，则进行累乘
//例如求 8的20次方:
//20的二进制为:10100 则 8^10 = 8^4 * 8^16

//m^power
int MatrixPower_lgN(uint64_t m, uint64_t power)
{
    if(power == 0)
    {
        return 1;
    };
    //二进制位数
    int binary_count = 1;
    int tmp_power = power;
    tmp_power = tmp_power >> 1;
    while(tmp_power)
    {
        tmp_power = tmp_power >> 1;
        binary_count++;
    };

    //位是1的进行累乘
    //整个过程是不断m的平方，遇到1进行结果累乘
    int ret = power & 0x00000001 == 1 ? m : 1; //0位预计算
    int cur = m;
    int p_idx = 1; //二进制位标记
    power = power >> 1;
    while(p_idx < binary_count)
    {
        cur = pow(cur, 2);
        ret = power & 0x00000001 == 1 ? ret * cur : ret;
        p_idx++;
        power = power >> 1;
    };
    
    return ret;
};

//矩阵加速阶乘同整数一样，实质是在进行指数的二进制找1累乘的过程，，矩阵的普通乘法按正常进行

int main()
{
    int p = 0;
    while(p < 10)
    {
        cout << MatrixPower_lgN(3,p++) << endl;
    };

    return 0;
};


//具体应用
//1.台阶问题：一次可以跳2步或者跳1步，则S(N) = S(N - 1) + S(N-2)
//2. 牛生牛，存活牛的问题： 牛3年成熟，所有的牛都不会死 C(N) = C(N-1) + C(N-3)
//   但是递推式是三阶，转换为状态矩阵是三阶 
//   [C_n, C_n-1, C_n-2] = [C_n-1, C_n-2, C_n-3] * [[a,b,c][d,e,f][g,h,i]]
//   矩阵加速乘法可以到)(lgN)


