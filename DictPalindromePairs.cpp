//字典回文对
//给定一组唯一的单词， 找出所有不同 的索引对(i, j)，使得列表中的两个单词， 
//words[i] + words[j] ，可拼接成回文串。

#include <vector>
#include <string>
#include<unordered_map>
using namespace std;

vector<vector<int>> palindromePairs(const vector<string>& words) 
{
    unordered_map<string, vector<int>> map; //代表,idx

    int idx = 0;
    for(const string& s : words)
    {
        int i_rp[26];
        for(int i =0; i< 26; i++)
        {
            i_rp[i] = 0;
        };

        for(char c : s)
        {
            int s = c - 'a';
            i_rp[c - 'a']++;
        };
        string s_rp;
        for(auto i_rp_i : i_rp)
        {
            s_rp.append(to_string(i_rp_i)).append("_");
        };

        auto iter = map.find(s_rp);  
        if(iter != map.end())  //有记录
        {
            iter->second.push_back(idx);
        }
        else
        {
            vector<int> vi;
            vi.push_back(idx);
            map.insert(make_pair(s_rp, vi));
        }
        idx++;
    };

    vector<vector<int>> vvi;
    for(auto iter = map.begin(); iter != map.end(); iter++)
    {
        const vector<int>& vi = iter->second;
        if(vi.size() > 1)
        {
            for(int i =0; i<vi.size();i++)
            {
                for(int j = i + 1; j < vi.size(); j++)
                {
                    vvi.push_back({i,j});
                    vvi.push_back({j,i});
                }
            }
        }
    };

    return vvi;
};

int main()
{
    vector<string> s = {"abcd","dcba","lls","s","sssll"};
    palindromePairs(s);
}