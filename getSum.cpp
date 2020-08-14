// 不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和

//参照整数相加，等于无进位加法+ 进位
int getSum(int a, int b) 
{
    if(a == 0)
    {
        return b;
    };
    if(b == 0)
    {
        return a;
    };

    int lower = 0; //无进位加法结果-异或
    int in = 0; //进位情况
    while(1)
    {
        lower = a ^ b;
        in = a & b;
        if(in == 0)
        {
            break;
        };
        a = lower;
        b = in << 1;
    };

    return lower;
};

int main()
{
    auto ret = getSum(-1, 1);
    return 0;
}