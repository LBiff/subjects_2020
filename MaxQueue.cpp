// II. 队列的最大值
// 请定义一个队列并实现函数 max_value 得到队列里的最大值，
// 要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
// 若队列为空，pop_front 和 max_value 需要返回 -1

//双端队列
//原队列正常进出
//双端队列维持从队头到队尾不递增
#include <queue>
#include <deque>
using namespace std;

class MaxQueue 
{
public:
    MaxQueue() 
    {

    }
    
    //直接从dq前取
    int max_value() 
    {
        return dq.empty() ? -1 : dq.front();
    }
    
    //q正常加入，de需要保持front->back不递增，则将比value小的全部弹出,后加入
    void push_back(int value) 
    {
        q.push(value);
        //双端队列从后面入将比其小的全部弹出
        while(!dq.empty() && dq.back() < value)
        {
            dq.pop_back();
        };
        dq.push_back(value);
    }
    
    //都从前面出，如果q出的和dq.front()相同，则dq也出
    int pop_front() 
    {
        if(q.empty())
        {
            return -1;
        };
        int f = q.front();
        q.pop();
        if(f == dq.front())
        {
            dq.pop_front();
        };
        return f;
    };
private:
    queue<int> q; //正常队列
    deque<int> dq; //维护max的双端队列
};
