// 俄罗斯方块游戏
// 使用一个字符串frame表明当前的方块状态，如"2122“，表明这个俄罗斯方块最多4列（长度），并且第一列有2个...
// |    |
// |# ##|
// |####|
// 另外一个字符串brick表示从上方下落的方块
// 方块从高处下落，只能左右移动
// 如果一行满则消除，求最少的剩余行数


#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

// 处理成一样长
int MinCount(vector<int> downStr, vector<int> upStr)
{
    // 窗口宽度
    int window_width = downStr.size();
    int max_total_high = 0;
    for(int i = 0; i < upStr.size(); i++)
    {
        int sum = upStr[i] + downStr[i];
        if(sum > max_total_high)
        {
            max_total_high = sum;
        }
    };

    // 下落稳定后的每行的块数
    vector<int> row_status(max_total_high, 0);
    for(int i = 0; i < window_width; i++)
    {
        //计算下面的贡献
        for(int j = 0; j < downStr[i]; j++)
        {
            row_status[j]++;
        };

        // 计算上面的贡献
        int top = max_total_high - 1;
        for(int k = upStr[i]; k > 0; k--)
        {
            row_status[top--]++;
        }
    };

    //计算消不完的
    int count = 0;
    for(auto r : row_status)
    {
        if(r != window_width)
        {
            count++;
        }
    };

    return count;
};

int GetMinRow(vector<int> frame, vector<int> brick)
{
    // 边界处理
    if(frame.size() < 2)
    {
        return 0;
    };
    //穷举
    int window_width = frame.size();
    int ret = INT_MAX;
    for(int start_idx = 0; start_idx <= frame.size() - brick.size(); start_idx++)
    {
        vector<int> new_brick;
        //前面加0
        for(int i = 0; i < start_idx; i++)
        {
            new_brick.push_back(0);
        };
        new_brick.insert(new_brick.end(), brick.begin(), brick.end());
        //后面加0;
        while(new_brick.size() < frame.size())
        {
            new_brick.push_back(0);
        };

        ret = min(ret, MinCount(frame, new_brick));
    };
    return ret;
}


vector<int> GetIntVByLineBySpace()
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

int main()
{
    vector<int> u = GetIntVByLineBySpace();
    vector<int> d = GetIntVByLineBySpace();
    auto ret = GetMinRow(u,d);
    cout << ret;
    return 0;
}
