//数组序号转换
// 给你一个整数数组 arr ，请你将数组中的每个元素替换为它们排序后的序号。
// 序号代表了一个元素有多大。序号编号的规则如下：
// 序号从 1 开始编号。
// 一个元素越大，那么序号越大。如果两个元素相等，那么它们的序号相同。
// 每个数字的序号都应该尽可能地小。

#include <vector>
#include <algorithm>
using namespace std;

class Comparator
{
public:
    //升序排列
    bool operator()(const pair<int,int>& p1, const pair<int,int>& p2)
    {
        return p1.first < p2.first ? true : false;
    }
};

vector<int> arrayRankTransform(vector<int>& arr) 
{
    //记录原始idx
    vector<pair<int,int>> vp(arr.size()); //<value, idx>
    for(int i = 0; i < arr.size(); i++)
    {
        vp[i] = {arr[i], i};
    };
    //带着原始idx的信息进行值排序
    sort(vp.begin(), vp.end(),Comparator());
    vector<int> ret(arr.size());

    //记录pre_v，当增加的时候才增加，解决重复问题
    int sort_idx = 0;
    int pre_v = INT_MIN;
    for(auto vp_i : vp)
    {
        if(vp_i.first > pre_v)
        {
            sort_idx += 1;
            pre_v = vp_i.first;
        };
        ret[vp_i.second] = sort_idx;
    };

    return ret;
};

int main()
{
    vector<int> v{40,10,20,30};
    auto ret = arrayRankTransform(v);
    return 0;
}