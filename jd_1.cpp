// 小明想从一段英文短文中提取潜在的年份信息，待匹配的年份的范围为1000年至3999年，包含1000和3999。
// 输入一段英文短文，按出现次序输出所提取到的所有可能的年份字符串。
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

//读取连续的数字
void PrintYears_2(const string& s)
{
    string tmp;
    vector<string> ret;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9') 
        {
            tmp += s[i];
        }
        else
        {
            if(tmp.size() == 4)
            {
                if(tmp[0] >= '1' && tmp[0] <= '3')
                {
                    
                     ret.push_back(tmp);
                }
            };
            tmp.clear();
        }
    };
    
    if(!ret.empty())
    {
        cout << ret[0];
    };
    for(int i= 1; i < ret.size(); i++)
    {
        cout << " " << ret[i];
    }

}
// 201003abc2020输出：2020
void PrintYears(const string& s)
{
    vector<string> ret;
    for(int i = 0; i < s.size();)
    {
        if(s[i] >= '1' && s[i] <= '3')
        {
            if(i + 3 < s.size())
            {
                if(i + 4 < s.size())
                {

                }
                string tmp = s.substr(i, 4);
                bool is_err = false;
                for(int i = 0; i < 3; i++)
                {
                    if(!(tmp[i] >= '0' && tmp[i] <= '9'))
                    {
                        is_err = true;
                        break;
                    }
                };;
                if(!is_err)
                {
                    ret.push_back(tmp);
                };
            };
            i += 4;
        }
        else
        {
            i++;
        }
    };

    if(!ret.empty())
    {
        cout << ret[0];
    };
    for(int i= 1; i < ret.size(); i++)
    {
        cout << " " << ret[i];
    }
};

int main()
{
    string tmp;
    string s;
    getline(cin , s);

    // while(!tmp.empty())
    // {
    //     s += tmp;
    //     tmp .clear();
    //     getline(cin , tmp);
    // };
    PrintYears_2(s);
    return 0;
}

