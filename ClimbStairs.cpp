//爬楼梯
// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
#include <vector>
using namespace std;

//纯数学方法，组合问题， 在1里面扔几个2的问题可以表示为，在总共的格子里选1个数目和，2随后放入空
int climbStairs_Error(int n) 
{
    int ret = 0;
    int two_count = n / 2; //2个总数
    
    vector<int> c_v(n + 1,1); //阶乘
    int c = 1;
    for(int i =1; i <= n; i++)
    {
        c *= i;
        c_v[i] = c;
    }
    
    //i--2的数量
    for(int i = 0;i<= two_count; i++)
    {
        int one_count = n - 2 * i; //1的数目
        int total_count = n - i;
        ret += (c_v[total_count] / (c_v[total_count - one_count] * c_v[one_count]));
    };
    
    return ret;
};

//本题动态规划
//1,2开始的斐波那契数列
int climbStairs(int n) 
{
    if(n == 1)
    {
        return 1;
    }
    int dp[n + 1]; //每到达一级都可以从前一级加1或前前+2获得
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i < n + 1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main()
{

}