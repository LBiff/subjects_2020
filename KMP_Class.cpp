//KMP算法的类
//labuladong算法手册

#include <string>
#include <vector>
using namespace std;

class KMP_P
{
public:
    KMP_P(string pat) : _pat(pat), _dp(pat.length(), vector<int>(256,0))
    {
        //通过pat构建_dp O(M)
        int p_len = _pat.length();
        //dp[pat状态][遇到的txt的下一个字符] = 下一转移状态
        //base case
        //只有遇到pat[0]这个字符才能使状态从0转移到1，
        //遇到其他字符仍然停留在0
        _dp[0][_pat[0]] = 1;
        //影子状态x初始为0
        int x = 0;
        for(int p_state = 1; p_state < p_len; p_state++)
        {
            for(int c = 0; c < 256; c++)
            {
                _dp[p_state][c] = _pat[p_state] ==  c ? p_state + 1 : _dp[x][c];
            };
            //更新影子状态
            x = _dp[x][_pat[p_state]];
        }
        
    };

    //需要进行的匹配，返回txt中第一个匹配的开始索引
    int search(string txt)
    {
        //按照dp数组匹配txt
        //需要O(N)时间
        int p_len = _pat.length();
        int t_len = txt.length();

        //状态i表示txt已经匹配的数目，即[0,i)已经匹配
        int p_state = 0; // 初始状态

        for(int i = 0; i < t_len; i++)
        {
            //当前是状态p_state,遇到的字符是txt[i]
            //_pat状态转移
            p_state = _dp[p_state][txt[i]];
            if(p_state == p_len)
            {
                return i - p_len + 1;
            }
        };

        return -1;
    }
private:
    string _pat; //待匹配字符
    //dp[i][j]表示 _pat的当前状态是i([0...i]已经匹配)，下一个遇到的字符是j(0 <= j <= 256)的时候，
    //需要进行的状态转换为val,val表示_pat[val]开始匹配
    vector<vector<int>> _dp; //next
};
