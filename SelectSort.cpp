//选择排序
//每次选择后面最小的放到最前面

#include <vector>
#include <algorithm>
using namespace std;

void SelectSort(vector<int>& vec)
{
    if(vec.size() < 2)
    {
        return;
    }

    for(int start = 0; start < vec.size() - 1; start++)
    {
        int min_idx = start;
        int check_idx = start;
        while(++check_idx < vec.size())
        {
            if(vec[check_idx] < vec[min_idx])
            {
                min_idx = check_idx;
            }
        }
        std::iter_swap(vec.begin() + start, vec.begin() + min_idx);
    }
}

int main()
{
    vector<int> v{6,5,8,32,5,87,233,1};
    SelectSort(v);
    return 0;
}
