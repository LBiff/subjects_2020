//快乐数
#include<cmath>
using namespace std;

//环检测
class Solution 
{
public:
    //快慢指针判断环
    bool isHappy(int n) 
    {
        int low = CalPow(n);
        int fast = CalPow(low);
        while(low != fast && fast != 1)
        {
            low = CalPow(low);
            fast = CalPow(fast);
            fast = CalPow(fast);
        };
        return fast == 1 ? true : false;
    };

    int CalPow(int n)
    {
        int ret = 0;
        while(n > 0)
        {
            ret += pow(n % 10, 2);
            n /= 10;
        };
        return ret;
    }
};

int main()
{
    int i = 19;
    Solution s;
    auto ret = s.isHappy(i);

    return 0;
}