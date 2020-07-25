//给定两个整数a,b,求a/1 + a/2 + a/3 + ... + a /b的和， 注意除法为整除
//a = 5, b=6 ==> 5/1 + 5/2 + 5/3 + 5/4 + 5/5 + 5/6 = 5 + 2 + 1 + 1 + 1 + 0 = 10

//O(n)算法不够
int GetSum(int a, int b)
{
    double want_i = 1;
    double get_b = a / want_i;
    while(get_b >= b)
    {
    }
}
