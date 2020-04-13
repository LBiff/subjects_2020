//【字节笔试2020】
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//将木棍折断为两段放在原位置，保持总体单调不减
//单调栈维护，尽量保持相等或+1
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

int MinBreakCount(const vector<int>& v)
{
    int ret = 0;
    stack<int> s; //单调栈
    for(int i = v.size() - 1; i >= 0; i--)
    {
        if(!s.empty() && s.top() < v[i])
        {
            int tmp = (v[i] - 1) / s.top();
            ret += tmp;
            s.push(v[i] / (tmp  + 1));
            continue;
        };
        
        s.push(v[i]);
    };
    
    return ret;
}
int main()
{
    GetIntVByLineBySpace();
    cout << MinBreakCount(GetIntVByLineBySpace()) << endl;
    return 0;
}