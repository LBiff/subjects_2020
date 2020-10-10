// 给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。
// 只有当 c <= a 且 b <= d 时，我们才认为区间 [a,b) 被区间 [c,d) 覆盖。
// 在完成所有删除操作后，请你返回列表中剩余区间的数目。
// 示例：
// 输入：intervals = [[1,4],[3,6],[2,8]]
// 输出：2
// 解释：区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。

#include <vector>
#include <algorithm>
using namespace std;

// 按照起始点增序
int removeCoveredIntervals(vector<vector<int>>& intervals) 
{
    sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2)
    {
        return v1[0]< v2[0] ? true : (v1[0] == v2[0] ? (v1[1] < v2[1] ? true : false) : false);
    });

    int del_count = 0;
    int pre_idx = 0;
    //后面能不能吃掉前面的
    for(int i = 1; i < intervals.size(); i++)
    {
        //pre吃掉i,pre不变
        if(intervals[pre_idx][0] <= intervals[i][0] && intervals[pre_idx][1] >= intervals[i][1])
        {
            del_count++;
        }
        //i吃掉pre
        else if(intervals[i][0] == intervals[pre_idx][0] && intervals[i][1] >= intervals[pre_idx][1])
        {
            pre_idx = i;
            del_count++;
        }
        else
        {
            pre_idx = i;
        }
    };

    return intervals.size() - del_count;
};

int main()
{
    vector<vector<int>> intervals{{1,2},{1,4},{3,4}};
    auto ret = removeCoveredIntervals(intervals);
    return 0;
}