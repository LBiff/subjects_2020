// 给定一个字符串，请将字符串里的字符按照出现的频率降序排列。
// 示例 1:
// 输入:
// "tree"
// 输出:
// "eert"
// 解释:
// 'e'出现两次，'r'和't'都只出现一次。
// 因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。

#include <string>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

class Comparator
{
public:
    bool operator()(const pair<char,int>& p1, const pair<char,int>& p2)
    {
        return p1.second < p2.second;
    };
};

string frequencySort(string s) 
{
    unordered_map<char,int> mp;
    for(auto c : s)
    {
        auto iter = mp.find(c);
        if(iter != mp.end())
        {
            iter->second++;
        }
        else
        {
            mp.insert({c,1});
        }
    };

    priority_queue<pair<char,int>, vector<pair<char,int>>, Comparator> q;

    for(auto mp_i : mp)
    {
        q.push({mp_i.first, mp_i.second});
    };

    string ret;
    while(!q.empty())
    {
        auto c = q.top().first;
        auto count = q.top().second;
        while(count-- > 0)
        {
            ret += c;
        };
        q.pop();
    }

    return ret;
};

int main()
{
    auto s = frequencySort("tree");
    return 0;
}