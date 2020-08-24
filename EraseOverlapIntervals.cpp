//不重叠区间
// 给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
// 注意:
// 可以认为区间的终点总是大于它的起点。
// 区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。

#include <vector>  
#include <algorithm>
#include <stack>
#include <string>
#include <set>
#include <sstream>
#include <iostream>
using namespace std;

//按结束最早进行贪心
int eraseOverlapIntervals(vector<vector<int>>& intervals) 
{
    if(intervals.size() < 2)
    {
        return 0;
    }

    //结束时间升序排
    sort(intervals.begin(), intervals.end(),
    [](const vector<int>& v1, const vector<int>& v2)
    {
        return v1[1] < v2[1] ? true :false;
    });

    int no_overlap_count = 1; //不相交区间的数量
    int end = intervals[0][1];
    for(auto i : intervals)
    {
        int start = i[0];
        if(start >= end)  //找到下一个区间
        {
            no_overlap_count++;
            end = i[1];
        }
    }
    return intervals.size() - no_overlap_count;
};

// [ [1,2], [2,3], [3,4], [1,3] ]


vector<int> GetIntVSpiltByChar(char c, string s)
{
    vector<int> v;
    size_t first_pos = s.find_first_of(c,0);
    v.push_back(atoi(s.substr(0, first_pos).c_str()));
    int pre = first_pos;
    size_t pos =  s.find_first_of(c,pre + 1);
    while(pos != string::npos)
    {
        v.push_back(atoi(s.substr(pre+1, pos-pre -1).c_str()));
        pre = pos;
        pos = s.find_first_of(c,pos + 1);
    };
    v.push_back(atoi(s.substr(pre+1).c_str()));
    return v;   
};


vector<vector<int>>  GetInput(string s)
{
    set<int> del;
    for(int i = 0; i < s.size(); i++)
    {
        int c = s[i];
        if(!((c >= '0' && c <= '9') || c == ','))
        {
            del.insert(i);
        }
    };

    string new_string;
    for(int i = 0; i < s.size(); i++)
    {
        if(del.find(i) == del.end())
        {
            new_string += s[i];
        }
    }

    vector<int> vt = GetIntVSpiltByChar(',', new_string);
    vector<vector<int>> vv;
    for(int i = 0; i < vt.size(); i += 2)
    {
        if(i + 1 < vt.size())
        {
            vv.push_back({vt[i], vt[i+1]});
        }
    };

    return vv;
};

int main()
{
    string s;
    getline(cin, s);
    auto vv = GetInput(s);
    auto ret = eraseOverlapIntervals(vv);
    cout << ret;
    return 0;
}
