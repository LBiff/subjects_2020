//HUAWEI
// 给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。
// 数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，
// 这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。

//前后单调栈
#include <vector>
#include <stack>
using namespace std;
vector<int> nextGreaterElements(vector<int>& nums) 
{
    vector<int> v = nums;
    v.insert(v.begin(), nums.begin(), nums.end());

    stack<int> s;
    vector<int> s_e_v(v.size(), -1);
    for(int i = 0; i < v.size(); i++)
    {

        while(!s.empty() && v[s.top()] < v[i])
        {
            int top = s.top();
            s_e_v[top] = v[i];
            s.pop();
        };
        s.push(i);
    };

    vector<int> ret(nums.size(), -1);
    for(int i = 0; i< nums.size(); i++)
    {
        if(s_e_v[i] != -1)
        {
            ret[i] = s_e_v[i];
        }
    };
    return ret;
};

int main()
{
    vector<int> v{1,2,1};
    auto ret = nextGreaterElements(v);
    return 0;
};