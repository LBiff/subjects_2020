//快排： 递归的 < = > partition过程
//经典快排每次partition以最后一个数作为划分数，随机快牌每次随机选取一个数作为划分数


#include <vector>
#include <algorithm>
#include <utility>
#include <assert.h>
#include <cstdlib>
#include <ctime>
using namespace std;

//1h20
std::pair<int,int> Partition(vector<int>& vec, int l, int r)
{
    assert((0 <=l) && (l <= r) && (r <= vec.size() - 1));

    //划分区域为[]闭区间
    int less = l - 1;
    int more = r + 1;
    //经典快排以最后一个数为划分值，随机快排随机选取数作为划分值
   // int flag_v = vec[r]; //经典快排
    srand(time(0));
    int flag_idx = l + static_cast<int>(static_cast<double>(rand()) / (double)RAND_MAX *(r - l + 1));
    int flag_v = vec[flag_idx];
    int idx = l; 
    while(idx < more)
    {
        if(vec[idx] < flag_v)
        {
            std::iter_swap(vec.begin() + idx, vec.begin() + less + 1);
            less++;
            idx++;
        }
        else if(vec[idx] > flag_v)
        {
            std::iter_swap(vec.begin() + idx, vec.begin() + more - 1);
            more--;
            idx++;
        }
        else
        {
            idx++;
        }
    };
    return std::make_pair(less, more);
};

//递归或者归并过程中一定要加 basecase
void QuickSort(vector<int>& vec, int l, int r)
{
    if(l < r)  //可能出现r > l 的情况： >区间无 
    {
        auto partition_v = Partition(vec, l, r);
        QuickSort(vec,l, partition_v.first);
        QuickSort(vec, partition_v.second, r);
    }
};

int main()
{
    vector<int> a{1,33,5,6,26,6,56,33,15,56,78};
    int end = a.size() - 1;
    QuickSort(a, 0, end);
    return 0;
}
