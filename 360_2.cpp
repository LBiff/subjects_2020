// 验证密码复杂性是网站在用户输入初始密码后需要进行的一步操作。
// 现在，小A的网站需要验证密码的复杂性，小A对一个足够复杂的密码拥有如下要求：
// 1.要有数字
// 2.要有大写字母
// 3.要有小写字母
// 4.要有特殊字符
// 5.长度不得小于8
// 现在给你密码，请你判断这个密码是否足够复杂
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

bool is_fuza(const string& s)
{
    if(s.size() < 8)
    {
        return false;
    }
    vector<bool> fir(4, false);
    for(auto c : s)
    {
        if('0' <= c && c <= '9') //数字
        {
            fir[0] = true;
        }
        else if('A' <= c && c <= 'Z')
        {
            fir[1] = true;
        }
        else if('a' <= c && c <= 'z')
        {
            fir[2] = true;
        }
        else
        {
            fir[3] = true;
        };

        if(fir[0] && fir[1] && fir[2] && fir[3])
        {
            return true;
        }
    };

    return false;
};

int main()
{
    while(1)
    {
        string s;
        getline(cin, s);
        if(s.empty())
        {
            return 0;
        }
        if(is_fuza(s))
        {
            cout << "Ok" << endl;
        }
        else
        {
            cout << "Irregular password" << endl;
        }
    }
}