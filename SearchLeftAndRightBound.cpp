//搜索排序数组target的左边界

#include <vector>
#include <cstdlib>
using namespace std;

//左边界的问题:正常二分查找，找到更新，向左压缩区间
int GetLeftBound(vector<int> v, int target)
{
    if(v.empty())
    {
        return -1;
    }
    int min_l = INT_MAX;
    //[]区间
    int l = 0;
    int r = v.size() - 1;
    int mid = l + (r - l) / 2;
    while(l <= r)
    {
        mid =  l + (r - l) / 2;
        if(v[mid] == target)  //找到区间向左压缩继续找
        {
///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            r = mid - 1;    //重点！！！！！！！！！
///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            if(mid < min_l)
            {
                min_l = mid;
            }
        }
        else if(v[mid] > target)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    };

    return min_l == INT_MAX ? -1 : min_l;
};

//右边界的问题:正常二分查找，找到更新，向右压缩区间
int GetRightBound(vector<int> v, int target)
{
    if(v.empty())
    {
        return -1;
    }
    int min_r = INT_MIN;
    //[]区间
    int l = 0;
    int r = v.size() - 1;
    int mid = l + (r - l) / 2;
    while(l <= r)
    {
        mid =  l + (r - l) / 2;
        if(v[mid] == target)  //找到区间向左压缩继续找
        {
///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            l = mid + 1;    //重点！！！！！！！！！
///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            if(mid > min_r)
            {
                min_r = mid;
            }
        }
        else if(v[mid] > target)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    };

    return min_r == INT_MIN ? -1 : min_r;
};


int main()
{
    vector<int> a{1,2,3,3,3,4};
    int c = GetRightBound(a, 3);
    return 0;
}
