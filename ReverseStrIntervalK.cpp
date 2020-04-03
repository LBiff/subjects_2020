//间隔反转字符串
#include <string>
using namespace std;

class Solution 
{
public:
    string reverseStr(string s, int k) 
    {
        int s_idx = 0;
        int e_idx = 2 *k - 1;
        while(e_idx < s.size())
        {
           help(s,s_idx, s_idx + k - 1) ;
           s_idx = e_idx + 1;
           e_idx = s_idx + 2 *k - 1;
        };

        int re = 2 * k - (e_idx  - s.size() + 1);
        if(re < k)
        {
            help(s,s_idx,s.size() - 1);
        }
        else if(re >= k)
        {
            help(s,s_idx,s_idx + k - 1);
        }
        return s;
    };

    //将[s_idx,e_idx]之间的字符串进行反转
    void help(string& s, int s_idx, int e_idx)
    {
        if(0 <= s_idx && s_idx <= e_idx && e_idx < s.size())
        {
          int l = s_idx;
          int r = e_idx;
          while(l <= r)
          {
              swap(s[l++],s[r--]);
          }
        };
    }
};

int main()
{
    Solution s;
    s.reverseStr("abcdefg",2);
}