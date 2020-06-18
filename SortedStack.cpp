// 栈排序
// 栈排序。 编写程序，对栈进行排序使最小元素位于栈顶。最多只能使用一个其他的临时栈存放数据，
// 但不得将元素复制到别的数据结构（如数组）中。该栈支持如下操作：push、pop、peek 和 isEmpty。
// 当栈为空时，peek 返回 -1。
#include <stack>
using namespace std;

//维护栈的从栈顶到栈底的递增顺序
//每次在push的时候利用临时辅助栈查找插入位置
class SortedStack_1
{
public:
    SortedStack() 
    {

    }

    void push(int val) 
    {
        stack<int> tmp;
        //将比其小的都弹出
       while(!stk.empty() && stk.top() < val)
       {
           tmp.push(stk.top());
           stk.pop();
       };
       stk.push(val);
       while(!tmp.empty())
       {
           stk.push(tmp.top());
           tmp.pop();
       }
    }

    void pop() 
    {
        if(!stk.empty())
        {
            stk.pop();
        }
    }

    int peek() 
    {
       return stk.empty() ? -1 : stk.top();
    }

    bool isEmpty() 
    {
        return stk.empty();
    }
private:
    stack<int> stk;
};


//优化: 不用每次创建辅助栈，用主栈和辅助栈共同维护
//两个栈的递增顺序相反
class SortedStack {
public:
    SortedStack() {

    }
    
    void push(int val) {
        //主栈为空直接入主栈
        if(stk.empty())
        {
            if(help_stk.empty())
            {
                stk.push(val);
            }
            else
            {
                //辅助栈将所有比val大的全部倒进主栈
                while(!help_stk.empty() && help_stk.top() > val)
                {
                    stk.push(help_stk.top());
                    help_stk.pop();
                };
                help_stk.push(val);
            }
        }
        else  //主栈不为空
        {
            if(help_stk.empty())
            {
                //将主栈比其小的全部倒进辅助栈
                while(!stk.empty() && stk.top() < val)
                {
                    help_stk.push(stk.top());
                    stk.pop();
                }
                stk.push(val);
            }
            else
            {
                //两都不为空查找位置
                //从辅助栈里查找位置
                if(stk.top() > val)
                {
                    //辅助栈往主栈倒
                    while(!help_stk.empty() && help_stk.top() > val)
                    {
                        stk.push(help_stk.top());
                        help_stk.pop();
                    };
                    help_stk.push(val);
                }
                else
                {
                    //主栈往辅助栈倒
                    while(!stk.empty() && stk.top() < val)
                    {
                        help_stk.push(stk.top());
                        stk.pop();
                    };
                    stk.push(val);
                }
            }
        }
    }
    
    void pop() {
        //向主栈汇合
        while(!help_stk.empty())
        {
            stk.push(help_stk.top());
            help_stk.pop();
        };
        if(!stk.empty())
        {
            stk.pop();
        };
    }
    
    int peek() {
     //向主栈汇合
        while(!help_stk.empty())
        {
            stk.push(help_stk.top());
            help_stk.pop();
        };
        if(!stk.empty())
        {
            return stk.top();
        };
    }
    
    bool isEmpty() {
        return help_stk.empty() && stk.empty();
    };

private:
    stack<int> stk;
    stack<int> help_stk;
};
