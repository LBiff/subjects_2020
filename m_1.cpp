#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// 注册网站时，需要使用包含不同类型（数字、符号、大写字母、小写字母）的字符，和特定长度。
// 检查一个密码内容同时包含以上 4 种类型的字符，并且长度在8-120 个字符之间。符合要求，返回 0；
// 长度不符合返回 1；类型不符合要求返还 2。
// 可以一次输入多组密码，以空格符间隔，空格符不作为密码。

//获取以特定字符分隔的string数组
static vector<string> GetStrVSpiltByChar(char c)
{
    string s;
    getline(cin,s);
    vector<string> v;
    size_t first_pos = s.find_first_of(c,0);
    v.push_back(s.substr(0, first_pos));
    int pre = first_pos;
    size_t pos =  s.find_first_of(c,pre + 1);
    while(pos != string::npos)
    {
        v.push_back(s.substr(pre+1, pos-pre -1));
        pre = pos;
        pos = s.find_first_of(c,pos + 1);
    };
    v.push_back(s.substr(pre+1));
    return v;   
};


int CalRet(const string& s)
{
    size_t sz = s.size();
    //长度不符合
    if(sz < 8 || sz > 120)
    {
        return 1;
    };
    vector<bool> v(4, false); //数字，符号，大写，小写
    for(auto c : s)
    {
        if(c >= '0' && c <= '9')
        {
            v[0] = true;
        }
        else if(c >= 'a' && c <= 'z')
        {
            v[3] = true;
        }
        else if(c >= 'A' && c <= 'Z')
        {
            v[2] = true;
        }
        else if(c != ' ')
        {
            v[1] = true;
        }
    };

    if((v[0] && v[1] && v[2] && v[3]))
    {
        return 0;
    };

    return 2;
};

int main()
{
    auto vs = GetStrVSpiltByChar(' ');
    for(auto vs_i : vs)
    {
        cout << CalRet(vs_i) << endl;
    };

    return 0;
}