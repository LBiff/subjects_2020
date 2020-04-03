//给一个数组arr和一个整数aim,求解数组中是否存在数和为aim

#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;

//递归
//[0-i)位置内得到的sum, 求从[i-终点]任意选，加出来的数字可否等于aim
bool GetAimFromArry(vector<int> v, int i, int sum, int aim)
{
    if(sum == aim)
    {
        return true;
    };
    if(i == v.size())
    {
        return false;
    };

    return GetAimFromArry(v, i+1,sum + v[i], aim) || GetAimFromArry(v, i+1,sum, aim);
};


//改动态规划
//递归的状态量 i的[0-i)任意取值得到的sum, dp为二维表
//sum的取值范围 0-v的和,,最后一排可以确定，依次往上推，，求(0,0)
// i/sum  0 ... v_sum
//  0
//  ...
//  N
bool GetAimFromArry_2(vector<uint64_t> v, int aim)
{
    int v_sum = accumulate(v.begin(), v.end(),0);
    if(aim > v_sum)
    {
        return false;
    }
    int dp_row_count = v.size() + 1;
    int dp_col_count = v_sum + 1;
    bool dp[dp_row_count][dp_col_count];
    //最后一排可定
    for(int col = 0; col < dp_col_count; col++)
    {
        dp[dp_row_count - 1][col] = (col == aim) ? true : false;
    };

    //上推以上排
    for(int row = dp_row_count - 2; row >= 0; row--)
    {
        for(int col = 0; col < dp_col_count; col++)
        {
            dp[row][col] = (dp[row + 1][col] || dp[row + 1][col + v[row]]);
        }
    };

    return dp[0][0];
}
int main()
{
    vector<uint64_t> a{1,4,5,12,4,25,4};
    bool b = GetAimFromArry_2(a,3);
    return 0;
}