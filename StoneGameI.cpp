// 石头游戏I
// 亚历克斯和李用几堆石子在做游戏。偶数堆石子排成一行，每堆都有正整数颗石子 piles[i] 。
// 游戏以谁手中的石子最多来决出胜负。石子的总数是奇数，所以没有平局。
// 亚历克斯和李轮流进行，亚历克斯先开始。 每回合，玩家从行的开始或结束处取走整堆石头。 
// 这种情况一直持续到没有更多的石子堆为止，此时手中石子最多的玩家获胜。
// 假设亚历克斯和李都发挥出最佳水平，当亚历克斯赢得比赛时返回 true ，当李赢得比赛时返回 false 。

#include <vector>
#include <numeric>
using namespace std;

//alias作为先手
//dp[i][j]表示[i...j]的堆中进行选取， first表示alias能够得到的最佳，sec表示对手能够得到最佳
bool stoneGame(vector<int>& piles) 
{
    int size = piles.size();
    vector<vector<pair<int,int>>> dp(size,vector<pair<int,int>>(size,{0,0}));
    //base case
    for(int i = 0; i < size; i++)
    {
        dp[i][i].first = piles[i]; //作为先手
        dp[i][i].second = 0;
    };

    //状态转移
    //dp[i][j].first = max(piles[i] + dp[i + 1][j].sec , piles[j] + dp[i][j - 1].sec)
    //dp[i][j].sec = dp[i + 1][j].fir , fp[i][j - 1].fir

    //斜着遍历
    for(int start_col = 1; start_col < size; start_col++)
    {
        int row = 0;
        int col = start_col;
        while(col < size)
        {
            dp[row][col].first = max(piles[row] + dp[row + 1][col].second , piles[col] + dp[row][col - 1].second);
            dp[row][col].second = max(dp[row + 1][col].first , dp[row][col - 1].first);
            row++;
            col++;
        }
    };

    return dp[0][size - 1].first > accumulate(piles.begin(), piles.end(), 0) / 2;
};

int main()
{
    vector<int> v{3,7,2,3};
    auto ret = stoneGame(v);
    return 0;
};

