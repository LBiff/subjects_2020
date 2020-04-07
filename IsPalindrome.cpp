//判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

bool isPalindrome(int x) 
{
    if(x < 0 || (x % 10 == 0 && x != 0)) //前缀不可能为0
    {
        return false;
    };

    //拿到其最高的标志位
    int n = 1;
    while(x / n >= 10)
    {
        n *= 10;
    };

    int r = 0;
    int l =0;
    while(x > 0)
    {
        l = x / n;
        r = x % 10;
        if(l != r)
        {
            return false;
        };
        //删除前
        x = x % n;
        //删除后
        x /= 10;
        n /= 100;
    };

    return true;
};

int main()
{
    int x = 1001;
    auto ret = isPalindrome(x);
    return 0;
}
