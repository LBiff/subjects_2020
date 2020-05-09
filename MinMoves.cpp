//给定一个长度为 n 的非空整数数组，
// 找到让数组所有元素相等的最小移动次数。每次移动将会使 n - 1 个元素增加 1。

#include <vector>
#include <cstdlib>
using namespace std;

//本题关注的是数字之间的相对大小
//将其他数字+1相当于将该数-1，直到所有的数等于最小数

int minMoves(vector<int>& nums) 
{
    if(nums.empty())
    {
        return 0;
    };
    int min_v = INT_MAX;
    //查找最小数以及除了最小数的其他数的总和
    //注意： sum可能越界，所以分开计算
    for(int i = 0; i<nums.size(); i++)
    {
        min_v = min(min_v,nums[i]);
    };

    int moves = 0;
    for(auto v : nums)
    {
        moves += v - min_v;
    }

    return moves;
};