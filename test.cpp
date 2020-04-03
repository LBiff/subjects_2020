//正整数数组中累加和等于给定值的最长子数组
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

//获取一行
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

int GetMaxLen(const vector<int>& v, int target)
{
    if(v.empty())
    {
        return 0;
    };
    //[]闭区间
    int l_idx = 0;
    int r_idx = 0;
    int v_size = v.size();
    int max_len = 0;
    int sum = v[0];
    while(l_idx < v_size && r_idx < v_size)
    {
        if(sum == target)
        {
            int cur_len = r_idx - l_idx + 1;
            max_len = max_len < cur_len ? cur_len :max_len;
            sum -= v[l_idx];
           if( r_idx + 1 < v_size)
           {
               sum += v[r_idx + 1];
           }
           else
           {
               return max_len;
           }
            l_idx++;
            r_idx++;
        }
        else if(sum > target)
        {
            sum -= v[l_idx];
            l_idx++;
            
        }
        else
        {
            sum += v[l_idx];
            r_idx++;
        };
    };
    return max_len;
};

int main()
{
    int a[2]{1,2};
    auto p = a;
    auto p_0 = &(a[0]);
    auto p2 = &a;
    unordered_map<int, int> map;
    vector<int> n_k = GetIntVByLineBySpace();
    vector<int> v = GetIntVByLineBySpace();
    int ret = GetMaxLen(v, n_k[1]);
    return 0;
};