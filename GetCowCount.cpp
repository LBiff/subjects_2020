//获取母牛数量
//母牛每年能生一只母牛，新生的母牛三年后也能生一只母牛，求N年后母牛的数量
#include <cstdlib>
using namespace std;

uint64_t GetCowCount(uint64_t years)
{
    if(years < 4)
    {
        return years;
    };
 
    return GetCowCount(years - 1) + GetCowCount(years - 3);
};


int main()
{
    uint64_t a = GetCowCount(6);
    return 0;
}