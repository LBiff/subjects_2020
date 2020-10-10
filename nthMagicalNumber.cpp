// 如果正整数可以被 A 或 B 整除，那么它是神奇的。
// 返回第 N 个神奇数字。由于答案可能非常大，返回它模 10^9 + 7 的结果。
#include <algorithm>
using namespace std;

int MOD =  1e9 + 7;

int nthMagicalNumber(int N, int A, int B) 
{
    if((MOD / max(A,B)) * 2 < N)
    {
        int cur_count = MOD / max(A,B) * 2;
        int cur_value = cur_count * max(A, B);
        
        bool is_fir = true;
        
        while(cur_count != N)
        {
            cur_value *= 
        }

    }
    else
    {
        if(N % 2 == 0)
        {
            return (N / 2 * max(A, B)) % MOD;
        }
        else
        {
            return ((N / 2 + 1) * min(A, B)) % MOD;
        }
    }
    
 
}