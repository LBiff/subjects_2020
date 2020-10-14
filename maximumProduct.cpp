// 给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。

#include <vector>
#include <queue>
using namespace std;

//thinking_10.14
int maximumProduct(vector<int>& nums) 
{
    priority_queue<int, vector<int>, greater<int>> zs_h; //正数小跟堆
    priority_queue<int, vector<int>, greater<int>> fs_h; //负数小跟堆
    int zero_size = 0; //0的数量

    for(auto n : nums)
    {
        if(n > 0)
        {
            if(zs_h.size() < 3)
            {
                zs_h.push(n);
            }
            else if(zs_h.top() < n)
            {
                zs_h.pop();
                zs_h.push(n);
            }
        }
        else if(n < 0)
        {
            if(fs_h.size() < 3)
            {
                fs_h.push(n);
            }
            else if(fs_h.top() < n)
            {
                fs_h.pop();
                fs_h.push(n);
            }
        }
    }

}