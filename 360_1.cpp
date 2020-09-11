#include <list>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

void Cal(int total_count, vector<pair<int,int>>& dk, set<int, greater<int>>& st)
{
    if(dk.size() == 2 * total_count)
    {
        st.insert(dk[0].first);
        return;
    };
    unordered_set<int> st2;
    //如果这段记录在z最前段记录,则第一个打卡的是boss，条件是前面必须是先上再下
    bool b1 = true; //是不是先上再下
    for(auto dk_i : dk)
    {
        int preson = dk_i.first;
        auto iter = st2.find(preson);
        if(iter == st2.end())
        {
            if(dk_i.second == 1) //上班
            {
                st2.insert(preson);
            }
            else
            {
                b1 = false;
                break;
            }
        }
    };

    if(b1)
    {
        st.insert(dk[0].first);
    };

    //如果在最后，没有条件直接排除
    list<int> lst;
    for(int i = 1; i <= total_count; i++)
    {
        lst.push_back(i);
    };

    for(auto dk_i : dk)
    {
        lst.remove(dk_i.first);
    };

    for(auto iter = lst.begin(); iter != lst.end(); iter++)
    {
        st.insert(*iter);
    }
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
    auto p1 = GetIntVByLineBySpace();
    int total_count = p1[0];
    int dk_count = p1[1];
    vector<pair<int,int>> dk;
    while(dk_count-- > 0)
    {
        auto p2 = GetIntVByLineBySpace();
        dk.push_back({p2[0], p2[1]});
    };
    set<int, greater<int>> st;
    Cal(total_count, dk, st);
    cout << *(st.begin());
    for(auto iter = next(st.begin()); iter != st.end(); iter++)
    {
        cout << " " << *iter;
    };
    cout << endl;
    return 0;
}


