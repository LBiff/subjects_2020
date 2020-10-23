#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


// 有一个房间最大容纳max_count人，新人搬进来的概率为in, 在房间的人搬出去的概率为out,
// 拼夕夕第一天搬进来一个人住着，这天没有新搬进来的人，他想一直住live_days天，问这些天里他一个人独居的时间(单位：天)期望值是多少?
// 规则： 
// 1. 当该天房间住满后，第二天不能有新人搬进来，但是第二天可以有人搬出去
// 2. 拼夕夕一直住在里面，不搬
// 3. 前一天不满的情况下第二天可以有人搬出去，可以有一个新人进来

double Get(int max_count, int live_days, double in, double out)
{

    // dp[i][j]表示第i天宿舍有j个人的概率为second
    vector<vector<double>> dp(live_days, vector<double>(max_count + 1));
    dp[0][0] = 0.0;
    dp[0][1] = 1.0;
    //初始化
    for(int i = 2; i < max_count + 1; i++)
    {
        dp[0][i] =0.0;
    };

    for(int day = 1; day < live_days; day++)
    {
        for(int pre = 0; pre < max_count + 1; pre++)
        {
            if(pre == 0)
            {
                dp[day][0] = 0.0; 
                continue;
            };

            double rat = 0.0;
            //没有搬入也没有搬出
            rat += dp[day - 1][pre] * (dp[day - 1][max_count] + (1 - dp[day - 1][max_count]) * (1 - in));

            //搬入一个
            if(pre != 1)
            {
                rat += dp[day - 1][pre - 1] * in;
            }
            //多的人全部搬出的概率
            for(int zt_pre = pre + 1; zt_pre < max_count + 1; zt_pre++)
            {
                rat += pow(out,zt_pre-pre) * dp[day - 1][zt_pre];
            };

            //搬入一个，也有搬出
            double out_rat = 0.0;
            for(int zt_pre = pre; zt_pre < max_count + 1; zt_pre++)
            {
                if(zt_pre - (zt_pre-pre + 1) > 1)
                {
                    out_rat += pow(out,zt_pre-pre + 1) * dp[day - 1][zt_pre];
                };
            };

            rat += out_rat * in;

            dp[day][pre] = rat;
        }
    };

    double ret = 0.0;
    for(int i = 0; i < dp.size(); i++)
    {
        ret += dp[i][1];
    };
    return ret;
};

int main()
{
    int max_count;
    int live_days;
    double in;
    double out;
    cin >> max_count >> live_days >> in >> out;
    auto ret = Get(max_count, live_days, in,out);
    cout << ret;
    return 0;
}