//排列组合
// 输入：[['a','b'],['n','m'],['0','1']]
// 输出：['an0','an1','am0','am1','bn0','bn1','bm0','bm1'] 

//41
#include <vector>
#include <string>
using namespace std;

void Combination(const vector<vector<char>>& vvc, int cur_idx, vector<string>& vs)
{
    if(cur_idx >= vvc.size())
    {
        return;
    };

    int sz = vs.size();
    for(int i = 0; i < sz; i++)
    {
        for(int j = 1; j < vvc[cur_idx].size(); j++)
        {
            vs.push_back(vs[i] + vvc[cur_idx][j]);
        }
    };
    
    for(int i = 0; i < sz; i++)
    {
        vs[i] += vvc[cur_idx][0];
    };

    Combination(vvc, cur_idx + 1, vs);
};

int main()
{
    vector<vector<char>> vvc{{'a','b'},{'n','m'},{'0','1'}};
    vector<string> vs{""};
    // for(int i = 0; i < vvc[0].size(); i++)
    // {
    //     string s;
    //     s += vvc[0][i];
    //     vs.push_back(s);
    // };
    Combination(vvc, 0, vs);
    return 0;
}


