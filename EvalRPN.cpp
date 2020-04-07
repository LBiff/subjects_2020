//编译计算的逆波兰表示法
// 有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
// 说明：
// 整数除法只保留整数部分。
// 给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
// 示例 1：
// 输入: ["2", "1", "+", "3", "*"]
// 输出: 9
// 解释: ((2 + 1) * 3) = 9
// 示例 2：

//栈
#include <stack>
#include <string>
#include <vector>
using namespace std;

int evalRPN(const vector<string>& tokens) 
{
    stack<int> s;
    for(auto str : tokens)
    {
        if(str != "+" && str != "-" && str != "*" && str != "/") //数字入栈
        {
            s.push(atoi(str.c_str()));
        }
        else
        {
            int r = s.top();
            s.pop();
            int l = s.top();
            s.pop();
            int ret;
            if(str == "+")
            {
                ret = l + r;
            }
            else if(str == "-")
            {
                ret = l - r;
            }
            else if(str == "*")
            {
                ret = l * r;
            }
            else
            {
                ret = l / r;
            }
            s.push(ret);
        }
    };
    return s.top();
}