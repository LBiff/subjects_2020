// 深信服笔试
// 给定只含有0-9的字符串和变换对<0,1>表示全部0换为1， 求解最后字符串
// 觉得是对的，但是不知道为啥过不去牛客
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <list>
using namespace std;

string Trans(const string& s, const vector<vector<int>> vp)
{
    unordered_map<char, list<int>> mp; //char, idx
    for(int i = 0; i < s.size(); i++)
    {
        auto iter = mp.find(s[i]);
        if(iter == mp.end())
        {
            mp.insert({s[i], {{i}}});
        }
        else
        {
            iter->second.push_back(i);
        }
    };

    for(auto i : vp)
    {
        if(i[0] < 0 || i[0] > 9 || i[1] < 0 || i[1] > 9)
        {
            continue;
        }
        char fir = i[0] + '0';
        char sec = i[1] + '0';
        
        if(fir == sec)
        {
            continue;
        }
        auto iter = mp.find(fir);
        if(iter != mp.end())
        {
            auto iter_sec = mp.find(sec);
            if(iter_sec == mp.end())
            {
                mp.insert({sec, iter->second});
            }
            else
            {
                iter_sec->second.insert(iter_sec->second.end(), iter->second.begin(), iter->second.end());
                
            };

            //清空
            iter->second.clear();
        }
    };

    string ret;
    ret.resize(s.size());
    for(auto iter = mp.begin(); iter != mp.end(); iter++)
    {
        auto c = iter->first;
        for(auto idx : iter->second)
        {
          
            ret[idx] = c;
        }
    };

    return ret;
};

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


int main()
{
    string tmp;
    getline(cin,tmp);
    string s = tmp;
    if(s.empty())
    {
        cout << "";
        return 0;
    };

    getline(cin,tmp);
    int count = atoi(tmp.c_str());
    vector<vector<int>> vv;
    while(count-- > 0)
    {
        vv.push_back(GetIntVByLineBySpace());
    }
    auto ret = Trans(s,vv);
    cout << ret;
    return 0;
}