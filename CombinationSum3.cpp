//组合总和
// 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
// 说明：
// 所有数字都是正整数。
// 解集不能包含重复的组合。 
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
//Error
//Thinking
//共有5道题

//要与不要的问题
void Select(int k, int n, int idx, vector<int> get, vector<vector<int>>& vv)
{
    if(idx > 9)
    {
        return;
    }
    if(get.size() == k)
    {
        if(accumulate(get.begin(), get.end(), 0) == n)
        {
            vv.push_back(get);
        }
    }
    else
    {
        vector<int> get_tmp = get;
        get_tmp.push_back(idx);
        Select(k,n,idx + 1, get_tmp, vv);
        Select(k,n,idx + 1, get,vv);
    }
}

//回溯
// void Select(vector<int> cur_sel_list, int sum, int k, vector<int> cur_v, int cur_sum, vector<vector<int>>& ret)
// {
//     //结束条件
//     if(cur_sel_list.empty() || cur_sum > sum || cur_v.size() > k)
//     {
//         return;
//     }
//     if(cur_sum == sum && cur_v.size() == k)
//     {
//         ret.push_back(cur_v);
//         return;
//     };

//     if(cur_sum < sum && cur_v.size() < k)
//     {
//         for(int i = 0; i < cur_sel_list.size(); i++)
//         {
//             int bak = cur_sel_list[i];
//             cur_v.push_back(bak);
//             cur_sel_list.erase(cur_sel_list.begin() + i);
//             Select(cur_sel_list,sum, k, cur_v, cur_sum + bak, ret);
//             cur_sel_list.push_back(bak);
//         }
//     }
// };

vector<vector<int>> combinationSum3(int k, int n) 
{
    vector<vector<int>> ret;
    Select(k,n,1,{},ret);
    return ret;
}




int main()
{
    auto ret = combinationSum3(3,9);
    return 0;
}
