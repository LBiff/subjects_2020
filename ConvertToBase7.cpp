//整数转换为7进制
#include <string>
#include <algorithm>
using namespace std;

string convertToBase7(int num) 
{
    if(num == 0)
    {
        return "0";
    };
    bool is_negative = num < 0 ? true : false;
    num = abs(num);
    string ret;
    while(num != 0)
    {
        ret += ('0' + num % 7);
        num /= 7;
    };
    reverse(ret.begin(), ret.end());
    ret = is_negative ? "-"+ ret : ret;
    return ret;
};

int main()
{
    auto ret = convertToBase7(-7);
    return 0;
}
