//随时找到数据流中的中位数，插入新数P(lgN),随时查询中位数O(1)
//大根堆和小根堆平分数据

#include <queue> //C++ 优先队列为queue,默认小根堆，less函数为大根堆，greater函数为小根堆
#include <vector>
#include <cstdlib>
#include <stdexcept>
using namespace std;

class MedianFinder 
{
public:
    /** initialize your data structure here. */
    MedianFinder() 
    {
        
    }
    
    void addNum(int num) 
    {
        if(!_gh.empty() && num < _gh.top())
        {
            _gh.push(num);
        }
        else
        {
            _lh.push(num);
        };
        
        //调整堆
        if(abs(static_cast<int>(_gh.size()) - static_cast<int>(_lh.size())) > 1)
        {
            if(_gh.size() > _lh.size())
            {
                int gtop = _gh.top();
                _gh.pop();
                _lh.push(gtop);
            }
            else
            {
                int ltop = _lh.top();
                _lh.pop();
                _gh.push(ltop);
            }
        };
    }
    
    double findMedian() 
    {
        if((_lh.size() + _gh.size()) % 2 == 0)
        {
            return (_lh.top() + _gh.top()) / 2.0;
        }
        else
        {
            return _lh.size() > _gh.size() ? _lh.top() : _gh.top();
        }

    };
private:
    priority_queue<int, vector<int>,greater<int>> _lh; //小根堆
    priority_queue<int, vector<int>, less<int>> _gh; //大根堆
};

int main()
{
    // //2 5 3 1 4 3 7
    // //1 2 3  4 5 7
    // GetMedian m;
    // m.Add(2);
    // m.Add(5);
    // m.Add(3);
    // m.Add(1);
    // m.Add(4);
    // m.Add(7);
    // double a = m.GetMedianAnyTime();
    // return 0;
}

