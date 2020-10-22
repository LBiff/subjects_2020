// 给你一个数组 events，其中 events[i] = [startDayi, endDayi] ，表示会议 i 开始于 startDayi ，结束于 endDayi 。
// 你可以在满足 startDayi <= d <= endDayi 中的任意一天 d 参加会议 i 。注意，一天只能参加一个会议。
// 请你返回你可以参加的 最大 会议数目。

#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Comparator
{
public:
    //按结束时间最小堆
    bool operator()(const vector<int>& v1, const vector<int>& v2)
    {
        return v1[1] > v2[1] ? true : false;
    }
};

//  [[1,4],[4,4],[2,2],[3,4],[1,1]]
int maxEvents(vector<vector<int>>& events) 
{
    //按开始时间排序
    sort(events.begin(), events.end(),[](const vector<int>& v1, const vector<int>& v2)
    {
        return v1[0] < v2[0] ? true : (v1[0] == v2[0] && v1[1] < v2[1] ? true : false);
    });

    priority_queue<vector<int>, vector<vector<int>>, Comparator> q;

    int day_idx = 1;
    int v_idx = 0;
    int count = 0;
    while(!q.empty() || v_idx < events.size())
    {
        //选出可以在当前开的会议
        while(v_idx < events.size())
        {
            if(events[v_idx][0] <= day_idx && events[v_idx][1] >= day_idx)
            {
                q.push(events[v_idx]);
                v_idx++;
            }
            else
            {
                break;
            }
        };

        //弹出不能开的
        while(!q.empty() && q.top()[1] < day_idx)
        {
            q.pop();
        };
        if(!q.empty())
        {
            count++;
            q.pop();
        };
        day_idx++;
    };
    return count;
};

int main()
{
    vector<vector<int>> v{{1,4},{4,4},{2,2},{3,4},{1,1}};
    auto ret = maxEvents(v);
    return 0;

}