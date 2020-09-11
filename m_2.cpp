#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;


//现在已经确保s[0,s_idx)已经搜到的
bool dfs(vector<vector<char>>& vc, int i, int j, string s, int s_idx, unordered_set<string>& hs)
{
    bool flag = false;
    size_t row = vc.size();
    size_t col = vc[0].size();
    size_t s_len = s.size();
    if(s_len < s_idx)
    {
        return false;
    };
    if(s_len = s_idx)
    {
        return true;
    };
    vector<vector<int>> vv{{i - 1, j}, {i + 1, j},{i, j - 1}, {i, j + 1}};
    for(auto vvi : vv)
    {
        string tmp = to_string(vvi[0]) + "_" +  to_string(vvi[1]);
        if(0 <= vvi[0] && vvi[0] < row && vvi[1] >= 0 && vvi[1] < col && vc[vvi[0]][vvi[1]] == s[s_idx] && 
        hs.find(tmp) == hs.end())
        {
            hs.insert(tmp);
            flag = flag || dfs(vc,vvi[0], vvi[1],s, s_idx + 1,hs);
            if (!hs.empty())
            {
                hs.erase(tmp);
            }
        }
    };

    return flag;

}
bool isExist(vector<vector<char>>& vc,  string& s)
{
    size_t row = vc.size();
    if(row == 0)
    {
        return s == "";
    };
    size_t col = vc[0].size();
    size_t s_len = s.size();
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(vc[i][j] == s[0])
            {
                unordered_set<string> hs;
                hs.insert(to_string(i) + "_" +  to_string(j));
                if(dfs(vc, i, j, s, 1, hs))
                {
                    return true;
                }
            }
        }
    };

    return false;
};

int main()
{
   
    vector<vector<char>> vc{ {'A','B','C','E'},

  {'S','F','C','S'},

  {'A','D','E','E'}};
  string s;
  cin >> s;
  string ret = isExist(vc, s) ? "true" : "false";
  cout << ret;
  return 0;


}