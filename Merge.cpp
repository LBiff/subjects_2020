//有序数组的原地合并
// 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 num1 成为一个有序数组。

//Thinking
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    if(nums1.empty())
    {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        return;
    };
    if(nums2.empty())
    {
        return;
    };

    

    
}


//----------------------------------------------------------------------------------------------
// 给出一个区间的集合，请合并所有重叠的区间。
// 示例 1:
// 输入: [[1,3],[2,6],[8,10],[15,18]]
// 输出: [[1,6],[8,10],[15,18]]
// 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 示例 2:
// 输入: [[1,4],[4,5]]
// 输出: [[1,5]]
// 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

#include <vector>
#include <algorithm>
using namespace std;

class Comparator
{
public:
    //按照start升序排列
    bool operator()(const vector<int>& v1, const vector<int>& v2)
    {
        return v1[0] < v2[0] ? true : (v1[0] == v2[0] ? (v1[1] < v2[1] ? true : false) : false);
    }
};

vector<vector<int>> merge_2(vector<vector<int>>& intervals) 
{
    vector<vector<int>> vv;
    if(intervals.empty())
    {
        return vv;
    };
    //按照start升序排列
    sort(intervals.begin(), intervals.end(), Comparator());

    int start = intervals[0][0];
    int end = intervals[0][1];
    
    for(int i = 1; i < intervals.size(); i++)
    {
        if(intervals[i][0] <= end)
        {
            end = max(end, intervals[i][1]);
        }
        else
        {
            vv.push_back({start, end});
            //本次合并结束，进入下一次
            start = intervals[i][0];
            end = intervals[i][1];
        }
    };
    vv.push_back({start,end});
    return vv;
};

int main() 
{
    vector<vector<int>> vv{{1,4},{1,5}};
    auto ret = merge(vv);
    return 0;

}


