#include <string>
#include <iostream>
using namespace std;

// ___aaa__b____c__dd___
// aaa_b_c_dd
void guolv(string& s)
{
    
    char del_flag = '|';
    int front_idx = 0;
    while(s[front_idx] == '_')
    {
        s[front_idx] = del_flag;
        front_idx++;
    };

    int back_idx = s.size() - 1;
    while(s[back_idx] == '_')
    {
        s[back_idx] = del_flag;
        back_idx--;
    };

    int count = 0;
    for(int i = front_idx; i <= back_idx; i++)
    {
        if(s[i] == '_')
        {
            count++;
            if(count > 1)
            {
                s[i] = del_flag;
            }
        }
        else
        {
           count = 0;
        }
    };

    for(auto s_i : s)
    {
        if(s_i != del_flag)
        {
            cout << s_i;
        }
    };
};

int main()
{
    string s;
    cin >> s;
    guolv(s);
    return 0;
};



