// 字典序第K小子串
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

string GetMinK(string s, int k)
{
    priority_queue<string, vector<string>, less<string>> q; //大根堆
    set<string> st;
    for(int start = 0; start < s.size(); start++)
    {
        for(int end = start; end < s.size(); end++)
        {
            string tmp = s.substr(start, end - start + 1);
            if(st.find(tmp) == st.end())
            {
                if(q.size() < k)
                {
                    q.push(tmp);
                }
                else
                {
                    if(tmp < q.top())
                    {
                        q.pop();
                        q.push(tmp);
                    }
                };

                st.insert(tmp);
            }
        }
    };

    return q.top();
};

int main()
{
    string tmp;
    getline(cin, tmp);
    string s = tmp;
    getline(cin, tmp);
    int k = atoi(tmp.c_str());
    auto ret = GetMinK(s, k);
    cout << ret;
    return 0;
}



