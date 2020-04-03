//不同数等于k的子数组个数
// 给定一个正整数数组 A，如果 A 的某个子数组中不同整数的个数恰好为 K，则称 A 的这个连续、不一定独立的子数组为好子数组。
// （例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。）
// 返回 A 中好子数组的数目。
//Error
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution 
{
public:
int subarraysWithKDistinct(vector<int>& A, int K) 
{
    if(K > A.size())
    {
        return 0;
    };

    //[]闭区间
    int idx_l = 0;
    int idx_r = 0;
    unordered_map<int, int> map; //窗口内<value, count>
    map.insert({A[0], 1});
    int count = 0; 
    //考察当前idx_l和idx_r括起来的闭区间的内容
    while(idx_r < A.size())
    {
        size_t map_size = map.size();
        if(map_size == K)
        {
            cout << idx_l << " " << idx_r <<endl;
            count++;
            //右继续扩
            if(idx_r + 1 < A.size())
            {
                auto iter = map.find(A[idx_r + 1]);
                if(iter != map.end())
                {
                   iter->second++;
                }
                else
                {
                    map.insert({A[idx_r + 1], 1});
                }
                idx_r++;
            }
        }
        // else if (map_size > K) //右边扩到头
        // {
        //     //删除最后一步多扩的一步
        //     auto iter_r= map.find(A[idx_r]);
        //     if(iter_r != map.end())
        //     {
        //          if(iter_r->second == 1)
        //         {
        //             map.erase(A[idx_r]);
        //         }
        //         else
        //         {
        //             iter_r->second--;
        //         }
        //     };
        //     idx_r--;

        //     //尝试左缩
        //     auto iter = map.find(A[idx_l + 1]);
        //     if(iter != map.end())
        //     {
        //         if(iter->second == 1)
        //         {
        //             map.erase(A[idx_l +1]);
        //         }
        //         else
        //         {
        //             iter->second--;
        //         }
        //     };
        //     idx_l++;
        // }
        else if(map_size < K)
        {
            //右扩
            if(idx_r + 1 < A.size())
            {
                auto iter = map.find(A[idx_r + 1]);
                if(iter != map.end())
                {
                    iter->second++;
                }
                else
                {
                    map.insert({A[idx_r + 1], 1});
                }
            }
            idx_r++;
        }
    };

    return count;
}
};

int main()
{
    Solution s;
    vector<int> v{1,2,1,2,3};
    auto ret = s.subarraysWithKDistinct(v,2);
    return 0;
}