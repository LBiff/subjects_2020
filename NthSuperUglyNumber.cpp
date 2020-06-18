// 超级丑数
// 编写一段程序来查找第 n 个超级丑数。
// 超级丑数是指其所有质因数都是长度为 k 的质数列表 primes 中的正整数。

#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;


//基本原理： 每一个丑数肯定是前面某个丑数的倍数
int nthSuperUglyNumber(int n, vector<int>& primes) 
{
    //升序排
    vector<int> nums(n, 1); //丑数缓存,,第一个肯定1
    vector<int> idxs(primes.size(), 0); //倍数索引
    int cur_idx = 1;
    while(cur_idx < n)
    {
        int min_v = INT_MAX;
        for(int i = 0; i < primes.size(); i++)
        {
            min_v = min(min_v, primes[i] * nums[idxs[i]]);
        };
        nums[cur_idx] = min_v;

        for(int j = 0; j < primes.size(); j++)
        {
            if(primes[j] * nums[idxs[j]] == min_v)
            {
                idxs[j]++;
            }
        };
        cur_idx++;
    };

    return nums.back();
};

int main() 
{
    vector<int> p{2,7,13,19};
    auto ret = nthSuperUglyNumber(12, p);
    return 0;
}