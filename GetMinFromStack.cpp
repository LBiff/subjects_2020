//O(1)时间从栈中获取最小元素
#include <stack>
using namespace std;

class MinStack 
{
public:
    /** initialize your data structure here. */
    MinStack() 
    {

    }
    
    void push(int x) 
    {
        if(_s.empty())
        {
            _min_s.push(x);
        }
        else
        {
            int min_top = _min_s.top();
            x < min_top ? _min_s.push(x) : _min_s.push(min_top);
        }
         _s.push(x);
    }
    
    void pop() 
    {
        _s.pop();
        _min_s.pop();
    };
    
    int top() 
    {
        return _s.top();
    };
    
    int getMin() 
    {
        return _min_s.top();
    };
    stack<int> _s;
    stack<int> _min_s;
};