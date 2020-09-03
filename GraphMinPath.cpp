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


int min_length = 1000000000;

//已经到达cur_idx
void CalShorest(const unordered_map<int, unordered_map<int,int>>& mmp, int cur_idx, int end_idx, 
                int cur_length, unordered_set<int>& bak)
{
    if(cur_idx == end_idx)
    {
        min_length = min(min_length, cur_length);
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
            CalShorest(mmp, iter_end->first, end_idx, cur_length + iter_end->second, bak);
            bak.insert(cur_idx);
        }
    }
}


void GetMinRoad()
{
    vector<int> in;
    in = GetIntVByLineBySpace();
    int city_count = in[0];
    int path_count = in[1];
    int quary_count = in[2];
    unordered_map<int, unordered_map<int,int>> mmp; //c1->c2, length
    while(path_count-- > 0)
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

    vector<vector<int>> quarys;
    while(quary_count-- > 0)
    {
        quarys.push_back(GetIntVByLineBySpace());
    }

    unordered_map<string, int> quaryed;
    for(int i = 0; i < quarys.size(); i++)
    {
        string str_tmp = to_string(quarys[i][0]) + "_" + to_string(quarys[i][1]);
        auto iter = quaryed.find(str_tmp);
        if(iter != quaryed.end())
        {
            cout << iter->second << endl;
        }
        else
        {
            min_length = 1000000000;
            unordered_set<int> bak;
            CalShorest(mmp, quarys[i][0], quarys[i][1], 0, bak);
            int min_ret = min_length == 1000000000 ? -1 : min_length;
            cout << min_ret << endl;
            quaryed.insert({str_tmp, min_ret});
        }
        
    }
}


// 5 3 3
// 1 2 1
// 2 3 1
// 3 5 2
// 1 2
// 2 4
// 1 5
int main()
{
    GetMinRoad();
    return 0;
}
