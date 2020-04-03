//判断是2的次幂
//特点： 100000
bool isPowerOfTwo(int n) 
{
    return (n >0) && ((n & ( n - 1)) == 0) ;
    
};

//判断是2的倍数
bool isMultipleOfTwo(int n)
{
    return n & (0x00000001) == 0;
};

