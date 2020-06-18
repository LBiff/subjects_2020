//堆箱子
// 堆箱子。给你一堆n个箱子，箱子宽 wi、深 di、高 hi。箱子不能翻转，将箱子堆起来时，
// 下面箱子的宽度、高度和深度必须大于上面的箱子。实现一种方法，搭出最高的一堆箱子。
// 箱堆的高度为每个箱子高度的总和。
// 输入使用数组[wi, di, hi]表示每个箱子。
#include <vector>
#include <algorithm>
using namespace std;

class Comparator
{
public:
//按高度进行排序
    bool operator()(const vector<int>& b1, const vector<int>& b2)
    {
        return b1[2] < b2[2] ? true : false;
    }
};

int pileBox(vector<vector<int>>& box) 
{
    if(box.empty())
    {
        return 0;
    }
    //先按照一个维度进行排序,答案子序列肯定在其中
    sort(box.begin(), box.end(), Comparator());

    //dp[i]表示以box[i]结束的子串的最大高度
    vector<int> dp(box.size(), 0);
    dp[0] = box[0][2];
    int max_ret = dp[0];
    for(int i = 1; i < dp.size(); i++)
    {
        int cur_max = 0;
        for(int j = 0; j < i; j++)
        {
            if(box[j][0] < box[i][0] && 
               box[j][1] < box[i][1] &&
               box[j][2] < box[i][2])
               {
                   cur_max = max(cur_max, dp[j]);
               }
        };
        dp[i] = cur_max + box[i][2];
        max_ret = max(max_ret, dp[i]);
    };

    return max_ret;
};

int main()  
{
    vector<vector<int>> box{{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    auto ret = pileBox(box);
    return 0;
}
