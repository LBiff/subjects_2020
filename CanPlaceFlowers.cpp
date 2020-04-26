//HUAWEI
//假设你有一个很长的花坛，一部分地块种植了花，另一部分却没有。
// 可是，花卉不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
// 给定一个花坛（表示为一个数组包含0和1，其中0表示没种植花，1表示种植了花），和一个数 n 。
// 能否在不打破种植规则的情况下种入 n 朵花？能则返回True，不能则返回False。
#include <vector>
using namespace std;

//直接模拟
bool canPlaceFlowers(vector<int>& flowerbed, int n) 
{
    int total_count = 0;
    flowerbed.insert(flowerbed.begin(), 0);
    flowerbed.push_back(0);
    for(int i = 1; i < flowerbed.size() - 1; i++)
    {
        if(flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
        {
            flowerbed[i] = 1;
            total_count++;
        }
    };
    return total_count >= n;
};

int main()
{
    vector<int> v{1,0,0,0,1};
    auto ret = canPlaceFlowers(v, 1);
    return 0;
}