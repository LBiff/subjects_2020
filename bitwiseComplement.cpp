//十进制数的反码
// 每个非负整数 N 都有其二进制表示。例如， 5 可以被表示为二进制 "101"，11 可以用二进制 "1011" 表示，
// 依此类推。注意，除 N = 0 外，任何二进制表示中都不含前导零。
// 二进制的反码表示是将每个 1 改为 0 且每个 0 变为 1。例如，二进制数 "101" 的二进制反码为 "010"。
// 给你一个十进制数 N，请你返回其二进制表示的反码所对应的十进制整数。

int bitwiseComplement(int N) 
{
    int count = 0;
    int idx = 0x01;
    int ret = 0;
    while(count++ < 32)
    {
       int tmp = (N & idx == 0x01 ? 0x0 : 0x01);
       ret |= tmp;
       ret << 1;
       N >> 1;
    };
    return ret;
};

int main()
{
    auto ret = bitwiseComplement(5);
    return 0;
}