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
vector<vector<int>> combinationSum3(int k, int n) 
{

}

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