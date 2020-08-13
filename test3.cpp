#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


//以空格分隔获取一行整数数组
static vector<int> GetIntVByLineBySpace()
{
    string s;
    string word;
    vector<int> v;
    getline(cin,s);
    istringstream record(s);
    while(record >> word)
    {
        v.push_back(atoi(word.c_str()));
    };
    return v;
};


//开始时间是8点
string calTime(int sec)
{
    int h = sec / 3600 + 8;
    int fz = (sec % 3600) / 60;
    int s = (sec % 60);
    string ret;
    if(h > 12)
    {
        h = h - 12;
        ret += "0";
        ret += to_string(h);
        ret += ":";
        ret += fz > 9 ? to_string(fz) : "0" + to_string(fz);
        ret += ":";
        ret += s > 9 ? to_string(s) : "0" + to_string(s);
        ret += " ";
        ret += "pm";
    }
    else 
    {
        ret += h < 10 ? "0" + to_string(h) : to_string(h);
        ret += ":";
        ret += fz > 9 ? to_string(fz) : "0" + to_string(fz);
        ret += ":";
        ret += s > 9 ? to_string(s) : "0" + to_string(s);
        ret += " ";
        ret += "am";
    }
    return ret;
}


int main()
{
    
    int test_count = GetIntVByLineBySpace()[0];
    while(test_count-- > 0)
    {
        int time = 0;
        int p_count = GetIntVByLineBySpace()[0];
        if(p_count == 1)
        {
            auto t1 = GetIntVByLineBySpace();
            time = t1[0];
        }
        else if(p_count > 1)
        {
            auto t1 = GetIntVByLineBySpace();
            auto t2 = GetIntVByLineBySpace();
            vector<int> dp(p_count, 0); //dp[i]表示前i个人最短的买票时间
            dp[0] = t1[0]; //前面没有人
            for(int i = 1; i < p_count; i++)
            {
                dp[i] = min(dp[i - 1] + t1[i], dp[i - 2] + t2[i - 1]);
            };
            time = dp.back();
        };

        cout << calTime(time) << endl;
    };

}