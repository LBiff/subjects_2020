// 在无限的整数序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第 n 个数字。
// 注意:
// n 是正数且在32位整数范围内 ( n < 2^31)。

#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

// 规律：
// 1位数有9个，两位数有90个，三位数有900个。。
int findNthDigit(int n) 
{
    //最多8位数
    unsigned long m = 0;
    vector<unsigned long> v(10, 0); //记录每个区间有多少数
    for(int i = 0; i < 10; i++)
    {
        v[i] = (i + 1) * 9 * pow(10, i);
        m += v[i];
        if(m > pow(2, 31))
        {
            break;
        }
    };


    //查看落在哪个区间
    unsigned int total = 0;
    int cur_idx = 0;
    for(int i = 0; i < v.size(); i++)
    {
        total += v[i];
        if(total >= n)
        {
            cur_idx = i;
            break;
        };
    };

    int cur_idx_pre = total - v[cur_idx];
    int num_idx = (n - cur_idx_pre) / (cur_idx + 1); //记录cur_idx位数的第num_idx个数字
    int num = pow(10, cur_idx) + num_idx;
    int num_num_idx = (n - cur_idx_pre) % (cur_idx + 1);
    num_num_idx = cur_idx + 1 - num_num_idx;

    //计算num数字的第num_num_idx个子数字
    int idx = 1;
    int ret = 1;
    int pow_num = pow(10, cur_idx);
    while(idx <= num_num_idx)
    {
        ret = num / pow_num;
        num %= pow_num;
        pow_num /= 10;
        idx++;
    };

    return ret;
};

int main()
{
    auto ret = findNthDigit(10);
    return 0;
}
