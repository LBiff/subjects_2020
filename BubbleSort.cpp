//冒泡排序
//从第一个数开始交换，每次把全局最大交换到最后 时间O(N^2), 空间 O(1)
#include<algorithm>
#include <vector>
using namespace std;

void BubbleSort(vector<int>& vec)
{
    if(vec.size() < 2)
    {
        return;
    }

    int end = vec.size() - 1;
    while(end > 0)
    {
        for(int idx = 0; idx < end; idx++)
        {
            if(vec[idx] > vec[idx+1])
            {
                std::iter_swap(vec.begin() + idx, vec.begin() + idx + 1);
            }
        }

        end--;
    }

}

int main()
{
    vector<int> a{2,5,8,6};
    BubbleSort(a);
    return 0;

}