// 计算从开始到结束位置的图的最短路径
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;


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


int min_time = 1000000000;

//已经到达cur_idx
void CalShorest(const unordered_map<int, unordered_map<int,int>>& mmp, int cur_idx, int end_idx, 
                int cur_time, unordered_set<int>& bak)
{
    if(cur_idx == end_idx)
    {
        min_time = min(min_time, cur_time);
        return;
    };

    if(bak.find(cur_idx) != bak.end())
    {
        return;
    }
    //选择列表
    auto iter = mmp.find(cur_idx);
    //有从此出发的路径
    if(iter != mmp.end())
    {
        for(auto iter_end = iter->second.begin(); iter_end != iter->second.end(); iter_end++)
        {
            CalShorest(mmp, iter_end->first, end_idx, cur_time + iter_end->second, bak);
            bak.insert(cur_idx);
        }
    }
}


int GetMinTime()
{
    vector<int> in;
    in = GetIntVByLineBySpace();
    int flag_count = in[0];
    int road_count = in[1];
    unordered_map<int, unordered_map<int,int>> mmp;
    while(road_count-- > 0)
    {
        in = GetIntVByLineBySpace();
        auto iter = mmp.find(in[0]);
        
        if(iter != mmp.end())
        {
            iter ->second.insert({in[1],in[2]});
        }
        else
        {
            unordered_map<int,int> tmp;
            tmp.insert({in[1], in[2]});
            mmp.insert({in[0],tmp});
        }
    };


    int end_idx = GetIntVByLineBySpace()[0];

    if(end_idx == 0)
    {
        return 0;
    };
    if(mmp.empty())
    {
        return 0;
    }

    unordered_set<int> bak;
    CalShorest(mmp, 0, end_idx, 0, bak);
    return min_time;

}


int main()
{
    int ret = GetMinTime();
    cout << ret;
    return 0;
}
