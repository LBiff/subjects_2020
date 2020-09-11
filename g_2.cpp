// 背包问题，收益和重量有可能为负数
#include <vector>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

int max_v = 0;

// vp: 重量， 收益
// cur_idx还没考虑
// vp<动作电量，愉悦度>
void Bag(const vector<pair<double,int>>& vp, int cur_idx, int cur_dianliang, int cur_yuyue)
{
    if(cur_dianliang <= 0 || cur_idx > static_cast<int>(vp.size()) - 1)
    {
        max_v = max(max_v, cur_yuyue);
        return;
    };

    //要
    if(cur_dianliang >= vp[cur_idx].first)
    {
        Bag(vp, cur_idx + 1, cur_dianliang - vp[cur_idx].first, cur_yuyue +  vp[cur_idx].second);
    }
    Bag(vp, cur_idx + 1, cur_dianliang, cur_yuyue);
};

int main()
{
    int dz_count;
    int dl;
    cin >> dz_count >> dl;
    vector<pair<double,int>> vp;
    while(dz_count-- > 0)
    {
        pair<double,int> p;
        cin >> p.first >> p.second;
        vp.push_back(p);
    };
    Bag(vp,0,dl,0);
    cout << max_v;
    return 0;
}