//最小和问题： 求数组中每个数的左边比其小的数的和， 暴力解是O(n^2)
#include <iostream>
#include <vector>
using namespace std;

//[]双闭区间的归并
int GetLessSum(vector<int>& vec, int l, int r)
{
    if(l == r)
    {
        return 0;
    };

    int sum = 0;

    int middle = l + ((r - l) >> 1);
    sum += GetLessSum(vec,l,middle);
    sum += GetLessSum(vec, middle + 1, r);

    //归并过程中进行累加
    int l_idx = l;
    int r_idx = middle + 1;

    vector<int> vec_ret;
    while(l_idx <= middle && r_idx <= r)
    {
        if(vec[l_idx] <= vec[r_idx])
        {
            sum += vec[l_idx] * (r-r_idx + 1);
            vec_ret.push_back(vec[l_idx++]);
        } 
        else
        {
            vec_ret.push_back(vec[r_idx++]);
        }
    };
    
    while(l_idx <= middle)
    {
        vec_ret.push_back(vec[l_idx++]);
    };
    while(r_idx <= r)
    {
        vec_ret.push_back(vec[r_idx++]);
    };

    int help_idx  = l;
    int ret_idx = 0;
    while(help_idx <= r)
    {
        vec[help_idx++] = vec_ret[ret_idx++];
    }

    return sum;
};

int main()
{
    vector<int> a{16,2,56,22,23};
    int end = a.size() - 1;
    int b = GetLessSum(a, 0, end);
    return 0;
}