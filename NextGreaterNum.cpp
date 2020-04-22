//下一个更大数
//单调栈
//单调递减栈，从顶到底递减， 每次加新数据如果比栈顶小弹出至比栈顶大

//则采用单调递增栈，请其出栈的元素就是第一个比其大的元素
#include <vector>
#include <stack>
using namespace std;

//从栈顶到栈底的单调递减栈
vector<int> NextGreaterNum(const vector<int>& v)
{
    vector<int> ret(v.size(), 0);
    stack<int> s; //idx
    //将栈顶比其大的都弹出来
    for(int i =0; i<v.size(); i++)
    {
        while(!s.empty() && s.top() > v[i])
        {
            int top_idx = s.top();
            s.pop();
            ret[top_idx] = i;
        };
        s.push(i);
    };

    while(!s.empty())
    {
       int top_idx = s.top();
        s.pop();
        ret[top_idx] = top_idx + 1;
    };

    return ret;
};