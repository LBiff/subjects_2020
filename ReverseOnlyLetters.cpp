//仅仅反转字母
// 给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
#include <string>
#include<stack>
using namespace std;

//字母入栈反序
//拼接新的时候查看原字符串，非字母从原字符串输出，字母从栈里输出
string ReverseOnlyLetters(string S) 
{
    stack<char> stack;
    for(auto c : S)
    {
        if(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
        {
            stack.push(c);
        }
    };

    string ret;
    for(int i = 0; i < S.size(); i++)
    {
        if(('a' <= S[i] && S[i] <= 'z') || ('A' <= S[i] && S[i] <= 'Z'))
        {
            ret.push_back(stack.top());
            stack.pop();
        }
        else
        {
            ret.push_back(S[i]);
        }
    };
    return ret;
}


