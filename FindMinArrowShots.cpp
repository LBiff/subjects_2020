//用最少数量的箭引爆气球
// 在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。
// 由于它是水平的，所以y坐标并不重要，因此只要知道开始和结束的x坐标就足够了。开始坐标总是小于结束坐标。
// 平面内最多存在104个气球。
// 一支弓箭可以沿着x轴从不同点完全垂直地射出。在坐标x处射出一支箭，若有一个气球的直径的开始和结束坐标为 
// xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 
//弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。

#include <vector>
#include <algorithm>
using namespace std;

//其实就是求最多的不重叠区间,就是删除最少使其不重叠
int findMinArrowShots(vector<vector<int>>& points) 
{
    //结束时间升序排
    sort(points.begin(), points.end(),
    [](const vector<int>& v1, const vector<int>& v2)
    {
        return v1[1] < v2[1] ? true :false;
    });

    int del_count = 0;
    int travl_idx = 0;

    while(travl_idx < points.size())
    {
        if(points[travl_idx][0] != INT_MIN)
        {
            for(int i = travl_idx + 1; i < points.size(); i++)
            {
                if(points[i][0] <= points[travl_idx][1] && points[i][0] != INT_MIN) //开始时间小于结束时间
                {
                    points[i][0] = INT_MIN; //标记删除
                    del_count++;
                };
            }
        };
        travl_idx++;
    };

    return points.size() - del_count;
};

int main()
{
    vector<vector<int>> vv{{10,16}, {2,8}, {1,6}, {7,12}};
    auto ret = findMinArrowShots(vv);
    return 0;
}