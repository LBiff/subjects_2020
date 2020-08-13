// 初在一个记事本上只有一个字符 'A'。你每次可以对这个记事本进行两种操作：
// Copy All (复制全部) : 你可以复制这个记事本中的所有字符(部分的复制是不允许的)。
// Paste (粘贴) : 你可以粘贴你上一次复制的字符。
// 给定一个数字 n 。你需要使用最少的操作次数，在记事本中打印出恰好 n 个 'A'。
// 输出能够打印出 n 个 'A' 的最少操作次数。

//动态规划求解
//状态定义: cur_count--当前的字符个数， copied_count--已经复制到粘贴板的字符个数
//         n--总共的字符个数,  operated_count--已经操作的次数

#include <climits>
#include <algorithm>
using namespace std;

int dfs(int cur_count, int copied_count, int n, int operated_count)
{
    if(cur_count == n)
    {
        return operated_count;
    }
    else if(cur_count > n)
    {
        //不可用
        return INT_MAX;
    }
    else
    {
        //两种选择：复制所有+粘贴， 直接粘贴上一步的
        return min(dfs(cur_count * 2, cur_count, n, operated_count + 2), 
                   dfs(cur_count + copied_count, copied_count, n,operated_count + 1));
    };
};

int minSteps(int n) 
{
    if(n == 1)
    {
        return 0;
    };
    return dfs(1, 1, n, 1);
};



int main()
{
    auto ret = minSteps(3);
    return 0;
}