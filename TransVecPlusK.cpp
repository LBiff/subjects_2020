//【字节笔试2020】
#include<vector>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

//将矩阵A转换为矩阵B，将A的某个连续区间+k(>=0)
//则左右检测不相等的区间，查看差值
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

bool TransVect(const vector<int>& a, const vector<int>& b)
{
    if(a.empty() && b.empty())
    {
        return true;
    };
    //找出第一个不相等的数
    int diff_front_idx = -1;
    for(int i =0; i< a.size(); i++)
    {
        if(a[i] != b[i])
        {
            diff_front_idx = i;
            break;
        }
    };
    //全部相等
    if(diff_front_idx == -1)
    {
        return true;
    };

    int diff_back_idx = -1;
    for(int j = a.size() -1; j >=0; j--)
    {
        if(a[j] != b[j])
        {
            diff_back_idx = j;
            break;
        }
    };

    //查找区间内是否相差k
    int diff_val = b[diff_front_idx] - a[diff_front_idx];
    if(diff_val < 0)
    {
        return false;
    };

    for(int i = diff_front_idx; i <= diff_back_idx; i++)
    {
        if(b[i] - a[i] != diff_val)
        {
            return false;
        }
    };

    return true;
};

int main()
{
    int data_count = GetIntVByLineBySpace()[0];
    vector<vector<int>> vv_a;
    vector<vector<int>> vv_b;

    while(data_count-- > 0)
    {
        GetIntVByLineBySpace();
        vv_a.push_back(GetIntVByLineBySpace());
        vv_b.push_back(GetIntVByLineBySpace());
    };

    for(int i = 0;i <vv_a.size(); i++)
    {
        bool ret = TransVect(vv_a[i], vv_b[i]);
        string s = ret ? "YES" : "NO";
        cout << s << endl;
    };

    return 0;
};
