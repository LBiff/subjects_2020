//中缀表达式转换为后缀表达式
// 前缀表达式是后缀的逆序

//中缀表达式转换为后缀表达式（逆波兰表达式）
//op栈保存运算符号 +-*/()

//依次遍历
//操作数直接输出
//(直接入op
//)op弹出至(输出，(弹出不输出，)忽略，，()不参与输出
// +- 将*/弹出输出直到左括号，
// */ 弹出所有的*/输出直到左括号或+-

//总原则
//1.操作数直接输出
//2. (直接入栈
//3. )弹出至左括号，左括号弹出
//4. 操作符直接弹出至比其优先级小的直到(
    //可以理解为 ( > */ > +-

#include <string>
#include <stack>
#include <vector>
using namespace std;
//ans栈
vector<string> MidConvertToPost(string mid_str)
{
    vector<string> ret;
    stack<char> op; //操作符
    for(int i =0; i < mid_str.size(); i++)
    {
        //操作数直接输出
        char cur_c = mid_str[i];
        bool is_num = (mid_str[i] >= '0' && mid_str[i] <= '9') || (mid_str[i] >= 'a' && mid_str[i] <= 'z');
        if(is_num)
        {
            string n;
            n += mid_str[i];
            int idx = i + 1;
            for(; idx< mid_str.size(); idx++)
            {
                int cur = mid_str[idx];
                if((mid_str[idx] >= '0' && mid_str[idx] <= '9') || (mid_str[idx] >= 'a' && mid_str[idx] <= 'z'))
                {
                    n += mid_str[idx];
                }
                else
                {
                    break;
                }
            };
            i = idx - 1;
            ret.push_back(n);
        }
        else if(mid_str[i] == '(')  //左括号直接入op栈
        {
            op.push(mid_str[i]);
        }
        else if(mid_str[i] == ')') //右括号将op栈(前的所有运算符弹入到ans，左右括号消失
        {
            while(!op.empty() && op.top() != '(')
            {
                string tmp;
                tmp += op.top();
                ret.push_back(tmp);
                op.pop();
            };
            if(!op.empty() && op.top() == '(')
            {
                op.pop();
            }
        }
        else if(mid_str[i] == '+' || mid_str[i] == '-' || 
                mid_str[i] == '*' || mid_str[i] == '/')  //运算符
        {
            if(mid_str[i] == '+' || mid_str[i] == '-') //弹出直到"("
            {
                while(!op.empty() && op.top() != '(')
                {
                    string tmp;
                    tmp += op.top();
                    ret.push_back(tmp);
                    op.pop();
                };
            }
            else //将低优先级弹出输出
            {
                while(!op.empty() && ((op.top() == '*') || (op.top() == '/')) && op.top() != '(')  //将*/弹出直到(
                {
                    string tmp;
                    tmp += op.top();
                    ret.push_back(tmp);
                    op.pop();
                };
            }
            op.push(mid_str[i]);
        }
    };

    //op全部弹出入ans
    while(!op.empty())
    {
        string tmp;
        tmp += op.top();
        ret.push_back(tmp);
        op.pop();
    };
    return ret;
};

int main()
{
    string mid = "a+b*c/d-a+f/b"; //
    auto ret = MidConvertToPost(mid);
    return 0;
}