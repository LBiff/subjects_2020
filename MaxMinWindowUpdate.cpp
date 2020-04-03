//最大最小窗口更新结构

#include <deque>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <stdexcept>
#include <iostream>
using namespace std;

//最大更新结构
//T 为容器
//最大更新结构== 双端队列值升序，队列加数从后面加（>=加数的弹出）， 队列减数从前面减去索引过期的
template<typename T>
class MaxWindowUpdate
{
typedef typename T::value_type _value_type;
public:
//初始化窗口为1
MaxWindowUpdate(T t)
{
    if(t.empty())
    {
        throw invalid_argument("argument must not empty!!");
    }
    _l_iter = t.begin();
    _l_idx  = 0;
    _r_iter = t.begin();
    _r_idx = 0;
    _t = t;
    _deque.push_front(make_pair(*(t.begin()), 0));
}

_value_type GetMax()
{
    if(!_deque.empty())
    {
        return _deque.front().first;
    }
    
};

//左向右移动1--减少数
bool LMove_1()
{
    if(_l_idx + 1 > _r_idx)
    {
        return false;
    }
    else
    {
        _l_idx++;
        deque<pair<int, uint64_t>>::iterator iter = _deque.begin();
        while(iter != _deque.end()  && iter->second < _l_idx)
        {
            _deque.pop_front();
            iter++;
        };
        return true;
    }
};

//右向右移动1--加数
bool RMove_1()
{
    if(_r_idx + 1 < _t.size())
    {
        _r_idx++;
        //从后面加
        deque<pair<int, uint64_t>>::iterator iter = _deque.end() - 1;
        _value_type value = *(_t.begin() + _r_idx);
        while(!_deque.empty() && iter->first <= value)
        {
            _deque.pop_back();
            iter--;
        };
        _deque.push_back(make_pair(value, _r_idx));
        return true;
    }
    else
    {
        return false;
    }
}

private:
    T _t;
    deque<pair<_value_type, uint64_t>> _deque; //双端队列 <value,tag>
    typename T::iterator _l_iter; //左迭代器 [
    size_t _l_idx;
    typename T::iterator _r_iter; //右迭代器 ]
    size_t _r_idx;
};

int main()
{
    vector<int> v{4,3,5,4,3,3,6,7};
    MaxWindowUpdate<vector<int>> a(v);
    int b;
    a.RMove_1();
    a.RMove_1();
    size_t idx = 2;
    while(idx < v.size())
    {
        cout << a.GetMax() << endl;
        a.LMove_1();
        a.RMove_1();
        idx++;
    }


    return 0;
}