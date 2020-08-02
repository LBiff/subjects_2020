// 全排列
// 给定一个 没有重复 数字的序列，返回其所有可能的全排列。

#include <vector>
#include <set>
#include <list>
using namespace std;

//回溯算法框架
//重点是路径+选择列表

//参数v表示所有的选择列表, tracked表示已经做过了选择
void GetCurPermute(const vector<int>& v, vector<int> tracked, vector<vector<int>>& ret)
{
    //满足结束条件则添加
    if(v.size() == tracked.size())
    {
        vector<int> v;
        for(auto i : tracked)
        {
            v.push_back(i);
        };
        ret.push_back(v);
    };

    //回溯
    //对于每一个接下来可选择的列表
    for(auto i : v)
    {
        //没有用过可回溯
        bool track_contain = false;
        for(auto j : tracked)
        {
            if(j == i)
            {
                track_contain = true;
                break;
            }
        }
        if(!track_contain)
        {
            //添加选择
            tracked.push_back(i);
            //回溯
            GetCurPermute(v, tracked, ret);
            //撤销选择
            tracked.erase(tracked.end() - 1);
        }
    }
};


vector<vector<int>> permute(vector<int>& nums) 
{
    vector<vector<int>> ret;
    GetCurPermute(nums,{}, ret);
    return ret;
};

int main()
{
    vector<int> n{1,2,3};
    auto ret = permute(n);
    return 0;
}