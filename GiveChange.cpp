//【字节】找零钱问题
// Z国的货币系统包含面值1元、4元、16元、64元共计4种硬币，以及面值1024元的纸币。
// 现在小Y使用1024元的纸币购买了一件价值为的商品，请问最少他会收到多少硬币？

#include <iostream>
using namespace std;
int main()
{
    int cost;
    cin >> cost;
    int ret = 0;
    int diff = 1024 - cost;
    int cash[4]{64,16,4,1};
    int idx = 0;
    while(diff > 0)
    {
        int get_count = diff / cash[idx];
        ret += get_count;
        diff -= get_count * cash[idx];
        idx++;
    };
    cout << ret << endl;
    return 0;
}