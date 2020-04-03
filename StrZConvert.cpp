//字符串的Z形转换
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

//计算每个字符所在的行数
string convert(string s, int numRows) 
{
    string ret;
    //计算索引对应的行数
    if(numRows == 1)
    {
        return s;
    }
    else if(numRows == 2)
    {
        for(int i =0; i< s.size(); i+= 2)
        {
            ret += s[i];
        };
        for(int i =1; i< s.size(); i+= 2)
        {
            ret += s[i];
        }
    }
    else
    {
        int circle_count = 2 * numRows - 2; //一次打钩循环的数
        //计算行数
        auto cal_row = [&](int idx) -> int
        {
            int reduce = idx % circle_count;
            if(reduce < numRows)
            {
                return reduce;
            }
            else
            {
                return circle_count - reduce;
            }
        };

        //计算每个字符所在行数添加
        vector<vector<char>> vv(numRows);
        for(int i = 0; i< s.size(); i++)
        {
            vv[cal_row(i)].push_back(s[i]);
        };

        for(auto row : vv)
        {
            for(auto c : row)
            {
                ret += c;
            }
        };

    };
    return ret;
};

int main()
{
    string s="LEETCODEISHIRING";
    auto ret = convert(s,3);
    return 0;
}