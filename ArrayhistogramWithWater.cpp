//数组直方图装水问题

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
    
    auto l_iter = height.begin() + 1;  //还没处理的
    auto r_iter = height.end() - 2;
    
    int max_r = height.back();
    int max_l = height[0];
    
    int sum = 0;
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