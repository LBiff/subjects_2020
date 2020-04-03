//递归逆序栈，不使用额外的数据结构
#include <stack>
#include <functional>
#include <vector>
using namespace std;

void ReverseStack(stack<int>& s)
{
    if(s.empty())
    {
        return;
    }
    //获取并删除栈底元素并返回
    function<int(stack<int>&)> GetStackBottomAndRemove;
    GetStackBottomAndRemove = [&](stack<int>& s) -> int
    {
        int re = s.top();
        s.pop();
        if(s.empty())
        {
            return re;
        }
        else
        {
            int last = GetStackBottomAndRemove(s);
            s.push(re);
            return last;
        }
    };

    int last = GetStackBottomAndRemove(s);
    ReverseStack(s);
    s.push(last);
};

//数组栈
vector<int> reverseStackRecursively(vector<int> stack, int top) 
{
    if(stack.empty())
    {
        return stack;
    };
    function<int(vector<int>&)> GetAndRemoveLastEle;
    GetAndRemoveLastEle = [&](vector<int>& stack)->int
    {
        if(!stack.empty())
        {
            int top = stack.back();
            stack.pop_back();
            if(stack.empty())
            {
                return top;
            }
            else
            {
                int last = GetAndRemoveLastEle(stack);
                stack.push_back(top);
                return last;
            }
        }
    };
    
    int last = GetAndRemoveLastEle(stack);
    auto s = reverseStackRecursively(stack,top - 1);
    s.push_back(last);
    return s;
}

int main()
{
    vector<int> v{1,2,3,4,5};
    auto ret = reverseStackRecursively(v,5);
    return 0;
}
