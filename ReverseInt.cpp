//整数反转
#include <algorithm>
using namespace std;

int reverse(int n)
{
    int ret = 0;
    bool is_negitive = n < 0;
    n = abs(n);
    while(n > 0)
    {
        int bit = n % 10;
        if((ret < (INT_MAX / 10))
            || ((ret == (INT_MAX / 10)) && (bit <= (INT_MAX % 10))))
        {
            ret *= 10;
            ret += n % 10;
            n /= 10;
        }
        else
        {
            return 0;
        }
    };
    return is_negitive ? -ret : ret;
};

int main()
{
    int i = reverse(123);
    return 0;
}