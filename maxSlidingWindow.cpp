// 给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

#include <vector>
#include <queue>
using namespace std;

//最大最小更新结构
// 借助一个双端队列，保存窗口内的数的在数组中的下标。
// 当窗口新增一个数，若 队列为空 或 该数大于等于队尾表示的数，则队尾弹出，继续进行判断；若该数小于队尾表示的数，将该数的下标从队尾进队。
// 当窗口减少一个数，判断队头是否过期，过期则队头出队。
// 窗口内最大值即为队头表示的数。


//最大更新结构，向右扩展，从左收缩, 从右边进将所有小的均弹出，从左边缩将所有过期的删掉

vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
    vector<int> ret;
    if(k > nums.size() || nums.empty())
    {
        return ret;
    }
    deque<pair<int,int>> q;  //<int,idx>
    //先扩展出k的滑动窗口
    for(int i = 0; i < k; i++)
    {
        if(q.empty())
        {
            q.push_back({nums[i], i});
        };
        //从后边进，将所有比其小的均弹出
        while(!q.empty() && nums[i] > q.back().first)
        {
            q.pop_back();
        };
        q.push_back({nums[i], i});
    };

    ret.push_back(q.front().first);
    for(int i = k; i < nums.size(); i++)
    {
        //向右边扩展
        if(q.empty())
        {
            q.push_back({nums[i], i});
        };
        //从后边进，将所有比其小的均弹出
        while(!q.empty() && nums[i] > q.back().first)
        {
            q.pop_back();
        };
        q.push_back({nums[i], i});

        //从左边缩小一个
        int del_idx = i - k;
        while(!q.empty() && q.front().second <= del_idx)
        {
            q.pop_front();
        };

        ret.push_back(q.front().first);
    };

    return ret;
};

int main()
{
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    int k = 3;
    auto ret = maxSlidingWindow(nums,k);
    return 0;
}
