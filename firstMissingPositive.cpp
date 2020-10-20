
// 给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。
#include <vector>
#include <set> 
#include <algorithm>
using namespace std;

int firstMissingPositive(vector<int>& nums) 
{
    //涉及到去重的问题
    set<int,less<int>> st;
    for(auto n : nums)
    {
        if(n > 0)
        {
            auto iter = st.find(n);
            if(iter == st.end())
            {
                st.insert(n);
            }
        }
    };

    int cur_v = 1;
    int cur_bak = 0;
    for(auto iter = st.begin(); iter != st.end(); iter++)
    {
        if(*iter != cur_v)
        {
            return cur_v;
        };
        cur_bak = *iter;
        cur_v++;
    };
    return cur_bak + 1;
};

int main()
{
    vector<int> v;
    auto ret = firstMissingPositive(v);
    return 0;
}