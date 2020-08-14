//移掉k位数字，使最终最小
// 给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。
// 注意:
// num 的长度小于 10002 且 ≥ k。
// num 不会包含任何前导零。
#include <string>
#include <stack>
using namespace std;

// 输入: num = "1432219", k = 3
// 输出: "1219"
string removeKdigits(string num, int k) 
{
    //保持栈内严格从底到顶递增
    stack<char> s;
    for(auto c : num)
    {
        while(!s.empty() && k > 0 && s.top() > c)
        {
            s.pop();
            k -= 1;
        }
        s.push(c);
    };

    //移除多余的
   for(int i = 0; i < k; i++)
   {
       s.pop();
   };

    string ret;
    //反序输出
    while(!s.empty())
    {
        ret = to_string(s.top() - '0') + ret;
        s.pop();
    };
    //删除所有的前置0
    int idx = 0;
    while(idx < ret.size() && ret[idx] == '0')
    {
        idx++;
    };
    ret = ret.substr(idx);
    return ret.empty() ? "0" : ret;
};


int main()
{
    string num = "1432219";
    int k = 3;
    auto ret = removeKdigits(num, k);
    return 0;
}

