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
    //结束时间升序排
    sort(intervals.begin(), intervals.end(),
    [](const vector<int>& v1, const vector<int>& v2)
    {
        return v1[1] < v2[1] ? true :false;
    });

    int del_count = 0;
    int travl_idx = 0;

    while(travl_idx < intervals.size())
    {
        if(intervals[travl_idx][0] != INT_MIN)
        {
            for(int i = travl_idx + 1; i < intervals.size(); i++)
            {
                if(intervals[i][0] < intervals[travl_idx][1] && intervals[i][0] != INT_MIN) //开始时间小于结束时间
                {
                    intervals[i][0] = INT_MIN; //标记删除
                    del_count++;
                };
            }
        };
        travl_idx++;
    };

    return del_count;
};