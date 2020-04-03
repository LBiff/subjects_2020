//归并排序
#include <vector>
#include <algorithm>
#include <exception>
#include <cmath>
#include <cassert>
using namespace std;

//返回最大索引
int GetMax(const vector<int> vec, int l, int r)
{
    assert(l > r || r > vec.size() - 1 || l < 0);

    if(l == r)
    {
        return l;
    };
    int middle = l + (r - l) / 2;  //不用 (l+r)/2, 是因为可能存在相加溢出的风险
    int l_max = GetMax(vec,l, middle);
    int r_max = GetMax(vec, middle+1, r);
    return vec[l_max] > vec[r_max] ? l_max : r_max;
};

void MergeSort(vector<int>& vec, int l, int r)
{
    //assert(!((0 <= l) && (l <= r) && (r <= vec.size())));

    if(vec.size() < 2 || l==r)
    {
        return;
    };


    int middle = l + (int)((r - l) >> 1);
    MergeSort(vec, l, middle);
    MergeSort(vec, middle+1, r);

    //合并
    vector<int> vec_ret;
    int l_idx = l;
    int r_idx = middle + 1;
    while(l_idx <= middle && r_idx <= r)
    {
        vec[l_idx] <= vec[r_idx] ?  vec_ret.push_back(vec[l_idx++]) 
                                 :  vec_ret.push_back(vec[r_idx++]);
    };
    while(l_idx <= middle)
    {
        vec_ret.push_back(vec[l_idx++]);
    };
    while(r_idx <= r)
    {
        vec_ret.push_back(vec[r_idx++]);
    };
    int help_idx = l;
    int vec_ret_idx = 0;
    while(help_idx <= r)
    {
        vec[help_idx++] = vec_ret[vec_ret_idx++];
    }
}

//非递归版本——Error
void MergeSortNoRecursion(vector<int>& vec)
{
    if(vec.size() < 2)
    {
        return;
    };

    //两[]区间
    //排好序的两区间进行合并
    auto merge = [&](int ll, int lr, int rl, int rr) 
    {
        int l_idx = ll;
        int r_idx = rl;
        vector<int> vec_ret;
        while(l_idx <= lr && r_idx <= rr)
        {
            vec[l_idx] <= vec[r_idx] ? vec_ret.push_back(vec[l_idx++]) :
                                        vec_ret.push_back(vec[r_idx++]);
        };
        while(l_idx <= lr)
        {
            vec_ret.push_back(vec[l_idx++]);
        };
        while(r_idx <= rr)
        {
            vec_ret.push_back(vec[r_idx++]);
        }

        int help_l_idx = ll;
        int ret_idx = 0;
        while(help_l_idx <= lr)
        {
            vec[help_l_idx] = vec_ret[ret_idx++];
        };
        help_l_idx = rl;
        while(help_l_idx <= rr)
        {
            vec[help_l_idx] = vec_ret[ret_idx++];
        }

    };

    int spilt_size = 1;
    int spilt_count = vec.size();

    while(spilt_count > 1)
    {
        int merge_idx = 0;
        while(merge_idx <= vec.size() - 1)
        {
            int ll = merge_idx;
            int lr = merge_idx + spilt_size - 1;
            if(lr > vec.size() - 1)
            {
                lr = vec.size() - 1;
                spilt_size *= 2;
                spilt_count = std::ceil((double)vec.size() / (double)spilt_size);
                continue;
            }
            int rl = lr + 1;
            int rr = merge_idx + 2 * spilt_size - 1;
            if(rr > vec.size() - 1)
            {
                lr = vec.size() - 1;
                spilt_size *= 2;
                spilt_count = std::ceil((double)vec.size() / (double)spilt_size);
                continue;
            };
            spilt_size *= 2;
            merge(ll, lr, rl, rr);
            merge_idx = rr + 1;
        };
        spilt_size *= 2;
        spilt_count = std::ceil((double)vec.size() / (double)spilt_size);
    }
   


}

int main()
{
    vector<int> a{14,5,56,5,15};
    MergeSortNoRecursion(a);
    return 0;
}