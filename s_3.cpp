#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;



long long  ret = 0;

void get(const string& pass, string cur_pass)
{
    if(cur_pass.size() == pass.size())
    {
        if(pass == cur_pass)
        {
            return;
        }
        ret++;
        return;
    };
    if(cur_pass.size() > pass.size())
    {
        return;
    };
    size_t cur_pass_size = cur_pass.size();
    double cur_next = (double)((cur_pass[cur_pass_size - 1] - '0') + (pass[cur_pass_size] - '0')) / 2.0;
    int up = ceil(cur_next);
    int down = floor(cur_next);
    if(up == down)
    {
        cur_pass += to_string(up);
        get(pass, cur_pass);
    }
    else
    {
       auto tmp = cur_pass;
       tmp += to_string(up);
       get(pass, tmp);
       cur_pass += to_string(down);
       get(pass, cur_pass);
    }
}
long long getPasswordCount(string password) 
{
    int len = password.size();
    if(password.empty())
    {
        return 0;
    };

    for(int i = 0; i <= 9; i++)
    {
        string cur_pass = to_string(i);
        get(password, cur_pass);
    };

    return ret;
};

int main()
{
    string password = "3";
    auto ret_1 = getPasswordCount(password);
    return 0;
}