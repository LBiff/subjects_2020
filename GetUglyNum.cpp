//丑数问题：规定1是丑数， 其他的数如果只含有2或3或5的因子， 那么这个数也是丑数。
//比如依次的丑数为： 1,2,3,4,5,6,8,9,10,12,15...,求第n个丑数
#include <cassert>
#include <algorithm>
#include <iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
//判断丑数
    bool isUgly(int num) 
    {
        if(num < 1)
        {
            return false;
        };
        if(num == 1)
        {
            return true;
        };

        //依次把 2,3,5因子拿掉
        while(num % 2 == 0)
        {
            num /= 2;
        };
        while(num % 3 == 0)
        {
            num /= 3;
        };
        while(num % 5 == 0)
        {
            num /= 5;
        };

        return num == 1 ? true : false;
        
    };

//输出第n个丑数
//基本原理：第n个丑数肯定是前面某个丑数的2或3或5倍
    long GetNthUglyNum(int n)
    {
        int cur_idx = 1; //当前丑数索引
        vector<int> help(n,1);  //丑数集
        //2,3,5倍因子所指的索引
        int idx_2 = 0;
        int idx_3 = 0;
        int idx_5 = 0;

        while(cur_idx < n)
        {
            help[cur_idx] = std::min(help[idx_2] * 2, std::min(help[idx_3] * 3, help[idx_5] * 5));
            //注意不是if_else关系，可能同时移动
            if(help[idx_2] * 2 == help[cur_idx])
            {
                idx_2++;
            }
            if(help[idx_3] * 3 == help[cur_idx])
            {
                idx_3++;
            }
            if(help[idx_5] * 5 == help[cur_idx])
            {
                idx_5++;
            }
            cur_idx++;
        };
        return help[n - 1];
    }
};


int main()
{
    Solution s;
    s.GetNthUglyNum(11);
    return 0;
}