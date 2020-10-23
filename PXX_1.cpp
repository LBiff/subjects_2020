//拼多多_1

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

pair<int,int> GetPair(vector<int> v, int diff)
{
    if(v.empty())
    {
        return {-1,-1};
    };
    
    pair<int,int> ret{max(0, v[0] - diff), v[0] + diff};
    for(int i = 1; i < v.size(); i++)
    {
        int low = v[i] - diff;
        int up = v[i] + diff;
        if(low > ret.second || up < ret.first)
        {
            return {-1,-1};
        }
        else
        {
            ret.first = max(0, max(ret.first, low));
            ret.second = min(ret.second, up);
        }
    };

    return ret;
};


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
    auto p1 = GetIntVByLineBySpace();
    int count = p1[0];
    int diff = p1[1];
    vector<int> v;
    while(count-- > 0)
    {
        v.push_back(GetIntVByLineBySpace()[0]);
    };

    auto ret = GetPair(v,diff);
    if(ret.first == -1)
    {
        cout << -1 << endl;
        return 0;
    };
    cout << ret.first << " " << ret.second;
    return 0;
}
