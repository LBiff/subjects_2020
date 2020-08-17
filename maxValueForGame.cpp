// 每个游戏有奖励值和完成的时间，在给定的时间内完成最大的奖励值
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;


//以空格分隔获取一行整数数组
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


int max_v = 0;
//在这个时间点有这些游戏可以玩，之前玩的游戏已经获得cur_v，现在站在cur_time还没有玩游戏， days总时间
void CalMax(vector<vector<int>> cur_select, int cur_v, int cur_time, bool is_end, int days)
{
    if(is_end)
    {
        max_v = max(max_v, cur_v);
        return;
    };

    if(cur_select.empty())
    {
       CalMax(cur_select, cur_v, cur_time, true, days);
       return;
    }

    for(int i = 0; i < cur_select.size(); i++)
    {
        vector<vector<int>> cur_select_bak = cur_select;
        cur_select_bak.erase(cur_select_bak.begin() + i);

        int end_time = cur_select[i][1] + cur_time;
        if(end_time == days)
        {
            CalMax(cur_select_bak, cur_v + cur_select[i][0], cur_select[i][1] + cur_time, true, days);
        }
        else if(end_time < days)
        {
            CalMax(cur_select_bak, cur_v + cur_select[i][0], cur_select[i][1] + cur_time, false, days);
        }
        else
        {
            CalMax(cur_select_bak, cur_v, cur_select[i][1] + cur_time, true, days);
        }
    }
}
int MaxValue()
{
    vector<vector<int>> select;
    vector<int> in;
    in = GetIntVByLineBySpace();
    int game_count = in[0];
    int days = in[1];
    while(game_count-- > 0)
    {
        select.push_back(GetIntVByLineBySpace());
    };

    CalMax(select, 0, 0, false, days);
    return max_v;
};

int main()
{
    auto ret = MaxValue();
    cout << ret;
    return 0;
}