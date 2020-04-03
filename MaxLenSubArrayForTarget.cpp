//累加和等于目标值的最长子串长度
//元素可为正负0等
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> GetLine()
{
   string s;
   getline(cin,s);
   istringstream record(s);
   vector<int> ret;
   string word;
   while(record >> word)
   {
       ret.push_back(atoi(word.c_str()));
   };
   return ret;
};

int GetMaxLen(const vector<int>& v, int target)
{
    int max_len = 0;
    unordered_map<int, int> map; //<sum,i> 累加和过程中获得sum的最早idx
    map.insert({0,-1}); //重要！！！！！！！！
    int sum = 0;
    for(int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        if(map.find(sum) == map.end())
        {
            map.insert({sum, i});
        }
        auto iter = map.find(sum - target);
        if(iter != map.end())
        {
            max_len = max(max_len, i - iter->second);
        }
    };
    return max_len;
};

int main()
{
    vector<int> n_k = GetLine();
    vector<int> v = GetLine();
    cout << GetMaxLen(v,n_k[1]);
    return 0;
}