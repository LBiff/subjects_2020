#include <vector>
#include<iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;


vector<pair<int, int>> GetIntVByLineBySpace()
{
    string s;
    string word;
    vector<pair<int, int>> v;
    getline(cin,s);
    istringstream record(s);
    int idx = 0;
    while(record >> word)
    {
        v.push_back({atoi(word.c_str()), idx++});
    };
    return v;
};

class comporator
{
public:
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)
    {
        return p1.first < p2.first ? true : false;
    }
};

int main()
{
    int test_count = GetIntVByLineBySpace()[0].first;
    while(test_count-- > 0)
    {

        auto p1 = GetIntVByLineBySpace();
        int huo_coun = p1[0].first;
        int jue_count = p1[1].first;
        //v,idx
        vector<pair<int, int>> huo_v = GetIntVByLineBySpace();
        vector<pair<int, int>> jue_v = GetIntVByLineBySpace();

        sort(jue_v.begin(),jue_v.end(), comporator());

        for(int i = 0; i < huo_v.size() - 1; i++)
        {
            bool get = false;
            for(int j= 0; j <jue_v.size(); j++)
            {
                if(jue_v[j].first >= huo_v[i].first)
                {
                    get = true;
                    cout << jue_v[j].second + 1 << " ";
                    jue_v.erase(jue_v.begin() + j);
                    break;
                }
            };
            if(!get)
            {
                cout << -1 << " ";
            }
        };

        bool end_get = false;
        for(int j= 0; j <jue_v.size(); j++)
        {
            int j0 = jue_v[j].first;
            int h = huo_v.back().first;
            if(jue_v[j].first >= huo_v.back().first)
            {
                end_get = true;
                cout << jue_v[j].second + 1;
                jue_v.erase(jue_v.begin() + j);
                break;
            }
        };
        if(!end_get)
        {
            cout << -1;
        };
        cout << endl;
    }
}