//int数字判断是回文数

//1.转换成字符串左右比较
//2.原数字左右比较
bool IsPalindrom_1(int n)
{
    if(n < 0 || (n % 10 == 0 && n != 0))
    {
        return false;
    };

    //help确定n的位数 232-->100
    int help = 1;
    //==10  n = 1000
    while(n / help >= 10)
    {
        help *= 10;
    };

    //n的左右对比
    while(n != 0)
    {
        //左右对比
        if((n / help) != (n % 10))
        {
            return false;
        };

        //n取中间
        n = n % help / 10;
        help /= 100;
    };

    return true;
}


//原数字一半反转比较
bool IsPalindrom_2(int n)
{
    if(n < 0 || (n %10 == 0 && n != 0))
    {
        return false;
    };

    int help = 0;
    while(help < n)
    {
        help  = help * 10 + n % 10;
        n /= 10;
    };

    return help == n || help % 10 == n;
};

int main()
{
    bool a = IsPalindrom_1(1001);
    bool b = IsPalindrom_2(1221);
    return 0;
}