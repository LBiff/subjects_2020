//求解子数组的累加和最大
#include <vector>
#include <cstdint>
using namespace std;

//ERROR

int GetMaxSubArraySum(vector<int> v)
{
    int arr_sum = 0;
    int max = INT32_MIN; 
    for (size_t i = 0; i < v.size(); i++)
    {
        arr_sum += v[i];
        if(arr_sum > max)
        {
            max = arr_sum;
        }
        if(arr_sum < 0)
        {
            arr_sum = 0;
        };
    };
    return max;
};

int main()
{
    int a = GetMaxSubArraySum(vector<int>{-1,-25,-4,-2,-12,-52});
    return 0;
}