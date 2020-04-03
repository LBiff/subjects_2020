//编辑距离
// 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
// 你可以对一个单词进行如下三种操作：
// 插入一个字符
// 删除一个字符
// 替换一个字符
#include <string>
#include <algorithm>
using namespace std;

//动态规划
//基本思路：每个字符都可能被删除添加和替换
int minDistance(string word1, string word2) 
{
    //[i][j]表示要形成w1的前i字符和w2的前j字符相等需要的操作
    //对“dp[i-1][j-1] 表示替换操作，dp[i-1][j] 表示删除操作，dp[i][j-1] 表示插入操作
    //https://leetcode-cn.com/problems/edit-distance/solution/zi-di-xiang-shang-he-zi-ding-xiang-xia-by-powcai-3/
    int dp[word1.length() +1][word2.length() + 1];
    dp[0][0] = 0;
    //填充0列
    for(int row = 1; row< word1.size() + 1; row++)
    {
        dp[row][0] = row;
    };
    //填充0行
    for(int col = 1; col < word2.size() + 1; col++)
    {
        dp[0][col] = col;
    };
    
    //计算普遍位置
    for(int row = 1; row < word1.size() + 1; row++)
    {
        for(int col = 1; col < word2.size() +1; col++)
        {
            if(word1[row - 1] == word2[col - 1])
            {
                dp[row][col] = dp[row - 1][col - 1];
            }
            else
            {
                dp[row][col] = min(dp[row - 1][col],min(dp[row][col - 1],dp[row - 1][col - 1])) + 1;
            }
        }
    };
    
    return dp[word1.size()][word2.size()];                             
};

int main()
{
    int a = minDistance("horse","ros");
    return 0;
}

