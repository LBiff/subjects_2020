//生成窗口最大值数组
//最大更新结构并记录结果
#include <vector>
#include <deque>
using namespace std;

vector<int> GetWindowMax(unsigned int n, unsigned int w, vector<int> v)
{
    deque<unsigned int> q; //双端队列deque 值大->小， 索引小->大
    vector<int> ret;
    for(int i = 0; i< v.size(); i++)
    {
        //右扩
        while(!q.empty() && v[q.back()] <= v[i])
        {
            q.pop_back();
        };
        q.push_back(i);
        //左缩
        if(q.front() == i - w)
        {
            q.pop_front();
        };
        if(i >= w - 1)
        {
            ret.push_back(v[q.front()]);
        }
    };
    return ret;
};

int main()
{
    auto ret = GetWindowMax(8,3,{4,3,5,4,3,3,6,7});
    return 0;
}