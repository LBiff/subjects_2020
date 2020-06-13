// 求众数 II
// 给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
// 说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。
// 示例 1:
// 输入: [3,2,3]
// 输出: [3]
// 示例 2:
// 输入: [1,1,1,3,3,2,2,2]
// 输出: [1,2]
    
#include <vector>
using namespace std;
//摩尔投票算法
//https://www.zhihu.com/question/49973163
//超过1/3最多有两个人
vector<int> majorityElement(vector<int>& nums) 
{
    //每次保证3个进行pk
    int cur_1 = 0;
    int count_1 = 0;
    int cur_2 = 0;
    int count_2 = 0;

    //投票阶段
    for(auto n : nums)
    {
        if(n == cur_1 && count_1 > 0)
        {
            count_1 += 1;
            continue;
        };
        if(n == cur_2 && count_2 > 0)
        {
            count_2 += 1;
            continue;
        };

        //三个都不相等则相互抵消，更新现存
        if(count_1 == 0)
        {
            cur_1 = n;
            count_1 = 1;
            continue;
        };
        if(count_2 == 0)
        {
            cur_2 = n;
            count_2 = 1;
            continue;
        };

        //三个都不相等且现有2个，全部抵消现有-1
        count_1--;
        count_2--;
    };
    //检验，比如说{3,2,3} ,输出{3,2}
    count_1 = 0;
    count_2 = 0;
    for(auto n : nums)
    {
        if(n == cur_1)
        {
            count_1 += 1;
            continue;
        };
        if(n == cur_2)
        {
            count_2 += 1;
            continue;
        }
    };
    int get_count = nums.size() / 3;
    vector<int> ret;
    if(count_1 > get_count)
    {
        ret.push_back(cur_1);
    };
    if(count_2 > get_count)
    {
        ret.push_back(cur_2);
    };

    return ret;
};

int main()
{
    vector<int> v{2,2,1,3};
    auto ret = majorityElement(v);
    return 0;
}