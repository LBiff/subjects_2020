//括号匹配
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
// 有效字符串需满足：
// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。

//用栈，只压左括号，遇到右括号和栈顶比较，对应则弹出
//原理：有括号匹配的是最近的左括号
#include <string>
#include <stack>
using namespace std;

bool isValid(string s) 
{
    stack<char> _stack;
    for(auto c : s)
    {
        bool is_left = (c == '(' || c == '[' || c == '{');
        if(is_left)
        {
            _stack.push(c);
        }
        else //右括号
        {
            if(_stack.empty())
            {
                return false;
            };
            char top = _stack.top();
            if((top == '[' && c == ']')
                ||(top == '(' && c == ')')
                ||(top == '{' && c == '}'))
                {
                    _stack.pop();
                }
                else
                {
                    return false;
                }
        };
    };
    return _stack.empty() ? true : false;
}