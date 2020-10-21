// 给定字符类型的数组chas，请在单词间做逆序调整。只要做到单词的顺序逆序即可，对空格的位置没有要求。
// 示例1
// 输入
// "i am a student"
// 输出
// "i ma a tneduts"

//云从

#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

void ReverseStr(string& s)
{
    int s_idx = -1;
    int e_idx = -1;

    for(int i = 0; i < s.size(); i++)
    {
        if(isalpha(s[i])) //是字母
        {
            if(s_idx == -1) //无效
            {
                s_idx = i;
            }
            e_idx = i;
        }
        else //非字母则中断进行翻转
        {
            if(s_idx != -1)
            {
                reverse(s.begin() + s_idx, s.begin() + e_idx + 1);
            };
            s_idx = -1;
        }
    };

    if(s_idx != -1)
    {
        reverse(s.begin() + s_idx, s.end());
    };
};

int main()
{
    string s = "i  am a    student ";
    ReverseStr(s);
    return 0;
}