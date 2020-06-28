//  复写零
// 给你一个长度固定的整数数组 arr，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。
// 注意：请不要在超过该数组长度的位置写入元素。
// 要求：请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。

// 输入：[1,0,2,3,0,4,5,0]
// 输出：null
// 解释：调用函数后，输入的数组将被修改为：[1,0,0,2,3,0,0,4]

#include <vector>
using namespace std;

//计算需要丢弃多少元素，从未丢弃的元素从后往前复制
//[1,0,3,0],从前向后不是0+1，是0+2，直到>=size, 得到[1,0,3]不丢弃，从后往前复制，遇到0复制


void duplicateZeros(vector<int>& arr) 
{
    int size = static_cast<int>(arr.size());
    int count = 0;
    int cur_idx = 0;
    while(count < size)
    {
        count += arr[cur_idx++] != 0 ? 1 : 2;
    };

    //[0, cur_idx)为不需要扔的
    int a_idx = static_cast<int>(arr.size()) - 1;
    //如果最后复制可能越界，存在复制不复制最后一个0的情况
    if(count > size) 
    {
        a_idx--;
        arr[arr.size() - 1] = 0; //直接把最后一个0复制一个到最后
        cur_idx--; //最后一个不用复制了
    }
    for(int i = cur_idx - 1; i >=0; i--)
    {
        if(a_idx <= i) //超过前面的则没有复制的必要
        {
            break;
        }
        arr[a_idx--] = arr[i];
        if(arr[i] == 0)
        {
            arr[a_idx--] = arr[i];
        }
    };
}

int main()
{
    vector<int> v{9,9,9,4,8,0,0,3,7,2,
                  0,0,0,0,9,1,0,0,1,1,
                  0,5,6,3,1,6,0,0,2,3,
                  4,7,0,3,9,3,6,5,8,9,
                  1,1,3,2,0,0,7,3,3,0,
                  5,7,0,8,1,9,6,3,0,8,
                  8,8,8,0,0,5,0,0,0,3,
                  7,7,7,7,5,1,0,0,8,0,0};
    duplicateZeros(v);
    return 0;
}