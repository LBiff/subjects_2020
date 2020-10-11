// 你的音乐播放器里有 N 首不同的歌，在旅途中，你的旅伴想要听 L 首歌（不一定不同，即，允许歌曲重复）。请你为她按如下规则创建一个播放列表：
// 每首歌至少播放一次。
// 一首歌只有在其他 K 首歌播放完之后才能再次播放。
// 返回可以满足要求的播放列表的数量。由于答案可能非常大，请返回它模 10^9 + 7 的结果。
// 0 <= K < N <= L <= 100
#include <vector>
using namespace std;

int mod = 1e9 + 7;

//取模总结
// (a + b) % p = (a%p + b%p) %p
// (a - b) % p = ((a%p - b%p) + p) %p
// (a * b) % p = (a%p)*(b%p) %p


// 方法 1：动态规划
// 想法
// 令 dp[i][j] 为播放列表长度为 i 包含恰好 j 首不同歌曲的不同列表数量。我们需要计算 dp[L][N]，看上去可以通过 dp 来解决。
// 算法
// 考虑 dp[i][j]。最后一首歌，我们可以播放没有播放过的歌也可以是播放过的。如果未播放过的，那么就是 dp[i-1][j-1] * (N-j) 种选择方法。
// 如果不是，那么就是选择之前的一首歌，dp[i-1][j] * max(j-K, 0)（j 首歌，最近的 K 首不可以播放）。
int numMusicPlaylists(int N, int L, int K) 
{
    vector<vector<long>> dp(L + 1, vector<long>(N + 1, 0));
    dp[0][0] = 1;
    //初始化 dp[0][j]=0; dp[i][0] = 0;
    //转移: dp[i][j] = //播放没有播放的歌曲 dp[i-1][j - 1] * (N - j + 1), 播放播放过的dp[i - 1][j] * max(j - K, 0)
    for(int i = 1; i < L + 1; i++)
    {
        for(int j = 1; j < N + 1; j++)
        {
            long no_played = ((dp[i-1][j - 1] % mod) * ((N - j + 1) %mod)) % mod;
            long played = ((dp[i - 1][j] % mod)* (max(j - K, 0) % mod)) % mod;
            dp[i][j] += no_played;
            dp[i][j] = (played + dp[i][j]) % mod;
        }
    };
    return dp.back().back();
};

int main()
{
    auto ret = numMusicPlaylists(3,3,1);
    return 0;
}