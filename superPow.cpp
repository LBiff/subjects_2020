// 372. 超级次方
// 你的任务是计算 ab 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。
// 示例 1:
// 输入: a = 2, b = [3]
// 输出: 8
// 示例 2:
// 输入: a = 2, b = [1,0]
// 输出: 1024

// 大幂次求解
// a^(1564) = a^4 * a^(156)^10
// mod运算简化
// (a * b) % k = (a % k)(b % k) % k 对乘法的结果求模，等价于先对每个因子都求模，然后对因子相乘的结果再求模
#include <vector>
using namespace std;

// O(n)
int base = 1337;
// 计算 a 的 k 次方然后与 base 求模的结果
int mypow(int a, int k) 
{
    // 对因子求模
    a %= base;
    int res = 1;
    for (int _ = 0; _ < k; _++) {
        // 这里有乘法，是潜在的溢出点
        res *= a;
        // 对乘法结果求模
        res %= base;
    }
    return res;
}

// mypow再加速， b为奇数 a^b = a * a^(b - 1), b为偶数 a^b = a^(b / 2)^2
int mypow_2(int a, int k) {
    if (k == 0) return 1;
    a %= base;

    if (k % 2 == 1) {
        // k 是奇数
        return (a * mypow(a, k - 1)) % base;
    } else {
        // k 是偶数
        int sub = mypow(a, k / 2);
        return (sub * sub) % base;
    }
}


int superPow(int a, vector<int>& b) 
{
    if (b.empty()) return 1;
    int last = b.back();
    b.pop_back();

    int part1 = mypow(a, last);
    int part2 = mypow(superPow(a, b), 10);
    // 每次乘法都要求模
    return (part1 * part2) % base;
}