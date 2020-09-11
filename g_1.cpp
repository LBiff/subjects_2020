#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
using namespace std;


//以空格分隔获取一行整数数组
vector<int> GetIntVByLineBySpace_1()
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

//以空格分隔获取一行整数数组
void GetIntVByLineBySpace(priority_queue<int, vector<int>, greater<int>>& q)
{
    string s;
    string word;
    getline(cin,s);
    istringstream record(s);
    while(record >> word)
    {
        q.push(atoi(word.c_str()));
    };
};

int main()
{
    auto p1 = GetIntVByLineBySpace_1();
    int c_count = p1[0];
    int yao_count = p1[1];
    int each_inc_h = p1[2];

    priority_queue<int, vector<int>, greater<int>> q;
    GetIntVByLineBySpace(q);
    while(yao_count-- > 0)
    {
        int top = q.top();
        q.pop();
        q.push(top + each_inc_h);
    };
    cout << q.top();
    return 0;
}
