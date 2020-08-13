//编辑距离
// 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
// 你可以对一个单词进行如下三种操作：
// 插入一个字符
// 删除一个字符
// 替换一个字符
#include <string>
#include <algorithm>
using namespace std;


//暴力解
//将word1转换为word2, [0,idx_1 - 1]与[0,idx_2 - 1]已经通过get_count次数匹配
int minDistance_1(string word1, string word2, int idx_1, int idx_2, int get_count)
{
    
    if(idx_1 >= word1.size() && idx_2 < word2.size()) //1匹配完了但是2还没匹配完，直接把2剩下的全部给1插入
    {
        return get_count + word2.size() - idx_2;
    }
    else if(idx_1 >= word1.size() && idx_2 >= word2.size()) //均匹配完
    {
        return get_count;
    }
    else if(idx_1 < word1.size() && idx_2 >= word2.size()) //1没完2完了，直接把1后面的删掉
    {
        return get_count + word1.size() - idx_1;
    }
    else //都没完
    {
        if(word1[idx_1] != word2[idx_2])//相等不动，不等操作
        {
            return min(minDistance_1(word1, word2, idx_1, idx_2 + 1, get_count + 1), //把2插入1中
                    min(minDistance_1(word1, word2, idx_1 + 1, idx_2 + 1, get_count + 1), //将1替换
                        minDistance_1(word1, word2, idx_1 + 1, idx_2, get_count + 1))); //将1删了
        }
        else
        {
            return minDistance_1(word1, word2, idx_1 + 1, idx_2 + 1, get_count);
        }
    }
}



//动态规划
//基本思路：每个字符都可能被删除添加和替换
int minDistance(string word1, string word2) 
{
    //[i][j]表示要形成w1的前i字符和w2的前j字符相等需要的操作
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
    
    return dp[word1.size()][word2.size()];                             
};

int main()
{
    int a = minDistance_1("horse", "ros", 0,0,0);
    return 0;
}

