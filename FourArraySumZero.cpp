// 给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
// 为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。
// 例如:
// 输入:
// A = [ 1, 2]
// B = [-2,-1]
// C = [-1, 2]
// D = [ 0, 2]
// 输出:
// 2
// 解释:
// 两个元组如下:
// 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
// 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0


//思路，两两分组hash<sum, count>, 两个hash查找
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution 
{
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
    {
        unordered_map<int, int> map_AB;
        for(int i = 0; i< A.size(); i++)
        {
            for(int j = 0; j< B.size(); j++)
            {
                int sum = A[i] + B[j];

                auto iter = map_AB.find(sum);
                if(iter != map_AB.end())
                {
                    iter->second++;
                }
                else
                {
                    map_AB.insert({sum, 1});
                }
            }
        };

        unordered_map<int, int> map_CD;
        for(int i = 0; i< C.size(); i++)
        {
            for(int j = 0; j< D.size(); j++)
            {
                int sum = C[i] + D[j];

                auto iter = map_CD.find(sum);
                if(iter != map_CD.end())
                {
                    iter->second++;
                }
                else
                {
                    map_CD.insert({sum, 1});
                }
            }
        };
        int count = 0;
        for(auto iter = map_AB.begin(); iter != map_AB.end(); iter++)
        {
            auto iter_cd = map_CD.find(-(iter->first));
            if(iter_cd != map_CD.end())
            {
                count += (iter->second) * (iter_cd -> second);
            }
        };
        return count;

    }
};

int main()
{
    vector<int> A{1,2};
    vector<int> B{-2,-1};
    vector<int> C{-1,2};
    vector<int> D{0,2};
    Solution s;
    auto a = s.fourSumCount(A,B,C,D);
    return 0;
}