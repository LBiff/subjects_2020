// 给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。

// 示例 1: 
// 输入: [5,7]
// 输出: 4

// 示例 2:
// 输入: [0,1]
// 输出: 0

//实质是找连续二进制字符串的最长公共前缀，因为数字是连续的，公共前缀就是m,n的公共前缀后面
//结果是 公共前缀 + 后缀0
int rangeBitwiseAnd(int m, int n) 
{
        int ret = m;
        for(int i = m + 1; i <= n; i++)
        {
            ret &= i;
        };
        return ret;
};

int main()
{
    auto ret = rangeBitwiseAnd(5,7);
    return 0;
}