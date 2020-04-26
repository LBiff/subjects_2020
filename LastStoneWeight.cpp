// // 每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
// // 如果 x == y，那么两块石头都会被完全粉碎；
// // 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
// // 最后，最多只会剩下一块石头。返回此石头最小的可能重量。如果没有石头剩下，就返回 0。
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    int lastStoneWeightII(vector<int>& stones) 
    {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int s1 = Select(0,0,sum / 2.0,stones);
        int s2 = sum - s1;
        return abs(s1 - s2);
    };

    //暴力选与不选，选出最接近2分之总重量的组合，
    int Select(int cur_idx, int get_v, double target, const vector<int>& v)
    {
        if(cur_idx > v.size() - 1)
        {
            return get_v;
        };
        int get_push = Select(cur_idx + 1, get_v + v[cur_idx], target, v);
        int get_pop = Select(cur_idx + 1, get_v, target, v);
        return abs(get_push - target) < abs(get_pop - target) ? get_push : get_pop;
    };

    int Select_dp(const vector<int>& v, int target)
    {
        int sum = accumulate(v.begin(), v.end(), 0);
        //row--get_v,  col--cur_idx
        //需要求的是(0,0)
        vector<vector<int>> dp(sum + 1, vector<int>(v.size() + 1, 0));
        //最后一列可知
        for(int row = 0; row <= sum; row++)
        {
            dp[row][v.size()] = row;
        };
        //按列从后往前推
        for(int col = v.size() - 1; col >= 0; col--)
        {
            for(int row = 0; row <= sum; row++)
            {
                if(row + v[col] <= sum)  //越界没必要算
                {
                    int get_push = dp[row + v[col]][col + 1];
                    int get_pop = dp[row][col + 1];
                    dp[row][col] = abs(get_push - target) < abs(get_pop - target) ? get_push : get_pop;
                }
            }
        };
        return dp[0][0];
    }
};

int main()
{
    vector<int> a{2,7,4,1,8,1};
    int sum = accumulate(a.begin(), a.end(), 0);
    double mid = sum / 2.0;
    Solution s;
    auto ret = s.Select(0,0,mid,a); 
    auto ret_2 = s.Select_dp(a,mid);
    return 0;
}