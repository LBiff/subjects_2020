//计算器的实现

#include "MidConvertToPost.cpp"
#include "EvalRPN.cpp"
using namespace std;

//输入中缀表达式
int Calculator(string mid_s)
{
    return evalRPN(MidConvertToPost(mid_s));
}

