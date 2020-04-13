//【字节笔试2020】
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
//站在某一栋楼房顶左右只能看到小于等于该房顶的楼房数目
//双边遍历单调递增栈求解双边界
vector<int> SeeHouseCount(const vector<int>& v)
{
    //单调栈查找其左右边界，左右边界小于其
    //从顶到底递增，单调递增栈 
    //()双开区间
    stack<int> l_r_s; //从左到右遍历栈
    vector<int> l_r_v(v.size(), -1);
    stack<int> r_l_s; //从右到左遍历栈
    vector<int> r_l_v(v.size());

    //右边界
    for(int i = 0; i < v.size(); i++)
    {
        while(!l_r_s.empty() && v[l_r_s.top()] < v[i])
        {
            int top_i =l_r_s.top();
            l_r_s.pop();
            l_r_v[top_i] = i;
        };
        l_r_s.push(i);
    };
    while(!l_r_s.empty())
    {
        int top_i =l_r_s.top();
        l_r_v[top_i] = v.size();
        l_r_s.pop();
    };

    //右到左遍历
    //左边界
    for(int i = v.size() - 1; i >= 0; i--)
    {
        while(!r_l_s.empty() && v[r_l_s.top()] < v[i])
        {
            int top_i =r_l_s.top();
            r_l_s.pop();
            r_l_v[top_i] = i;
        };
        r_l_s.push(i);
    };
    while(!r_l_s.empty())
    {
        int top_i =r_l_s.top();
        r_l_v[top_i] = -1;
        r_l_s.pop();
    };

    vector<int> ret(v.size(), 0);
    for(int i =0; i < ret.size(); i++)
    {
        ret[i] = l_r_v[i] - r_l_v[i] - 2;
    };

    return ret;
};

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

int main()
{

    // vector<int> test_v{8,2,2,4,6};
    // auto test_ret = SeeHouseCount(test_v);

    int test_count = GetIntVByLineBySpace()[0];
    vector<vector<int>> vv;
    while(test_count-- > 0)
    {
        GetIntVByLineBySpace();
        vv.push_back(GetIntVByLineBySpace());
    };

    for(auto v : vv)
    {
        auto get = SeeHouseCount(v);
        for(int i = 0; i < get.size() - 1; i++)
        {
            cout << get[i] << " ";
        };
        cout << get.back() << endl;
    };

    return 0;
}