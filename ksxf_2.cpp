#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> GetIntVSpiltByChar(char c)
{
    string s;
    getline(cin,s);
    vector<int> v;
    size_t first_pos = s.find_first_of(c,0);
    v.push_back(atoi(s.substr(0, first_pos).c_str()));
    int pre = first_pos;
    size_t pos =  s.find_first_of(c,pre + 1);
    while(pos != string::npos)
    {
        v.push_back(atoi(s.substr(pre+1, pos-pre -1).c_str()));
        pre = pos;
        pos = s.find_first_of(c,pos + 1);
    };
    v.push_back(atoi(s.substr(pre+1).c_str()));
    return v;   
};


void BubbleSort(vector<int>& vec)
{
    if(vec.size() < 2)
    {
        return;
    }

    for(int i = 0; i < vec.size(); i++)
    {
        int min_v = vec[i];
        int min_idx = i;
        for(int j = i; j < vec.size(); j++)
        {
            if(vec[j] < min_v)
            {
                min_v = vec[j];
                min_idx = j;
            }
        };
        swap(vec[i], vec[min_idx]);
    }
};

int main()
{
    auto p1 = GetIntVSpiltByChar(',');
    p1 = GetIntVSpiltByChar(',');
    if(p1.empty())
    {
        return 0;
    }
    BubbleSort(p1);
    cout << p1[0];
    for(int i = 1; i < p1.size(); i++)
    {
        cout << "," << p1[i];
    };
    return 0;
}