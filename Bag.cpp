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
void Bag(const vector<pair<int,int>>& vp, int cur_idx, int cur_size, int cur_v, const int& bag_size)
{
    if(cur_size > bag_size)
    {
        return;
    };
    if(cur_idx > static_cast<int>(vp.size()) - 1)
    {
        max_v = max(max_v, cur_v);
        return;
    };
    max_v = max(max_v, cur_v);

    Bag(vp, cur_idx + 1, cur_size + vp[cur_idx].first, cur_v +  vp[cur_idx].second, bag_size);
    Bag(vp, cur_idx + 1, cur_size, cur_v, bag_size);
};

//以空格分隔获取一行整数数组
vector<int> GetIntVByLineBySpace()
{
    string s;
    string word;
    vector<int> v;
    getline(cin,s);
    istringstream record(s);
    while(record >> word)
    {
        v.push_back(atoi(word.c_str()));
    };
    return v;
};

int main()
{
    auto p1 = GetIntVByLineBySpace();
    int count = p1[0];
    int bag_size = p1[1];
    vector<pair<int,int>> vp;
    while(count-- > 0)
    {
        auto p1 = GetIntVByLineBySpace();
        vp.push_back({p1[0], p1[1]});
    };

    auto ret = GetMax(vp, bag_size);
    cout << max_v;
    return 0;
}

// 4 4
// -1 -1
// 1 -1
// -1 1
// 6 6