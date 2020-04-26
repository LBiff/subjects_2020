//HUAWEI
//完全平方数
// 给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
// 说明：不要使用任何内置的库函数，如  sqrt。

//直接算, 需要转换为long
bool isPerfectSquare(int num) 
{
    for(int i =0; (long)i * (long)i <= num; i++)
    {
        if((long)i * (long)i == num)
        {
            return true;
        }
    };
    return false;
}

//二分查找也会溢出，需要转换为long
bool isPerfectSquare(int num) 
{
    if(num < 0)
    {
        return false;
    };
    if(num < 2)
    {
        return true;
    };

    int l = 2;
    int r = num / 2;
    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        int tmp = mid * mid;
        if(tmp == num)
        {
            return true;
        }
        else if(tmp > num)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    };

    return false;
};


//牛顿法(切线法)
bool isPerfectSquare(int num) 
{
    if(num < 2)
    {
        return true;
    };

    long x = num / 2;
    while(x * x > num)
    {
        x = (x + num / x) / 2;
    };

    return x * x == num;
}
