// 给定一个正整数，返回它在 Excel 表中相对应的列名称。
//转换为26进制

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string convertToTitle(int n) 
{
    vector<char> ret;
    while(n > 0)
    {
        n -= 1; //注意从1开始的边界条件
        ret.push_back(n % 26 + 'A'); //每次取最后一位
        n /= 26; //右推一位
    };
    string ret_s;
    for(int i = ret.size() - 1; i>=0; i--)
    {
        ret_s += ret[i];
    };

    return ret_s;
}