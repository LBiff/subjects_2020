//字符串相加
// 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
// 注意：
// num1 和num2 的长度都小于 5100.
// num1 和num2 都只包含数字 0-9.
// num1 和num2 都不包含任何前导零。
// 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。

#include <string>
using namespace std;

string addStrings(string num1, string num2) 
{
    int max_length = num1.length() > num2.length() ? num1.length() :  num2.length();
    string ret;
    ret.resize(max_length);

    int over_flow = 0; //溢出值
    int n1_idx = num1.length() - 1;
    int n2_idx = num2.length() - 1;
    int ret_idx = max_length - 1;
    while(n1_idx >= 0||  n2_idx >= 0)
    {
        over_flow = n1_idx >= 0 ? over_flow + (num1[n1_idx] - '0') : over_flow;
        over_flow = n2_idx >= 0 ? over_flow + (num2[n2_idx] - '0') : over_flow;
        ret[ret_idx] = (over_flow % 10) + '0';
        over_flow = over_flow / 10;
        n1_idx--;
        n2_idx--;
        ret_idx--;
    };
    if(over_flow)
    {
       ret = '1' + ret;
    }
    return ret;
};


int main()
{
    string a = "9";
    string b = "99";
    string c = addStrings(a, b);
    return 0;
}
