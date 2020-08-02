//HUAWEI
//生成有效的括号
// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
#include <vector>
#include <string>
#include <stack>
using namespace std;

//有效性判定
bool is_effective(const string& str)
{
    stack<char> s;
    for(auto c : str)
    {
        if(c == '(')
        {
            s.push(c);
        }
        else
        {
            if(s.empty())
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    };
    if(!s.empty())
    {
        return false;
    }
    else
    {
        return true;
    }
};

//每一个位置都可能添加(或)。
void AddStr(string get_s, vector<string>& vs, int total_num, int cur_num)
{
    if(cur_num > total_num)
    {
        return;
    };

    //处理已经形成的
    if(get_s.length() == total_num && is_effective(get_s) && !get_s.empty())
    {
        vs.push_back(get_s);
    };

    AddStr(get_s + "(", vs,total_num, cur_num + 1);
    AddStr(get_s + ")", vs,total_num, cur_num + 1);
};

vector<string> generateParenthesis(int n) 
{
    vector<string> ret;
    AddStr("",ret,2 * n, 0);
    return ret;
};

// 那么，要生成所有长度为 2 * n 的括号序列，我们定义一个函数 generate(n) 来返回所有可能的括号序列。
// 那么在函数 generate(n) 的过程中：
// 我们需要枚举与第一个 ( 对应的 ) 的位置 2 * i + 1；
// 递归调用 generate(i) 即可计算 a 的所有可能性；
// 递归调用 generate(n - i - 1) 即可计算 b 的所有可能性；
// 遍历 a 与 b 的所有可能性并拼接，即可得到所有长度为 2 * n 的括号序列


int main()
{
    auto ret = generateParenthesis(3);
    return 0;
}