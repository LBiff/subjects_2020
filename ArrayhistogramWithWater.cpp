//数组直方图装水问题
// 给定一个数组,每个位置的值代表一个高度。那么整个数组可以看过是一个直方图。
// 如果把这个直方图当做容器的话,求这个容器能装多少水。例如:
// 3, 1, 2,4
// 代表第一个位置高度为3,
// 第二个位置高度为1,
// 第三个位置高度为2,
// 第四个位置高度为4
// 3,1, 2,4这个数组代表的容器可以装3格的水。

#include <vector>
#include <cstdlib>
#include <cstdint>
using namespace std;

//逐个求解每个位置上的装水量
int trap(vector<int>& height) 
{
    //两侧夹击
    if(height.size() < 3)
    {
        return 0;
    };
    
    // 最左边和最右边是不能装水的
    auto l_iter = height.begin() + 1;  //还没处理的
    auto r_iter = height.end() - 2;
    
    int max_r = height.back();
    int max_l = height[0];
    
    int sum = 0;
    // 左右夹击
    while(l_iter <= r_iter)
    {
        if(max_l > max_r) //右边是瓶颈
        {
            if(*r_iter < max_r)
            {
                sum += max_r - *r_iter;
            }
            else
            {
                max_r = *r_iter;
            }
            r_iter--;
        }
        else //左边是瓶颈
        {
            if(*l_iter < max_l)
            {
                sum += max_l - *l_iter;
            }
            else
            {
                max_l = *l_iter;
            }
            l_iter++;
        }
    };
    return sum;
};


int main()
{
    vector<int> c{0,1,0,2,1,0,1,3,2,1,2,1};
    int a = trap(c);

    return 0;
}