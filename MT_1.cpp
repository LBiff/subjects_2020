#include <string>
#include <sstream>
#include <iostream>
using namespace std;

bool isRight(string s)
{
    if(s.empty())
    {
        return false;
    };
    if(!(('a' <= s[0] && s[0] <= 'z') || ('A' <= s[0] && s[0] <= 'Z')))
    {
        return false;
    };

    bool has_num = false;
    for(auto c : s)
    {
        if((('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')))
        {
            continue;
        }
        else if('0' <= c && c <= '9')
        {
            has_num = true;
            continue; 
        }
        else
        {
            return false;
        }
    };
    return has_num;
};

int main()
{
    string s;
    getline(cin, s);
    int test_count = atoi(s.c_str());
    while(test_count-- > 0)
    {
        getline(cin, s);
        bool ret = isRight(s);
        if(ret)
        {
            cout << "Accept" << endl;
        }
        else
        {
            cout << "Wrong" << endl;
        }
    };
    return 0;
}