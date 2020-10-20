// 给你两个长度相同的整数数组 target 和 arr 。
// 每一步中，你可以选择 arr 的任意 非空子数组 并将它翻转。你可以执行此过程任意次。
// 如果你能让 arr 变得与 target 相同，返回 True；否则，返回 False 。

//只要两个数组中的元素相等，那肯定可以翻转得到，将一个数翻转到最前面然后然后翻转到相应位置

#include <vector>
#include <algorithm>
using namespace std;

bool canBeEqual(vector<int>& target, vector<int>& arr) 
{
    if(target.size() != arr.size())
    {
        return false;
    }
    sort(target.begin(), target.end());;
    sort(arr.begin(),arr.end());
    for(int i = 0; i < target.size(); i++)
    {
        if(target[i] != arr[i])
        {
            return false;
        }
    };
    return true;
}
