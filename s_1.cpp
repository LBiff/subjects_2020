
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int ret = 0;

void get(int a, int b, int c, int cur_count) 
{
    if(a <= 0 || b <= 0 || c <= 0)
    {
        ret = max(ret, cur_count);
        return;
    };
    if(a >= 2)
    {
        get(a - 2, b + 1, c, cur_count);
        get(a - 2, b, c + 1, cur_count);
    };
    if(b >= 2)
    {
        get(a + 1, b - 2, c, cur_count);
        get(a, b - 2, c + 1, cur_count);
    };
    if(c >= 2)
    {
        get(a + 1, b, c - 2, cur_count);
        get(a, b + 1, c - 2, cur_count);
    };
    if(a >= 1 && b >= 1)
    {
        get(a - 1, b - 1, c + 1, cur_count);
    };
    if(a >= 1 && c >= 1)
    {
        get(a - 1, b + 1, c - 1, cur_count);
    };
    if(b >= 1 && c >= 1)
    {
        get(a + 1, b - 1, c - 1, cur_count);
    };
    get(a - 1, b - 1, c - 1, cur_count + 1);
};


int numberofprize_1(int a, int b, int c) 
{
    get(a,b,c,0);
    return ret;
};


unordered_map<string, int> mp;
int numberofprize(int a, int b, int c) 
{
    vector<int> v{a,b,c};
    sort(v.begin(), v.end());
    int half = (v[0] + v[1]) / 2;
    if(v[2] - v[0] <= 2)
    {
        return half;
    }
    
    v[1] = half;
    v[2] = v[2] - (v[1] - half);
    string tmp = to_string(v[0]) + "_" + to_string(v[1])+ "_" + to_string(v[2]);
    auto iter = mp.find(tmp);
    if(iter == mp.end())
    {
        return iter -> second;
    }
    else
    {
        int r = numberofprize(v[0], v[1],v[2]);
        mp.insert(tmp)
    }
    
    
};


int main()
{
    auto i = numberofprize(4,4,2);
    return 0;
};



