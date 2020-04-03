//编译计算的逆波兰表示法
//栈
#include <stack>
#include <string>
#include <vector>
using namespace std;

int evalRPN(vector<string>& tokens) 
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