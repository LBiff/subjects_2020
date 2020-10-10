// 我们在两条独立的水平线上按给定的顺序写下 A 和 B 中的整数。
// 现在，我们可以绘制一些连接两个数字 A[i] 和 B[j] 的直线，只要 A[i] == B[j]，且我们绘制的直线不与任何其他连线（非水平线）相交。
// 以这种方法绘制线条，并返回我们可以绘制的最大连线数。

// 示例 1：
// 1 4 2
// 1 2 4
// 1-1， 4-4
// 输入：A = [1,4,2], B = [1,2,4]
// 输出：2
// 解释：
// 我们可以画出两条不交叉的线，如上图所示。
// 我们无法画出第三条不相交的直线，因为从 A[1]=4 到 B[2]=4 的直线将与从 A[2]=2 到 B[1]=2 的直线相交。

#include <vector>
#include <algorithm>
using namespace std;

//其实就是求最长公共子序列
int maxUncrossedLines(vector<int>& A, vector<int>& B) 
{
    //dp[i][j]表示A[0,i]与B[0,j]的最长公共子序列的长度
   vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
   //初始化
   //dp[i][0] = 0; dp[0][j] = 0;

   //转移方程 dp[i][j] = A[i]== B[j] ? dp[i - 1][j - 1] + 1 ? max(dp[i - 1][j],dp[i][j - 1]);
    for(int i = 1; i < A.size() + 1; i++)
    {
        for(int j = 1; j < B.size() + 1; j++)
        {
            if(A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
            
        }
    };

    return dp.back().back();
};

int main()
{
    // [1,3,7,1,7,5] [1,9,2,5,1]
    vector<int> A{1,3,7,1,7,5};
    vector<int> B{1,9,2,5,1};
    auto ret = maxUncrossedLines(A, B);
    return 0;
}