// 正值下班高峰时期，现有可载客司机数2N人，调度中心将调度相关司机服务A、B两个出行高峰区域。
// 第 i 个司机前往服务A区域可得收入为 income[i][0]，前往服务B区域可得收入为 income[i][1]。
// 返回将每位司机调度完成服务后，所有司机总可得的最高收入金额，要求每个区域都有 N 位司机服务。

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


int max_v = 0;

void diaodu(const vector<vector<int>>& vv, int cur_idx, int a_count, int b_count, int quyu_renshu, int cur_v)
{
    if(cur_idx >= vv.size())
    {
        max_v = max(max_v, cur_v);
        return;
    };
    if(a_count > quyu_renshu || b_count > quyu_renshu)
    {
        return;
    }
    diaodu(vv, cur_idx + 1, a_count + 1, b_count, quyu_renshu, cur_v + vv[cur_idx][0]);
    diaodu(vv, cur_idx + 1, a_count, b_count + 1, quyu_renshu, cur_v + vv[cur_idx][1]);
};


int GetTotal(const vector<vector<int>>& vv)
{
    int sj_sz = vv.size();
    int half_sz = sj_sz / 2;
    diaodu(vv,0,0,0,half_sz,0);
    return max_v;
};


vector<int> GetIntVByLineBySpace()
{
    string s;
    string word;
    vector<int> v;
    getline(cin,s);
    if(s == "#")
    {
        return {};
    }
    istringstream record(s);
    while(record >> word)
    {
        v.push_back(atoi(word.c_str()));
    };
    return v;
};

int main()
{
    vector<vector<int>> vv;
    
    while(1)
    {
        auto ret = GetIntVByLineBySpace();
        if(ret.empty())
        {
            break;
        };
        vv.push_back(ret);
    };

    cout << GetTotal(vv) << endl;
    return 0;

}