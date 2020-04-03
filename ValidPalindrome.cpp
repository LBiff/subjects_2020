//验证回文字符串
//给定一个非空字符串s，最多删除一个字符。判断是否能成为回文字符串。
//关键点：内部删除一个字符并不改变外部的对称，双指针法
#include <string>
using namespace std;

bool validPalindrome(string s)
{
    int l_idx = 0;
    int r_idx = s.length() - 1;

    auto is_Palindrome = [&](int& l_idx, int& r_idx) -> bool
    {
        while(l_idx < r_idx)
        {
            if(s[l_idx] != s[r_idx])
            {
                return false;
            };
            l_idx++;
            r_idx--;
        };
        return true;
    };

    if(!is_Palindrome(l_idx, r_idx))
    {
        int l = l_idx + 1;
        int r = r_idx - 1;
        return is_Palindrome(l, r_idx) || is_Palindrome(l_idx, r);
    }
    return true;
};

int main()
{
    string s = "abc";
    bool b = validPalindrome(s);
}


