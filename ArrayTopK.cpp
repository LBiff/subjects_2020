//在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，
//而不是第 k 个不同的元素。
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int findKthLargest(vector<int>& nums, int k) 
{
    priority_queue<int,vector<int>,greater<int>> q; //小根堆
    int idx = 0;
    for(; idx< k; idx++)
    {
        q.push(nums[idx]);
    };
    int t = q.top();
    
    while(k < nums.size())
    {
        if(nums[k] >= q.top())
        {
            q.pop();
            q.push(nums[k]);
        }
        k++;
    };
    
    return q.top();
};

int main()
{
    vector<int> a{3,2,1,5,6,4};
    int ret = findKthLargest(a,2);
    return ret;
}