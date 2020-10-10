// 有 n 个城市通过 m 个航班连接。每个航班都从城市 u 开始，以价格 w 抵达 v。
// 现在给定所有的城市和航班，以及出发城市 src 和目的地 dst，你的任务是找到从 src 到 dst 最多经过 k 站中转的最便宜的价格。
// 如果没有这样的路线，则输出 -1。

//有向图

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int min_fee = INT_MAX;

//src->des -> fee
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) 
{
    //建图
    unordered_map<int, vector<pair<int,int>>> graph; //{src, {des, fee}};
    for(auto f :flights)
    {
        auto iter = graph.find(f[0]);
        if(iter != graph.end())
        {
            iter -> second.push_back({f[1], f[2]});
        }
        else
        {
            graph.insert({f[0], {{f[1], f[2]}}});
        }
    };

    //图的广搜
    queue<pair<int,int>> q; //{cur_station, cur_fee}
    q.push({src, 0});
    int cur_level = 0; //当前q中保存的是第几层
    int min_fee = INT_MAX;
    while(!q.empty() && cur_level < K + 1)
    {
        size_t sz = q.size();
        while(sz-- > 0)
        {
            auto top = q.front();
            q.pop();
            auto iter = graph.find(top.first);
            if(iter != graph.end())
            {
                for(auto i : iter->second)
                {
                    int new_fee = i.second + top.second;
                    if(i.first == dst)
                    {
                        min_fee = min(min_fee, new_fee);
                    }
                    else
                    {
                        q.push({i.first, new_fee});
                    }
                }
            }
        };
        cur_level++;
    };

    return min_fee == INT_MAX ? -1 : min_fee;
};
