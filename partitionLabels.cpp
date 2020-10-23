// 字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。
// 返回一个表示每个字符串片段的长度的列表。

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> partitionLabels(string S) 
{
    unordered_map<char, pair<int,int>> mp;
    for(int i = 0; i < S.size(); i++)
    {
        auto iter = mp.find(S[i]);
        if(iter == mp.end())
        {
            mp.insert({S[i],{i,i}});
        }
        else
        {
            iter->second.second = i;
        }
    };

    vector<int> ret;
    pair<int,int> tmp= mp.find(S[0])->second;
    for(int i = 1; i < S.size();i++)
    {
        auto mp_i = mp.find(S[i])->second;
        if(mp_i.first <= tmp.second)
        {
            tmp.second = max(tmp.second, mp_i.second);
        }
        else
        {
            ret.push_back(tmp.second - tmp.first + 1);
            tmp = mp_i;
        }
    };
    ret.push_back(tmp.second - tmp.first + 1);
    return ret;
};


int main()
{
    auto ret = partitionLabels( "ababcbacadefegdehijhklij");
    return 0;
}
