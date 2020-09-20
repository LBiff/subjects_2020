#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

string Get(const string& s, int spilt)
{
    string ret;
    int sz = s.size();
    int pre = 0;
    for(int i = 0; i < s.size();i+= spilt)
    {
        pre = i;
        string tmp = s.substr(i,spilt);
        reverse(tmp.begin(), tmp.end());
        ret += tmp;
    };
    return ret;
};

int main()
{
    int spilt;
    string s;
    string tmp;
    getline(cin, tmp);
    spilt = atoi(tmp.c_str());
    getline(cin, s);
    if(spilt >= s.size())
    {
        reverse(s.begin(), s.end());
        cout << s << endl;
        return 0;
    }
    cout << Get(s, spilt) << endl;
    return 0;
}