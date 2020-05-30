// 在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行。在接下来的一年里，
// 你要旅行的日子将以一个名为 days 的数组给出。每一项是一个从 1 到 365 的整数。
// 火车票有三种不同的销售方式：
// 一张为期一天的通行证售价为 costs[0] 美元；
// 一张为期七天的通行证售价为 costs[1] 美元；
// 一张为期三十天的通行证售价为 costs[2] 美元。
// 通行证允许数天无限制的旅行。 例如，如果我们在第 2 天获得一张为期 7 天的通行证，那么我们可以连着旅行 7 天：
// 第 2 天、第 3 天、第 4 天、第 5 天、第 6 天、第 7 天和第 8 天。
// 返回你想要完成在给定的列表 days 中列出的每一天的旅行所需要的最低消费。
#include <vector>
#include <cstdlib>
#include <string>
#include <unordered_map>
using namespace std;

//第day_idx天(0基准)计划，当前手里的票<date, days_count>, 当前所有的花费
int dp(int day_idx, const vector<int>& days, const vector<int>& costs,  pair<int,int> pre_ticket, int cur_cost, unordered_map<string, int>& map)
{
    if(day_idx >= days.size())
    {
        return cur_cost;
    };

    //上次买的票可以这次用
    int cost = INT_MAX;
    if(days[day_idx] < pre_ticket.first + pre_ticket.second)
    {
        //这次不花钱
        string tmp = to_string(day_idx + 1) + "-" + to_string(pre_ticket.first)  + "-"  + to_string(pre_ticket.second) + "-" + to_string(cur_cost);
        auto iter = map.find(tmp);
        if(iter != map.end())
        {
            cost = min(cost, iter->second);
        }
        else
        {
            int ret_0 = dp(day_idx + 1, days, costs, pre_ticket,cur_cost,map);
            cost = min(cost, ret_0);
            map.insert({tmp,ret_0});
        }
    }
    else //这次需要另外购买
    {
        string tmp_1 = to_string(day_idx + 1) + "-" + to_string(days[day_idx]) + "-" + "1" + "-" + to_string(cur_cost + costs[0]);
        string tmp_2 = to_string(day_idx + 1) + "-" + to_string(days[day_idx]) + "-" + "7" + "-" + to_string(cur_cost + costs[1]);
        string tmp_3 = to_string(day_idx + 1) + "-" + to_string(days[day_idx]) + "-" + "30" + "-" + to_string(cur_cost + costs[2]);
        auto iter_1 = map.find(tmp_1);
        auto iter_2 = map.find(tmp_2);
        auto iter_3 = map.find(tmp_3);

        if(iter_1 != map.end())
        {
            cost = min(cost, iter_1->second);
        }
        else
        {
            int ret_1 = dp(day_idx + 1, days, costs, make_pair(days[day_idx], 1),cur_cost + costs[0],map);
            cost = min(cost, ret_1);
            map.insert({tmp_1,ret_1});
        };

        if(iter_2 != map.end())
        {
            cost = min(cost, iter_2->second);
        }
        else
        {
            int ret_2 = dp(day_idx + 1, days, costs, make_pair(days[day_idx], 7),cur_cost + costs[1],map);
            cost = min(cost, ret_2);
            map.insert({tmp_2,ret_2});
        };

        if(iter_3 != map.end())
        {
            cost = min(cost, iter_3->second);
        }
        else
        {
            int ret_3 = dp(day_idx + 1, days, costs, make_pair(days[day_idx], 30),cur_cost + costs[2],map);
            cost = min(cost, ret_3);
            map.insert({tmp_3,ret_3});
        }
    };
    return cost;
};


int mincostTickets(vector<int>& days, vector<int>& costs) 
{
    unordered_map<string, int> map;
    return dp(0,days,costs,make_pair(0,0),0,map);
};



int main()
{
    vector<int> days{1,4,6,7,8,20};
    vector<int> costs{2,7,15};
    auto ret = mincostTickets(days, costs);
    return 0;
}

