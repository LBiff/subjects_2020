 //1095  
// 给你一个 山脉数组 mountainArr，请你返回能够使得 mountainArr.get(index) 
// 等于 target 最小 的下标 index 值。
// 如果不存在这样的下标 index，就请返回 -1。

//先二分查找峰值，峰值就是比左右都大
//二分在左边查
//二分在右边查

#include <algorithm>
#include <vector>
using namespace std;
class MountainArray 
{
public:
    int get(int index){return _v[index];};
    int length() {return _v.size();};
    MountainArray(vector<int> v) : _v(v){};

    vector<int> _v;
};
// 1.二分查找峰值
//二分找数
int findInMountainArray(int target, MountainArray &mountainArr) 
{
    int len = mountainArr.length();
    int l = 0;
    int r = len - 1;
    int mid = -1;
    while(l <= r)
    {
        mid = l +  (r - l) / 2;
        int mid_v = mountainArr.get(mid);
        int less_1 = mid > 0 ? mountainArr.get(mid - 1) : -1;
        int greater_1 = mid + 1 < len ? mountainArr.get(mid + 1) : -1;

        if(less_1 != -1 && greater_1 != -1 && mid_v > less_1 && mid_v > greater_1)
        {
            break;
        }
        else if(mid_v > less_1) //top在右半边
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    };
    if(mid == -1) //没有峰顶
    {
        return -1;
    };

    //先在左边查找
    int l_1 = 0;
    int r_1 = mid;
    int min_idx = len;
    while(l_1 <= r_1)
    {
        int mid_1 = l_1 + (r_1 - l_1) / 2;
        int mid_1_v = mountainArr.get(mid_1);
        if(mid_1_v == target)
        {
            min_idx = mid_1;
            break;
        }
        else if(mid_1_v > target)
        {
            r_1 = mid_1 - 1;
        }
        else
        {
            l_1 = mid_1 + 1;
        }
    };
    if(min_idx != len)
    {
        return min_idx;
    }
    else
    {
        int l_2 = mid;
        int r_2 = len - 1;
        while(l_2 <= r_2)
        {
            int mid_2 = l_2 + (r_2 - l_2) / 2;
            int mid_2_v = mountainArr.get(mid_2);
            if(mid_2_v == target)
            {
                min_idx = mid_2;
                break;
            }
            else if(mid_2_v > target)
            {
                l_2 = mid_2 + 1;
            }
            else
            {
                r_2 = mid_2 - 1;
            }
        };
        if(min_idx != len)
        {
            return min_idx;
        }
        else
        {
            return -1;
        }
    }
};


int main()
{
    vector<int> v{1,2,3,4,5,3,1};
    MountainArray m(v);
    auto ret = findInMountainArray(3,m);
    return 0;
}




