//局部最小：数组无序，定义：相邻不等，0比1位置小，则0位局部最小，
//N-1位置比N-2位置小，则N-1为局部最小，如果中间一个数比左右都小，则该数局部最小。

#include  <vector>
#include <stdexcept>
#include <cstdlib>
using namespace std;

//返回局部最小索引
uint64_t GetLocalMin(const vector<int> v)
{
    if(v.size() < 2)
    {
        throw invalid_argument("v must greater than 1");
        return -1;
    };

    if(v[0] < v[1])
    {
        return 0;
    }
    else if(v[v.size() -1] < v[v.size() - 2])
    {
        return v.size() -1;
    }

    bool l_is_up = false;
    bool r_is_up = true;
    bool middle_l_is_up = false;
    bool middle_r_is_up = false;
    int l_idx = 0;
    int r_idx = v.size() - 1;
    int middle_idx = l_idx + (r_idx - l_idx) / 2;
    while(middle_idx != l_idx && middle_idx != r_idx)  //最后剩两个
    {
        middle_l_is_up = v[middle_idx] > v[middle_idx - 1] ? true : false;
        middle_r_is_up = v[middle_idx] > v[middle_idx + 1] ? false : true;
        if(!middle_l_is_up && middle_r_is_up)
        {
            return middle_idx;
        };

        if(middle_l_is_up) //选择左边
        {
            r_idx = middle_idx;
            middle_idx = l_idx + (r_idx - l_idx) / 2;
        }
        else if(!middle_r_is_up)
        {
            l_idx = middle_idx;
            middle_idx = l_idx + (r_idx - l_idx) / 2;
        }
        // else //左降右升已返回
        // {
            
        // }
    }
}


int main()
{
    vector<int> a{2,1,5};
    uint64_t b = GetLocalMin(a);
    return 0;
}
