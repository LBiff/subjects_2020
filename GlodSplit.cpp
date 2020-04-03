//黄金分割问题就是金典的霍夫曼编码问题
//一块金条切成两半需要花费和金条长度相同量的铜板，已知每个人需要的长度，将总长度怎么分花费铜板最少

#include <queue>
#include <cstdlib>
#include <vector>
#include <forward_list>
using namespace std;


//求最小花费
uint64_t CalMinCostForGlodSplit(vector<uint64_t> v)
{
    if(v.size() < 2)
    {
        return 0;
    };

    //构造小根堆
    priority_queue<uint64_t,vector<uint64_t>, greater<uint64_t>> less_heap;
    uint64_t v_idx = 0;
    while(v_idx < v.size())
    {
        less_heap.push(v[v_idx++]);
    };

    uint64_t cost = 0;
    while(less_heap.size() > 1)
    {
        uint64_t top_1 = less_heap.top();
        less_heap.pop();
        uint64_t top_2 = less_heap.top();
        less_heap.pop();
        uint64_t sum = top_1 + top_2;
        cost += sum;
        less_heap.push(sum);
    };
    return cost;
};

int main()
{
    int a = CalMinCostForGlodSplit(vector<uint64_t>{10,20,30});
    return 0;
}

