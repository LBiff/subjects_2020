//最小使用会议房间问题
//给定一个会议时间安排的数组，每个会议时间都会包括开始和结束的时间 [[s1,e1],[s2,e2],...] (si < ei)，
//为避免会议冲突，同时要考虑充分利用会议室资源，请你计算至少需要多少间会议室，才能满足这些会议安排。
#include<vector>
#include <algorithm>
#include <queue>
using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals) 
{
    if(intervals.empty())
    {
        return 0;
    }
    sort(intervals.begin(), intervals.end(), 
        [](const vector<int>& m_1, const vector<int>& m_2){return m_1[0] <= m_2[0] ? true : false;});
    priority_queue<int,vector<int>,greater<int>> q; //最小堆，结束时间，即正在开会房间
    q.push(intervals[0][1]);
    for(int i = 1; i< intervals.size(); i++)
    {
        if(intervals[i][0] >= q.top()) //可以开始
        {
            q.pop();
            q.push(intervals[i][1]);
        }
        else
        {
            q.push(intervals[i][1]); //重新开房
        }
    };

    return q.size();
};

int main()
{
    vector<vector<int>> vv{{5,10},{0,30},{15,20}};
    int c = minMeetingRooms(vv);
    return 0;
}