//荷兰国旗问题： 将数组以最后一个数为标记将数组划分 < = > 三部分


#include <vector>
#include <algorithm>
using namespace std;

void HollandFlag(vector<int>& vec)
{
    if(vec.size() < 2)
    {
        return;
    };

    //边界都是]闭区间
    int less_idx = -1;
    int greater_idx = vec.size();

    int flag = vec.back();
    int idx = 0;
    while(idx < greater_idx)
    {
        if(vec[idx] < flag)
        {
            std::iter_swap(vec.begin() + idx, vec.begin() + less_idx + 1);
            less_idx++;
            idx++;
        }
        else if(vec[idx] > flag)
        {
           std::iter_swap(vec.begin() + idx, vec.begin() + greater_idx - 1);
            greater_idx--;
        }
        else
        {
            idx++;
        }
    }
} 

int main()
{
    vector<int> a{1,52,54,2,5,1,2,52,54,56,2,1,2,52};
    HollandFlag(a);
    return 0;
}