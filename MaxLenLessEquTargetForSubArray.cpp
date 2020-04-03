//子数组累加和小于等于给定值的最长子串
#include <string>
#include <vector>
using namespace std;

//二分查找累加和第一次大于等于target的索引
//help 是升序
int FirstGreaterEquValue(const vector<int> & help, int end_idx, int target)
{
    if(end_idx >= help.size())
    {
        return -1;
    };
    int l = 0;
    int r = end_idx;
    int first_idx = INT_MAX;
    while(l <= r)
    {
        int mid = l + (r - l) / 2; //防止溢出
        if(mid >= target)
        {
            first_idx = first_idx < mid ? first_idx : mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return first_idx == INT_MAX ? -1 : first_idx;
}
pair<int,int> MaxLen(const vector<int>& v, int target)
{
    if(v.empty())
    {
        return {-1,-1};
    };
    vector<int> l_sum_v(v.size() + 1, 0); //左累加和数组,考虑-1位置为0
    int sum = 0;
    for(int i = 1; i< l_sum_v.size(); i++)
    {
        sum += v[i-1];
        l_sum_v[i] = sum;
    };

    vector<int> l_max_v; //l_sum_v 左侧最大值数组
    int cur_max = INT_MIN;
    for(auto v : l_sum_v)
    {
        if(v > cur_max)
        {
            l_max_v.push_back(v);
            cur_max = v;
        }
        else
        {
            l_max_v.push_back(cur_max);
        }
    };

    pair<int,pair<int,int>> ret{-1,{-1,-1}};
    for(int i = 1; i < l_sum_v.size(); i++)
    {
        int v = l_sum_v[i];
        int g_e_idx = FirstGreaterEquValue(l_max_v,i - 1,target - v);
        if(g_e_idx != -1)
        {
            if(ret.first <  i - g_e_idx)
            {
                ret.first = i - g_e_idx;
                ret.second = {g_e_idx, i};
            }
        };
    };
    return ret.second;
};

int main()
{
    vector<int> v{3,-2,-4,0,6};
    auto ret = MaxLen(v,-2);
    return 0;
}
