//二进制字符串相加
#include <string>
using namespace std;

string addBinary(string a, string b) 
{
    string ret;

    int idx_1 = a.size() - 1;
    int idx_2 = b.size() - 1;
    int over_flow = 0;
    while(idx_1 >= 0 && idx_2 >= 0)
    {
        over_flow += (a[idx_1] - '0');
        over_flow += (b[idx_2] - '0');
        ret = to_string(over_flow % 2) + ret;
        over_flow /= 2;
        idx_1--;
        idx_2--;
    };

    while(idx_1 >= 0)
    {
        over_flow += a[idx_1] - '0';
        ret = to_string(over_flow % 2) + ret;
        over_flow /=2;
        idx_1--;
    };
    while(idx_2 >= 0)
    {
        over_flow += (b[idx_2] - '0');
        ret = to_string(over_flow % 2) + ret;
        over_flow /=2;
        idx_2--;
    };
    if(over_flow)
    {
        ret = "1" + ret;
    };

    return ret;
};

int main()
{
    addBinary("1", "111");
    return 0;
}