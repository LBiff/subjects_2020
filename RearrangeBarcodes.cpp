// 条形码的重排列
// 在一个仓库里，有一排条形码，其中第 i 个条形码为 barcodes[i]。
// 请你重新排列这些条形码，使其中两个相邻的条形码 不能 相等。 你可以返回任何满足该要求的答案，
// 此题保证存在答案。
// 示例 1：
// 输入：[1,1,1,2,2,2]
// 输出：[2,1,2,1,2,1]
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// 1、获取数据中出现次数最多的值，把该值依次填入奇数位
// 2、填满奇数位
// 3、填满偶数位

class Comparator
{
public:
    bool operator()(const pair<int,int>& p1, const pair<int,int>& p2)
    {
        return p1.second < p2.second ? true : false;
    }
};

vector<int> rearrangeBarcodes(vector<int>& barcodes) 
{
    unordered_map<int,int> map; //<value, count>
    for(auto i : barcodes)
    {
        auto iter = map.find(i);
        if(iter != map.end())
        {
            iter->second++;
        }
        else
        {
            map.insert({i, 1});
        }
    };

    priority_queue<pair<int,int>,vector<pair<int,int>>,Comparator> q; //大根堆 <value, count>
    for(auto iter = map.begin(); iter != map.end(); iter++)
    {
        q.push({iter->first, iter->second});
    }; 

    vector<int> ret(barcodes.size());
    //西安进行奇数位填充后偶数位
    int idx = 1;
    pair<int,int> cur_pair;
    bool size_odd = ret.size() % 2 == 1; //个数是奇数
    while(!q.empty())
    {
        auto top = q.top();
        q.pop();
        int top_count = top.second;
        while(top_count-- > 0)
        {
            idx >= ret.size() ? (size_odd ? ret[idx - ret.size()] = top.first  : ret[idx - ret.size() - 1] = top.first)
                                : ret[idx] = top.first;
            idx += 2;
        }
    }
    return ret;
};

int main()
{
    vector<int> v{1,0,2};
    auto ret = rearrangeBarcodes(v);
    return 0;
}