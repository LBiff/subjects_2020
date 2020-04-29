//招商2020
//在一个N层高的金字塔上，以金字塔为第一层，第i层有i个落点，每个落点有若干枚硬币，在落点可以跳向左斜下
//或者右斜下，知道每一层金币分布，求解获得的最多的金币。
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
using namespace std;

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

//已经跳到[cur_level][col]位置处，但是还没有加入最终计算
int dp(const vector<vector<int>> vv, int cur_level, int col, int get, unordered_map<string, int>& map)
{
    if(cur_level == vv.size() - 1)
    {
        return get + vv[cur_level][col];
    };

    string s = to_string(cur_level) + "-" + to_string(col);
    auto iter = map.find(s);
    if(iter != map.end())
    {
        return iter->second;
    };

    int get_l = dp(vv, cur_level + 1, col, get + vv[cur_level][col], map); //选择下一层左边的
    int get_r = dp(vv, cur_level + 1, col + 1, get + vv[cur_level][col], map); //选择下一层右边

    int ret = max(get_l, get_r);
    map.insert({s,ret});
    return  max(get_l, get_r);
}


int GetMax(vector<vector<int>> coins)
{
    unordered_map<string, int> map; //缓存
    return dp(coins, 0,0,0,map);
};

int main()
{
    int row_count = GetIntVByLineBySpace()[0];
    vector<vector<int>> vv;
    while(row_count-- > 0)
    {
        vv.push_back(GetIntVByLineBySpace());
    };
    //vector<vector<int>> coins{{8},{3,8},{8,1,0},{4,7,5,4},{3,5,2,6,5}};
    auto ret = GetMax(vv);
    return 0;
}