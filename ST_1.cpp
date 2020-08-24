#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <sstream>
using namespace std;

string p = "Good";

int GetMax(string s)
{
    if(s.size() < 4)
    {
        return 0;
    }
    vector<int> G_v;
    vector<int> o_v;
    vector<int> d_v;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'G')
        {
            G_v.push_back(i);
        }
        else if(s[i] == 'o')
        {
            o_v.push_back(i);
        }
        else if(s[i] == 'd')
        {
            d_v.push_back(i);
        }
    };

    int count = 0;
    while(!G_v.empty() && o_v.size() >= 2 && !d_v.empty())
    {
        bool is_end = false;
        while(!d_v.empty())
        if(G_v.front() < o_v[0] < o_v[1] < d_v.front())
        {
            count++;
        };
        G_v.erase(G_v.begin());
        o_v.erase(o_v.begin());
        o_v.erase(o_v.begin() + 1);
        d_v.erase(d_v.begin());
    };

    return count;
};

// 123 GoodoodGGoooddjfhjdGGooo3dkdggggGoood0123
int Max_2(string s)
{
    deque<char> q;
    int count = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'G' || s[i] == 'o')
        {
            q.push_back(s[i]);
        }
        else if(s[i] == 'd')
        {
            int G_count = 0;
            while(!q.empty())
            {
                if(G_count == 1)
                {
                    break;
                }
                if(q.front() == 'G')
                {
                    G_count++;
                };
                q.pop_front();
            };

            int o_count = 0;
            vector<char> pop_cs;
            while(!q.empty())
            {
                if(o_count == 2)
                {
                    break;
                }
                if(q.front() == 'o')
                {
                    o_count++;
                };
                pop_cs.push_back(q.front());
                q.pop_front();
            };

            if(o_count == 2 && G_count == 1)
            {
                count++;
            }
            else
            {
               for(int i = pop_cs.size() - 1; i >=0; i--)
               {
                   q.push_front(pop_cs[i]);
               };
               while(G_count-- > 0)
               {
                   q.push_front('G');
               }
            }
            
        }
    };

    return count;
};



int main()
{
    string s;
    getline(cin,s);
    auto ret = Max_2(s);
    cout << ret;
    return 0;
}