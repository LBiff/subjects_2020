// 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
// 你可以对一个单词进行如下三种操作：
// 插入一个字符
// 删除一个字符
// 替换一个字符

#include <string>
#include <vector>
using namespace std;

int minDistance(string word1, string word2) 
{
    size_t sz1 = word1.size();
    size_t sz2 = word2.size();
    //dp[i][j]表示word1[0, i] 转换到word2[0, j]所用的最少的操作数， 0索引表示空字符串
    vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1, 0));

    //初始化: dp[0][0] = 0;
    //dp[i][j] = w1[i] == w2[j] ? dp[i - 1][ j - 1]
    //                          : min(dp[i - 1][j - 1] --替换操作
    //                                dp[i][j - 1] + 1 --插入
    //                                dp[i - 1][j] + 1) --删除一个字符

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
            if(word1[row - 1] == word2[col - 1])  //相等不做任何操作
            {
                dp[row][col] = dp[row - 1][col - 1];
            }
            else
            {
                //dp[row - 1][col] + 1 删除1处的字符
                //dp[row][col - 1] + 1 插入2处字符到1
                //dp[row - 1][col - 1] + 1 替换操作
                dp[row][col] = min(dp[row - 1][col],min(dp[row][col - 1],dp[row - 1][col - 1])) + 1;
            }
        }
    };

    return dp.back().back();
}
 