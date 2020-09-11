#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;


vector<long> GetlongVByLineBySpace()
{
    string s;
    string word;
    vector<long> v;
    getline(cin,s);
    istringstream record(s);
    while(record >> word)
    {
        v.push_back(atoi(word.c_str()));
    };
    return v;
};

void Get(vector<long>& v)
{
    auto v_sort = v;
    sort(v_sort.begin(), v_sort.end());
    
    long mid_pre = v_sort[v.size() / 2 - 1];
    long mid_post = v_sort[v.size() / 2];

    for(auto v_i : v)
    {
        if(v_i <= mid_pre)
        {
            cout << mid_post <<endl;
        }
        else if(v_i >= mid_post)
        {
           cout << mid_pre << endl;
        }
    };
};

int main()
{
    auto p1 = GetlongVByLineBySpace();
    if(p1[0] < 2)
    {
        cout << 0 << endl;
    }
    auto v = GetlongVByLineBySpace();
    Get(v);
    return 0;
}