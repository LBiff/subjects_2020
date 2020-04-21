//【华为2020】 投票

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
using namespace std;

string GetTopName(const vector<string>& vs)
{

    auto is_effective = [](const string& name)
    {
        if(name.empty())
        {
            return false;
        };
        if(!(name[0] >= 'A' && name[0] <= 'Z'))
        {
            return false;
        };
        for(int i = 1; i < name.length(); i++)
        {
            if(!(name[i] >= 'a' && name[i] <= 'z'))
            {
                return false;
            }
        };

        return true;
    };

    if(vs.empty())
    {
        return "error.0001";
    };

    unordered_map<string, int> map;
    for(auto s : vs)
    {
        if(!is_effective(s))
        {
            return "error.0001";
        };
        auto iter = map.find(s);
        if(iter != map.end())
        {
            iter->second++;
        }
        else
        {
            map.insert({s,1});
        }
    };

    auto is_greater = [](const pair<string, int>& p1, const pair<string, int>& p2)->bool
    {
        return p1.second > p2.second ||  (p1.second == p2.second && p1.first < p2.first) ?
                true : false;
    };


    pair<string, int> top = *map.begin();
    for(auto iter = next(map.begin()); iter != map.end(); iter++)
    {
        pair<string, int> tmp{iter->first, iter->second};
        if(is_greater(tmp, top))
        {
            top = tmp;
        }
    };

    return top.first;
};

vector<string> GetStrVByLineBySpecific(string spilt_c)
{

    string s;
    getline(cin,s);
    vector<string> v;
    size_t first_pos = s.find_first_of(spilt_c,0);
    v.push_back(s.substr(0, first_pos));
    int pre = first_pos;
    size_t pos =  s.find_first_of(spilt_c,pre + 1);
    while(pos != string::npos)
    {
        v.push_back(s.substr(pre+1, pos-pre -1));
        pre = pos;
        pos = s.find_first_of(spilt_c,pos + 1);
    };
    v.push_back(s.substr(pre+1));
    return v;   
};


int main()
{
    vector<string> vs = GetStrVByLineBySpecific(",");
    // vector<string> vs{"Tom","Lily","Tom","Lucy","Lucy","Jack"};
    cout << GetTopName(vs) << endl;
    return 0;
}