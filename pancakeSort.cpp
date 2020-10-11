// 给定数组 A，我们可以对其进行煎饼翻转：我们选择一些正整数 k <= A.length，然后反转 A 的前 k 个元素的顺序。
// 我们要执行零次或多次煎饼翻转（按顺序一次接一次地进行）以完成对数组 A 的排序。
// 返回能使 A 排序的煎饼翻转操作所对应的 k 值序列。任何将数组排序且翻转次数在 10 * A.length 范围内的有效答案都将被判断为正确。

#include <vector>
#include <algorithm>
using namespace std;

//每次找到最大值，将其反转到最前面，然后整体反转到最后面
vector<int> pancakeSort(vector<int>& arr) 
{
    vector<int> ret;

    int cur_op_idx = arr.size() - 1; //当前想获得的最大值
    for(int cur_op_idx = arr.size() - 1; cur_op_idx > 0; cur_op_idx--)
    {
        int cur_max_idx = 0; //当前的最大值索引
        int cur_max_v = arr[0];
        for(int j = 0; j <= cur_op_idx; j++)
        {
            if(arr[j] > cur_max_v)
            {
                cur_max_v = arr[j];
                cur_max_idx = j;
            }
        };

        //只有小于的时候才反转
        if(cur_max_idx < cur_op_idx)
        {
            ret.push_back(cur_max_idx + 1);
            reverse(arr.begin(), arr.begin() + cur_max_idx + 1);
            ret.push_back(cur_op_idx + 1);
            reverse(arr.begin(), arr.begin() + cur_op_idx + 1);
        }
    };

    return ret;
};

int main()
{
    // 输入：[3,2,4,1]
    // 输出：[4,2,4,3]
    vector<int> v{3,2,4,1};
    auto ret = pancakeSort(v);
    return 0;
}