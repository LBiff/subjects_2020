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
// int findSubstringInWraproundString(string p) 
// {
//     auto GetChar = [](const char c) ->char
//     {
//         if(c == 'z')
//         {
//             return 'a';
//         };
//         return static_cast<char>(c + 1);
//     };

//     unordered_set<string> set;
//     //从长到短判定
//     int s = 0;
//     int e = p.size() - 1;
//     int ret;
//     while(s <= e)
//     {
//         string tmp;
//         //判断当前形成的子串
//         bool is_effective = true;
//         for(int i = s; i < e; i++)
//         {
//             if(GetChar(p[i]) != p[i + 1])
//             {
//                 is_effective = false;
//                 break;
//             }
//         };
//         if(is_effective)
//         {
//             ret += 
//         }
        
//     }
// }