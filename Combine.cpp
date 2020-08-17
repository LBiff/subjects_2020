//HUAWEI
//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

#include <vector>
using namespace std;


//要与不要的问题
void dp(vector<vector<int>>& vv, int idx, int k, int n, vector<int> cur_v)
{
    if(cur_v.size() == k)
    {
        vv.push_back(cur_v);
        return;
    };

    if(idx > n)
    {
        return;
    };
    vector<int> cur_v_bak = cur_v;
    cur_v_bak.push_back(idx);
    dp(vv, idx + 1, k,n,cur_v_bak);
    dp(vv, idx + 1, k,n,cur_v);
}

vector<vector<int>> combine(int n, int k) 
{
    vector<vector<int>> vv;
    dp(vv, 1,k,n,{});
    return vv;
};


int main()
{
    auto ret = combine(5, 3);
    return 0;
}

 
