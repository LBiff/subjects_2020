//项目顺序问题: 已知每个项目的花费cost_i 和其纯利润pri_i, 最大串行做的项目数k, 初始启动资金m,求最大获利
//贪心问题：　在现有资金能做的情况下选利润最高的

#include <queue>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;


class Project
{
public:
    uint64_t _idx; //索引
    uint64_t _cost; //花费
    uint64_t _profit; //纯利润
    Project(uint64_t idx, uint64_t cost, uint64_t profit) : _idx(idx), _cost(cost), _profit(profit)
    {
    };
};
class MinHeapCompByCost
{
public:
    bool operator()(const Project& p_1, const Project& p_2)
    {
        return p_1._cost > p_2._cost ? true : false;
    }
};

//最大堆
class MaxHeapComBtProfit
{
public:
    bool operator()(const Project& p_1, const Project& p_2)
    {
        return p_1._profit < p_2._profit ? true : false;
    }
};


//返回最大获利
uint64_t GetMaxProfit(vector<Project> ps, uint64_t start_money, uint64_t do_num)
{
    uint64_t ret_profit = 0;
    priority_queue<Project, vector<Project>,MinHeapCompByCost> min_cost_heap;

    //全部入MinCostHeap
    for(Project i : ps)
    {
        min_cost_heap.push(i);
    };

    uint64_t did_num = 0;
    while(!min_cost_heap.empty() && did_num < do_num)
    {
        priority_queue<Project, vector<Project>,MaxHeapComBtProfit> max_profit_heap;
        while(!min_cost_heap.empty() && min_cost_heap.top()._cost <= start_money)
        {
            max_profit_heap.push(min_cost_heap.top());
            min_cost_heap.pop();
        };
        if(!max_profit_heap.empty())
        {
            ret_profit += max_profit_heap.top()._profit;
            start_money +=  max_profit_heap.top()._profit;
            max_profit_heap.pop();
            while(!max_profit_heap.empty())
            {
                Project top = max_profit_heap.top();
                min_cost_heap.push(top);
                max_profit_heap.pop();
            }
        }
        else
        {
            break;
        };
        did_num++;
    };

    return ret_profit;
};

int main()
{
    vector<Project> ps{
        {0,2,3},
        
        {1,5,6},
        {2,3,5},
        {3,6,1},
        {4,5,6}};
    int a= GetMaxProfit(ps, 2,3);
    return 0;
}




