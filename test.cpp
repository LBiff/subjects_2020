#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

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

//n--特训时间 m--木头人数 a--每个木头人的血量  b--小强一次输出的攻击
int KillCount(int n, int m, int a, int b)
{
     
};

int main()
{
    int test_count = GetIntVByLineBySpace()[0];
    vector<int> ret;
    while(test_count-- > 0)
    {
        auto in = GetIntVByLineBySpace();
        ret.push_back(KillCount(in[0],in[1],in[2],in[3]));
    };
    for(auto r : ret)
    {
        cout << r << endl;
    };
    return 0;
}