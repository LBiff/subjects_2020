// 我们给出 S，一个源于 {'D', 'I'} 的长度为 n 的字符串 。（这些字母代表 “减少” 和 “增加”。）
// 有效排列 是对整数 {0, 1, ..., n} 的一个排列 P[0], P[1], ..., P[n]，使得对所有的 i：
// 如果 S[i] == 'D'，那么 P[i] > P[i+1]，以及；
// 如果 S[i] == 'I'，那么 P[i] < P[i+1]。
// 有多少个有效排列？因为答案可能很大，所以请返回你的答案模 10^9 + 7

#include <string>
#include <vector>
using namespace std;

#define mod 10e9 + 7;

int numPermsDISequence(string S) 
{
    //求解最大和最小
    int max_v = 0;
    int min_v = 0;
    int cur = 0;
    for(auto c : S)
    {
        if(c == 'D')
        {
            cur--;
            max_v = max(max_v, cur);
            min_v = min(min_v, cur);
        }
        else
        {
            cur++;
            max_v = max(max_v, cur);
            min_v = min(min_v, cur);
        }
    };

    vector<vector<int>> vv;
    vv[-min_v].push_back(0);
    vv.resize(max_v - min_v + 1);
    cur = 0;
    for(int i = 0; i < S.size(); i++)
    {
        if(S[i] == 'D')
        {
            cur--;
        }
        else
        {
            cur++;
        };
        vv[cur - min_v].push_back(i + 1);
    };

    int ret = 1;
    



    



    

    
}
