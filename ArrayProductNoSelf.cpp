//除自己外的数乘积
#include <vector>
#include <numeric>
using namespace std;

//解法1：一次遍历求解左累积记录到ret, 反向遍历变量记录右累积
//解法2：一次遍历，对称改写
vector<int> productExceptSelf(vector<int>& nums) 
{
    vector<int> ret(nums.size(), 1);
    size_t n_size = nums.size();
    int l_multi = 1;
    int r_multi = 1;
    for(int i =0; i< n_size; i++)
    {
        ret[i] *= l_multi;
        l_multi *= nums[i];

        ret[n_size - 1 - i] *= r_multi;
        r_multi *= nums[n_size - 1 - i];
    };

    
    return ret;
}