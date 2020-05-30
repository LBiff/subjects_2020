//马戏团人塔
// 有个马戏团正在设计叠罗汉的表演节目，一个人要站在另一人的肩膀上。
// 出于实际和美观的考虑，在上面的人要比下面的人矮一点且轻一点。已知马戏团每个人的身高和体重，
// 请编写代码计算叠罗汉最多能叠几个人。

#include <vector>
#include <algorithm>
using namespace std;

//先按身高排序，后查找体重的最长递增不连续子序列
int bestSeqAtIndex(vector<int>& height, vector<int>& weight) 
{
    if(height.empty())
    {
        return 0;
    }
    vector<pair<int,int>> h_w_v;
    for(int i = 0; i < height.size(); i++)
    {
        h_w_v.push_back({height[i],weight[i]});
    };

    //身高升序排序, 若身高相同则按体重降序排，避免后续查找体重的最长子序列
    auto comparator = [](const pair<int,int>& p1, const pair<int,int>& p2)
    {
        return p1.first < p2.first ? true :  (p1.first == p2.first && p1.second > p2.second ? true : false);
    };

    sort(h_w_v.begin(), h_w_v.end(), comparator);

    //查找体重second递增的最长子序列的长度
    //二分O(nlgn)
    // 首先，给你一排扑克牌，我们像遍历数组那样从左到右一张一张处理这些扑克牌，最终要把这些牌分成若干堆。
    // 处理这些扑克牌要遵循以下规则：
    // 只能把点数小的牌压到点数比它大的牌上。如果当前牌点数较大没有可以放置的堆，则新建一个堆，把这张牌放进去。
    // 如果当前牌有多个堆可供选择，则选择最左边的堆放置。
    // 比如说上述的扑克牌最终会被分成这样 5 堆（我们认为 A 的值是最大的，而不是 1）。
    // 为什么遇到多个可选择堆的时候要放到最左边的堆上呢？因为这样可以保证牌堆顶的牌有序（2, 4, 7, 8, Q），证明略。
    // 按照上述规则执行，可以算出最长递增子序列，牌的堆数就是最长递增子序列的长度，证明略。
    // 我们只要把处理扑克牌的过程编程写出来即可。每次处理一张扑克牌不是要找一个合适的牌堆顶来放吗，
    // 牌堆顶的牌不是有序吗，这就能用到二分查找了：用二分查找来搜索当前牌应放置的位置。

    //二分查找大于等于v的最左位置
    auto BinFindIdx = [](const vector<int>& h, int v) -> int
    {
        int l = 0;
        int r = static_cast<int>(h.size()) - 1;
        int min_idx = INT_MAX;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(h[mid] >= v)
            {
                min_idx = min(min_idx, mid);
                r = mid - 1;
            }
            else if(h[mid] < v)
            {
                l = mid + 1;
            }
        };

        return min_idx;
    };
    vector<int> heap;
    for(int j= 0; j < h_w_v.size(); j++)
    {
        int min_idx = BinFindIdx(heap, h_w_v[j].second);
        if(min_idx == INT_MAX)
        {
            heap.push_back(h_w_v[j].second);
        }
        else
        {
            heap[min_idx] = h_w_v[j].second;
        }
    };
    return heap.size();
};

int main()
{
    vector<int> height{65,70,70,75,60,68};
    vector<int> weight{100,90,100,190,95,110};
    auto ret = bestSeqAtIndex(height, weight);
    return 0;
}
