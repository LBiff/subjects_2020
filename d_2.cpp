#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;   
   
//以空格分隔获取一行整数数组
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

bool ok(const unordered_map<int,vector<int>>& mp, int island_count)
{
    int get_count = 0;
    unordered_set<int> st;
    auto root = *mp.begin();
    queue<int> q;
    q.push(root.first);
    st.insert(root.first);
    while(!q.empty())
    {
        auto top = q.front();
        q.pop();
        get_count++;
        auto iter = mp.find(top);
        auto& child = iter->second;
        for(int i = 0; i < child.size(); i++)
        {
            auto iter_st = st.find(child[i]);
            if(iter_st == st.end())
            {
                q.push(child[i]);
                st.insert(child[i]);
            };
        }
    };

    return get_count == island_count;
};


int main()
{
    int count = GetIntVByLineBySpace()[0];
    while(count-- > 0)
    {
        auto title = GetIntVByLineBySpace();
        int island_count = title[0];
        int data_count = title[1];
        int max_v = title[2];
        unordered_map<int,vector<int>> mp;
        while(data_count-- > 0)
        {
            auto g = GetIntVByLineBySpace();
            if(g[2] <= max_v)
            {
                auto iter = mp.find(g[0]);
                if(iter == mp.end())
                {
                    mp.insert({g[0], {g[1]}});
                }
                else
                {
                    iter->second.push_back(g[1]);
                };

                auto iter_2 = mp.find(g[1]);
                if(iter_2 == mp.end())
                {
                    mp.insert({g[1], {g[0]}});
                }
                else
                {
                    iter_2->second.push_back(g[0]);
                };
            }
        };

        if(!mp.empty() && mp.size() >= island_count - 1 && ok(mp, island_count))
        {
            cout << "Yes" << endl;
        }
        else
        { 
            cout << "No" << endl;
        }
    };

    return 0;
}