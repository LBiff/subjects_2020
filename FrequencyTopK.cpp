//频率统计TopK
// 给一非空的单词列表，返回前 k 个出现次数最多的单词。
// 返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

struct Node
{
    int _f;
    string _s;
    Node(string s,int f):_f(f),_s(s){};
};
class comparator
{
public:
    bool operator()(const Node& n_1, const Node& n_2)
    {
        return n_1._f > n_2._f || (n_1._f == n_2._f && n_1._s < n_2._s) ? true : false;
    }
};
//静态TopK
//哈希建立频率，k最小堆维护TopK
vector<string> topKFrequent(vector<string>& words, int k)
{
    //map建立词频的索引
    unordered_map<string, int> str_f_map;
    for(auto s : words)
    {
        auto iter = str_f_map.find(s);
        if(iter != str_f_map.end()) 
        {
            iter ->second++;
        }
        else
        {
            str_f_map.insert({s, 1});
        }
    };

    priority_queue<Node, vector<Node>,comparator> h;  //默认k
    for (auto iter = str_f_map.begin(); iter != str_f_map.end(); iter++)
    {
        if(h.size() < k) 
        {
            h.push(Node(iter->first, iter->second));
        }
        else //等于k
        {
            //校验资格
            if(iter->second > h.top()._f)
            {
                h.pop();
                h.push(Node(iter->first, iter->second));
            }
        }
    };

    vector<Node> ret_n;
    while(!h.empty())
    {
        ret_n.push_back(h.top());
        h.pop();
    };
    
    sort(ret_n.begin(), ret_n.end(), comparator());
    vector<string> ret_s;
    for(auto n : ret_n)
    {
        ret_s.push_back(n._s);
    }
    return ret_s;
};



//map找频率，k小根堆堆顶做门槛
class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> ret;
        if(nums.empty() || k < 1)
        {
            return ret;
        };

        //先统计频率
        unordered_map<int,int> map; //value, count
        for(auto i : nums)
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

        //小根堆维护
        priority_queue<pair<int,int>,vector<pair<int,int>>,Comparator> heap; //count, value
        for(auto iter = map.begin(); iter != map.end(); iter++)
        {
            if(heap.size() < k)
            {
                heap.push(pair(iter-> second, iter->first));
            }
            else
            {
                if(iter->second > heap.top().first)
                {
                    heap.pop();
                    heap.push(pair(iter-> second, iter->first));
                }
            }
        };

        auto ht = heap.top();
        stack<int> s;
        while(!heap.empty())
        {
            s.push(heap.top().second);
            heap.pop();
        };

        while(!s.empty())
        {
            ret.push_back(s.top());
            s.pop();
        };

        return ret;
    };
private:
    class Comparator
    {
    public:
        bool operator()(const pair<int,int>& p1, const pair<int,int>& p2)
        {
            return p1.first > p2.first ? true : false;
        };
    };
};


int main()
{
    vector<int> vi{5,3,1,1,1,3,73,1};
    Solution s;
    auto a = s.topKFrequent(vi, 2);
    return 0;
}