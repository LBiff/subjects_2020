//【字节】--万万没想到之聪明的编辑
// 我叫王大锤，是一家出版社的编辑。我负责校对投稿来的英文稿件，这份工作非常烦人，因为每天都要去修正无数的拼写错误。
// 但是，优秀的人总能在平凡的工作中发现真理。我发现一个发现拼写错误的捷径：
// 1. 三个同样的字母连在一起，一定是拼写错误，去掉一个的就好啦：比如 helllo -> hello
// 2. 两对一样的字母（AABB型）连在一起，一定是拼写错误，去掉第二对的一个字母就好啦：比如 helloo -> hello
// 3. 上面的规则优先“从左到右”匹配，即如果是AABBCC，虽然AABB和BBCC都是错误拼写，应该优先考虑修复AABB，结果为AABCC

// ------------------for 1-----------------------
// #include <string>
// #include <vector>
// #include <iostream>
// using namespace std;

// void CheckAAA(string& s)
// {
//     if(s.size() < 3)
//     {
//         return;
//     };
//     char pre_pre = s[0];
//     char pre=s[1];
//     for(int i = 2; i < s.size(); i++)
//     {
//         if(s[i] == pre_pre && pre_pre == pre)
//         {
//             s.erase(s.begin() + i);
//             CheckAAA(s);
//         };
//         pre_pre = pre;
//         pre = s[i];
//     }
// };

// void CheckAABB(string& s)
// {
//     if(s.size() < 4)
//     {
//         return;
//     };

//     int a_1_idx = 0;
//     int a_2_idx = 1;
//     int b_1_idx = 2;
//     for(int i = 3; i< s.size(); i++)
//     {
//         if(s[a_1_idx] == s[a_2_idx] && s[b_1_idx] == s[i])
//         {
//             s.erase(s.begin() + b_1_idx);
//             CheckAABB(s);
//         }
//         a_1_idx = a_2_idx;
//         a_2_idx = b_1_idx;
//         b_1_idx = i;
//     }
// };

// string AutoCheck(string s) 
// {
//     CheckAAA(s);
//     CheckAABB(s);
//     return s;
// }

// int main()
// {
//     auto ret = AutoCheck("wooooooow");
//     return 0;
// }

//---------------------------0816---------------
#include <string>
#include <iostream>
using namespace std;

void checkAAA(string& s)
{
    if(s.size() < 3)
    {
        return;
    };
    int pre_c = s[0];
    int count = 1;
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] == pre_c)
        {
            count++;
            if(count == 3)
            {
                s.erase(s.begin() + i);
                checkAAA(s);
            }
        }
        else
        {
            pre_c = s[i];
            count = 1;
        }
    }
};

void checkAABB(string& s)
{
    if(s.size() < 4)
    {
        return;
    };
    char c0 = s[0];
    char c1 = s[1];
    char c2 = s[2];
    char c3 = s[3];
    for(int i_0 = 0; i_0 < s.size() - 3; i_0++)
    {
        c0 = s[i_0];
        c1 = s[i_0 + 1];
        c2 = s[i_0 + 2];
        c3 = s[i_0 + 3];
        if(c0 == c1 && c1 != c2 && c2 == c3)
        {
            s.erase(s.begin() + i_0 + 2);
            checkAABB(s);
        }
    }
};

int main()
{
    int count = 0;
    string s;
    getline(cin, s);
    count = atoi(s.c_str());
    while(count-- > 0)
    {
        getline(cin, s);
        checkAAA(s);
        checkAABB(s);
        cout << s << endl;
    };
    return 0;
}