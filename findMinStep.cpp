// 回忆一下祖玛游戏。现在桌上有一串球，颜色有红色(R)，黄色(Y)，蓝色(B)，绿色(G)，还有白色(W)。 现在你手里也有几个球。
// 每一次，你可以从手里的球选一个，然后把这个球插入到一串球中的某个位置上（包括最左端，最右端）。
// 接着，如果有出现三个或者三个以上颜色相同的球相连的话，就把它们移除掉。重复这一步骤直到桌上所有的球都被移除。
// 找到插入并可以移除掉桌上所有球所需的最少的球数。如果不能移除桌上所有的球，输出 -1 。
//10.5
#include <string>
#include <unordered_map>
using namespace std;

void del(string& cur_board)
{

}
//用当前手中的牌去消除当前的需要的步数
int dp(string cur_board, unordered_map<char,int> hand, int head_count, int cur_step)
{
    if(cur_board.empty())
    {
        return cur_step;
    };
    if(head_count == 0)
    {
        return -1;
    };


    
}
//暴力解
int findMinStep(string board, string hand) 
{

}