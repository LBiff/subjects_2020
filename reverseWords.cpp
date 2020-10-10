// 给定一个字符串，逐个翻转字符串中的每个单词。
// 示例：
// 输入: ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
// 输出: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
// 注意：

// 单词的定义是不包含空格的一系列字符
// 输入字符串中不会包含前置或尾随的空格
// 单词与单词之间永远是以单个空格隔开的
// 进阶：使用 O(1) 额外空间复杂度的原地解法。

#include <vector>
#include <algorithm>
using namespace std;

void reverseWords(vector<char>& s) 
{

    auto SwapIToJ = [&s](int i, int j)
    {
        if(i >= 0 && j < s.size() && i < j)
        {
           while(i < j)
           {
               swap(s[i++], s[j--]);
           }
        }
    };

    //原地交换
    SwapIToJ(0, s.size() - 1);

    int pre_idx = 0;
    int cur_idx = 0;
    while(cur_idx < s.size())
    {
        if(s[cur_idx] == ' ')
        {
            //交换pre_idx和cur_idx-1之间
            SwapIToJ(pre_idx, cur_idx - 1);
            pre_idx = cur_idx + 1;
        };
        cur_idx++;
    };

    SwapIToJ(pre_idx, s.size() - 1);
};

int main()
{
    vector<char> s{'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};
    reverseWords(s);
    return 0;
}