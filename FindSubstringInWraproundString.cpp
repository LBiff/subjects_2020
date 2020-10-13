// 把字符串 s 看作是“abcdefghijklmnopqrstuvwxyz”的无限环绕字符串，所以 s 看起来是这样的：
// "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....". 
// 现在我们有了另一个字符串 p 。你需要的是找出 s 中有多少个唯一的 p 的非空子串，尤其是当你的输入是字符串 p ，
// 你需要输出字符串 s 中 p 的不同的非空子串的数目。 
// 注意: p 仅由小写的英文字母组成，p 的大小可能超过 10000。
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

//判断连续子串
//无必要代码
int findSubstringInWraproundString(string p) 
{
    if(p.size() < 2)
    {
        return p.size();
    };
   unordered_set<string> st;
   int pre_idx = 0; //连续字符的第一个字符
   for(int i = 1; i < p.size(); i++)
   {
       char next_c = p[i - 1] == 'z' ? 'a' : p[i - 1] + 1;
       if(p[i] != next_c)
       {
           int total_len = i - pre_idx;
           int cur_len = total_len;
           while(cur_len > 0)
           {
            //    for(int start = pre_idx; start < )
           };
       }
   }
}