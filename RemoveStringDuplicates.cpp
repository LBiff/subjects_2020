// 删除字符串中的所有相邻重复项
// 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
// 在 S 上反复执行重复项删除操作，直到无法继续删除。
// 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
#include <string>
#include <stack>
using namespace std;

//用栈
string removeDuplicates(string S) 
{
    stack<char> stk;
    for(auto c : S)
    {
        if(!stk.empty() && stk.top() == c)
        {
            stk.pop();
        }
        else
        {
            stk.push(c);
        }
    };

    string ret;
    while(!stk.empty())
    {
        ret = stk.top() + ret;
        stk.pop();
    }
    return ret;
}
