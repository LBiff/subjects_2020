//打印字符串的全排列
#include <iostream>
#include <algorithm>
using namespace std;

//[0,s_idx]位置确定，(s_idx,s.length-1)全排序列, 允许重复
void PrintStringAllRank(string s, int s_idx)
{
    if(s_idx == s.length())
    {
        cout << s << endl;
    };


    for (int i = s_idx; i < s.length(); i++)    
    {
        string s_bak = s;
        iter_swap(s_bak.begin() + i, s_bak.begin() + s_idx);
        PrintStringAllRank(s_bak, s_idx + 1);
    }
};

//不允许重复，打印前hash_set检测
int main()
{
    string s = "abcd";
    PrintStringAllRank(s,0);
    return 0;
}