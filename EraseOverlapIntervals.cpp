//不重叠区间
// 给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
// 注意:
// 可以认为区间的终点总是大于它的起点。
// 区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。

#include <vector>  
#include <algorithm>
using namespace std;

//按结束最早进行贪心
int eraseOverlapIntervals(vector<vector<int>>& intervals) 
{
    if(intervals.size() < 2)
    {
        return 0;
    }

    //结束时间升序排
    sort(intervals.begin(), intervals.end(),
    [](const vector<int>& v1, const vector<int>& v2)
    {
        return v1[1] < v2[1] ? true :false;
    });

    int no_overlap_count = 1; //不相交区间的数量
    int end = intervals[0][1];
    for(auto i : intervals)
    {
        int start = i[0];
        if(start >= end)  //找到下一个区间
        {
            no_overlap_count++;
            end = i[1];
        }
    }
    return intervals.size() - no_overlap_count;
};