// 从中间折断的上升序列中查找target
// [8,9,10,3,4,5,6]
#include <vector>
using namespace std;

bool Find(const vector<int>& v, int target)
{
    if(v.empty())
    {
        return false;
    }
    else if(v.size() == 1)
    {
        return v[0] == target;
    };
    int l_idx = 0;
    int r_idx = v.size() - 1;
    while(l_idx <= r_idx)
    {
        int mid = l_idx + (r_idx - l_idx) / 2;
        if(v[mid] == target)
        {
            return true;
        };

        if(v[l_idx] < v[r_idx])  //整个区间递增,正常二分
        {
            if(v[mid] > target)
            {
                r_idx = mid - 1;
            }
            else
            {
                l_idx = mid + 1;
            }
        }
        else //跨递增区间
        {
            if(target < v[0]) //target在第二递增区间
            {
                if(v[mid] < v[0]) //mid也在第二递增区间
                {
                    if(v[mid] < target)
                    {
                        l_idx = mid + 1;
                    }
                    else
                    {
                        r_idx = mid - 1;
                    }
                }
                else  //mid在第一递增区间
                {
                   l_idx = mid + 1;
                }
            }
            else //target在第一递增区间
            {
                if(v[mid] < v[0]) //mid在第二递增区间
                {
                    r_idx = mid - 1;
                }
                else  //mid在第一递增区间
                {
                   if(v[mid] < target)
                    {
                        l_idx = mid + 1;
                    }
                    else
                    {
                        r_idx = mid - 1;
                    }
                }
            }
        }
    };

    return false;
};

int main()
{
    vector<int> v{8,9,10,3,4,5,6};
    auto ret = Find(v, 7);
    return 0;
}
