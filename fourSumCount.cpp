// 给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
// 为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，
// 最终结果不会超过 231 - 1 。

#include <vector>
#include <unordered_map>
using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
{
    unordered_map<int,int> mp_1;
    unordered_map<int,int> mp_2;

    auto CalTwoSum = [](const vector<int>& A, const vector<int>& B, unordered_map<int,int>& mp)
    {
        int len = A.size();
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < len; j++)
            {
                auto sum_2 = A[i] + B[j];
                auto iter = mp.find(sum_2);
                if(iter != mp.end())
                {
                    iter->second++;
                }
                else
                {
                    mp.insert({sum_2, 1});
                }
            }
        }
    };

    CalTwoSum(A,B,mp_1);
    CalTwoSum(C,D,mp_2);

    int ret = 0;
    for(auto iter_1 = mp_1.begin(); iter_1 != mp_1.end(); iter_1++)
    {
        auto iter_2 = mp_2.find(-(iter_1->first));
        if(iter_2 != mp_2.end())
        {
            ret += iter_1->second * iter_2->second;
        }
    };

    return ret;
};

int main()
{
    vector<int> A{1,2};
    vector<int> B{-2,-1};
    vector<int> C{-1,2};
    vector<int> D{0,2};

    auto ret = fourSumCount(A,B,C,D);
    return 0;
}