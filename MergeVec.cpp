//区间合并问题    
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
    vector<vector<int>> ret;
    if(intervals.empty())
    {
        return ret;
    };

    auto SortInter = [](vector<int> v_1, vector<int> v_2) -> bool
    {
        return v_1[0] < v_2[0];
    };
    sort(intervals.begin(), intervals.end(), SortInter);

    int begin = intervals[0][0];
    int end = intervals[0][1];
    vector<int> push_v = intervals[0];
    for(int i = 1; i< intervals.size(); i++)
    {
        if(intervals[i][0] <= push_v[1]) //能接住
        {
            push_v[1] = max(push_v[1], intervals[i][1]);
        }
        else
        {
            ret.push_back(push_v);
            //选择另一起始点
            push_v = intervals[i];
        }
    };
    ret.push_back(push_v);
    return ret;
};

int main()
{
    vector<vector<int>> a = {{1,3},{2,6},{8,10},{15,18}};
    auto b = merge(a);
    return 0;

}