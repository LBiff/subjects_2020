#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <algorithm>
using namespace std;

//以空格分隔获取一行整数数组
static vector<int> GetIntVByLineBySpace()
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

//当前处理到第i个了,还没有处理
//第i个以前没有超half的最大
int max_v = 0;
int GetMax(const vector<int>& v, int i, int get, int half)
{
  
    if(i < v.size())
    {
        if(get <= half)
        {
            max_v = max(max_v, get);
        }
        GetMax(v, i + 1, get + v[i], half);
        GetMax(v, i + 1, get, half);
    }
    return -1;
}

int main()
{
    // int test_count = GetIntVByLineBySpace()[0];
    // vector<vector<int>> vv;
    // while(test_count -- > 0)
    // {
    //     GetIntVByLineBySpace();
    //     vv.push_back(GetIntVByLineBySpace());
    // };
    // for(auto v : vv)
    // {
    //      GetMin(v);
    // }

    vector<int> v{30, 60, 5, 15, 30};
    int sum = 140;
    int half = 70;


    return 0;
}