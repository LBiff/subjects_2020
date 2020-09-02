// 相邻分房子
// 一条街道房子彼此相邻，现在这条街要拆迁，要按户分房子，求总共最少需要分多少套房
// 规则1：每户至少一套
// 规则2：相邻的两户，人数多的家庭分的新房子比人数少的多
// 规则3：人数相同的家庭，分房子数可以不同，不管是否相邻
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
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

// 终极解决： 先去重，重复的全部分1套，剩下的采用相对求解，第一个为1， 比较相邻，最后求最小定义为1
// 过0.8
int main()
{
    auto v = GetIntVByLineBySpace();
    if(v.size() < 2)
    {
        cout << v.size();
        return 0;
    };
    //bool true-表示这个值是绝对值
    vector<pair<int, bool>> vp(v.size(), {0, false});
    vp[0] = {1, false};
    int min_v = 1;
    for(int i = 1; i < v.size(); i++)
    {
        if(v[i] == v[i - 1])
        {
            vp[i] = {1, true};
        }
        else if(v[i] > v[i - 1])
        {
            vp[i] = {vp[i - 1].first + 1, vp[i - 1].second};
        }
        else
        {
            if(vp[i- 1].second)
            {
                if(vp[i- 1].first - 1 < 1)
                {
                    vp[i - 1].first++;
                } 
                vp[i] = {vp[i - 1].first - 1, true};
            }
            else
            {
                vp[i] = {vp[i - 1].first - 1, false};
            }
        }
        min_v = vp[i].second ? min_v : min(min_v, vp[i].first);
    };

    int ret = 0;
    for(auto vp_i : vp)
    {
        if(vp_i.second)
        {
            ret += vp_i.first;
            continue;
        }
        ret += vp_i.first - min_v + 1;
    };

    cout << ret;
    return 0;
}
