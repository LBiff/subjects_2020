// 质数（素数）计数
// 统计所有小于非负整数 n 的质数的数量。
// 输入: 10
// 输出: 4
// 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。

#include <vector>
using namespace std;

// 排除法
int countPrimes(int n) 
{
    if(n < 3)
    {
        return 0;
    }
    vector<bool> is_primes(n, true);
    is_primes[0] = false;
    is_primes[1] = false;
    for(int i = 2; i * i < n; i++)
    {
        if(is_primes[i])
        {
            for(int j = i * i; j < n; j += i)
            {
                is_primes[j] = false;
            }
        }
    };

    int count = 0;
    for(auto p : is_primes)
    {
        if(p)
        {
            count++;
        }
    };

    return count;
};

int main()
{
    auto ret = countPrimes(10);
    return 0;
}