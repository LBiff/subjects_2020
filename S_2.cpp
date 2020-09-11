#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> GetStrVSpiltByChar()
{
    string s;
    getline(cin,s);
    s.erase(s.end() - 1);
    vector<int> v;
    size_t first_pos = s.find_first_of(',',0);
    v.push_back(atoi(s.substr(0, first_pos).c_str()));
    int pre = first_pos;
    pre++;
    size_t pos =  s.find_first_of(',',pre + 1);
    while(pos != string::npos)
    {
        v.push_back(atoi(s.substr(pre+1, pos-pre -1).c_str()));
        pre = pos;
        pos = s.find_first_of(',',pos + 1);
    };
    v.push_back(atoi(s.substr(pre+1).c_str()));
    return v;   
};


 int getHouses(int t, int* xa, int xaLen) 
 {
    int need_width = t;
    int ret = 2;
    if(xaLen < 2) //不能挨着
    {
        return 0;
    }

    for(int i = 0; i <= xaLen - 4; i++)
    {
        int idx_1 = xa[i];
        double width_1 = xa[i + 1];
        int idx_2 = xa[i + 2];
        double width_2 = xa[i + 3];

        double diff = idx_2 - idx_1 - width_1 / 2.0 - width_2 / 2.0;
        if(diff > need_width)
        {
            ret += 2;
        }
        else if(diff == need_width)
        {
           ret += 1;
        }
    };
    return ret;
}

int CalCount(const vector<int>& v)
{
    int need_width = v[0];
    int ret = 2;
    if(v.size() < 3) //不能挨着
    {
        return 0;
    }

    for(int i = 1; i <= static_cast<int>(v.size()) - 4; i++)
    {
        int idx_1 = v[i];
        double width_1 = v[i + 1];
        int idx_2 = v[i + 2];
        double width_2 = v[i + 3];

        double diff = idx_2 - idx_1 - width_1 / 2.0 - width_2 / 2.0;
        if(diff > need_width)
        {
            ret += 2;
        }
        else if(diff == need_width)
        {
           ret += 1;
        }
    };
    return ret;
};


int main()
{
    auto p = GetStrVSpiltByChar();
    auto ret = CalCount(p);

    cout << ret;
    return 0;
}