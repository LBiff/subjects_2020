// 回文子串 [l,r]内最少拆分多少个

#include <string>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

int min_idx = 1000000000;

bool isRight(const string& s)
{
    if(s.empty())
    {
        return false;
    }
    int l = 0;
    int r = s.size() - 1;
    while(l < r)
    {
        if(s[l] != s[r])
        {
            return false;
        };
        l++;
        r--;
    };
    return true;
};

// 
void GetCount(const string& s, int l, int r, int cur_idx, int had_count, string cur_s)
{
    if(cur_idx >= r)
    {
        string tmp = cur_s;
        tmp.push_back(s[cur_idx]);
        if(isRight(tmp))
        {
            min_idx = min(min_idx, had_count + 1);
        };
        return;
    };

    //已经形成了
    string tmp_s = cur_s;
    tmp_s.push_back(s[cur_idx]);
    
    if(isRight(tmp_s))
    {
        GetCount(s, l, r, cur_idx + 1, had_count + 1, ""); //计数

        GetCount(s, l, r, cur_idx + 1, had_count, tmp_s); //继续找
    }
    else //没有形成
    {
        GetCount(s, l, r, cur_idx + 1, had_count, tmp_s); //继续找
    }
};

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


int MinCount(string s, int l, int r)
{
    unordered_map<string, int> mp;
    GetCount(s, l, r, l, 0, "");
    return min_idx;
};

int main()
{
    string tmp;
    getline(cin, tmp);
    string s = tmp;
    getline(cin, tmp);
    int test_count = atoi(tmp.c_str());
    vector<vector<int>> vv;
    while(test_count-- > 0)
    {
        vv.push_back(GetIntVByLineBySpace());
    };

    for(auto v : vv)
    {
        min_idx = 1000000000;
        auto ret = MinCount(s, v[0] - 1, v[1] - 1);
        cout << ret << endl;
    }
    return 0;
}