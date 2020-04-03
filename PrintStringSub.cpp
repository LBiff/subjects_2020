//打印字符串的所有子序列
#include <string>
#include <iostream>
using namespace std;


//从s字符串中从[s_idx(包括)-(n-1))中随便挑选拼凑字符串
void PrintStringSub_2(string s, int s_idx, string pre)
{
  
    if(s_idx == s.length())
    {
        if(pre != "")
        {
            cout << pre << endl;
        }
        return;
    };
    PrintStringSub_2(s, s_idx + 1, pre); //不要s[s_idx]
    PrintStringSub_2(s, s_idx + 1, pre + s[s_idx]);
}


int main()
{
    string a = "abcd";
    PrintStringSub_2(a, 0,"");
    return 0;
}