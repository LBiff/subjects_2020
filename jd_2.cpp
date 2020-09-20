#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

typedef long long ll; 

//以空格分隔获取一行整数数组
vector<ll> GetllVByLineBySpace()
{
    string s;
    string word;
    vector<ll> v;
    getline(cin,s);
    istringstream record(s);
    while(record >> word)
    {
        v.push_back(atoi(word.c_str()));
    };
    return v;
};

long long max_meili = 0;

void dp(const vector<vector<ll>>& vv, ll cur_idx, ll cur_idx_idx, long long cur_qian, ll cur_meili,const ll& total_qian)
{
    if(cur_idx >= vv.size() || cur_qian > total_qian)
    {
        return;
    };

    max_meili = max(max_meili, cur_meili);

    if(cur_idx_idx < (vv[cur_idx][0] - 1))
    {
        dp(vv, cur_idx, cur_idx_idx + 1, cur_qian, cur_meili, total_qian);
        dp(vv, cur_idx, cur_idx_idx + 1, cur_qian + vv[cur_idx][1], cur_meili + vv[cur_idx][2], total_qian);
    }
    else
    {
        dp(vv, cur_idx + 1, 0, cur_qian, cur_meili, total_qian);
        dp(vv, cur_idx + 1, 0, cur_qian + vv[cur_idx][1], cur_meili + vv[cur_idx][2], total_qian);
    }
};

ll GetMax(const vector<vector<ll>>& vv, ll sz, ll total_qian)
{
    //dp[i][j]表示将前i件物品装进限重为j的背包可以获得的价值
    vector<ll> dp(total_qian + 1, 0);
    //初始化dp[0][0...total_qian] = 0;
    //动态转移 dp[i][j] = max(dp[i-1][j], dp[i - 1][j - w[i]] + v[j])
    int cur_idx = 0;
    int cur_idx_count = vv[0][0];
    int cur_idx_idx = 0;
    for(ll i = 1; i <= sz; i++)
    {
        for(ll j = total_qian; j >= vv[cur_idx][1]; j--)
        {
            dp[j] = max(dp[j], dp[j - vv[cur_idx][1]] + vv[cur_idx][2]);
        };
        if(cur_idx_idx == cur_idx_count - 1)
        {
            cur_idx++;
            if(cur_idx >= vv.size())
            {
                break;
            }
            cur_idx_count = vv[cur_idx][0];
            cur_idx_idx = 0;
        }
        else
        {
            cur_idx_idx++;
        }
    };
    return dp.back();
}


int main()
{
    //数量，单价，魅力值
    vector<vector<ll>> vv;
    auto p1 = GetllVByLineBySpace();
    ll count = p1[0];
    ll total_qian = p1[1];
    ll total_sz = 0;
    while(count-- > 0)
    {
        auto p = GetllVByLineBySpace();
        total_sz += p[0];
        vv.push_back(p);
    };
    auto ret = GetMax(vv,total_sz,total_qian);
    cout << ret;
    return 0;
}