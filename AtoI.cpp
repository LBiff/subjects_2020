//字符串转整数
#include <string>
#include <queue>
using namespace std;

int myAtoi(string str) 
{
    priority_queue<int> a;
    
    unsigned int ret = 0; //注意用unsigned int,int正负不对称
    //去除前面无用符号
    int idx = 0;
    bool is_negitive = false;
    while(idx < str.length())
    {
        if(str[idx] == ' ')
        {
            idx++;
        }
        else if(str[idx] == '-' || str[idx] == '+')
        {
            is_negitive = (str[idx] == '-') ? true : false;
            idx++;
            break;
        }
        else if('0' <= str[idx] && str[idx] <= '9')
        {
            break;
        }
        else //非法字符
        {
            return ret;
        }
    };
    //寻找连续数字
    while(idx < str.length())
    {
        if((str[idx] >= '0') && (str[idx] <= '9'))
        {
            //int 正负不对称
            unsigned int max = is_negitive ? 
                                static_cast<unsigned int>(abs(INT_MIN)) 
                                : static_cast<unsigned int>(INT_MAX);
            if(ret < (max / 10) || (ret == (max / 10) && ((str[idx] - '0') <= (max % 10))))
            {
                ret *= 10;
                ret += (str[idx] - '0');
                idx++;
            }
            else
            {
                return is_negitive ? INT_MIN : INT_MAX;
            }
        }
        else
        {
            return is_negitive ? -ret : ret;
        }
    };
    return is_negitive ? -ret : ret;
};

int main()
{
    string s = "+-2";
    int a = myAtoi(s);
    return 0;
}

