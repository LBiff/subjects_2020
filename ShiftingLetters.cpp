#include <string>
#include <vector>
using namespace std;

// 有一个由小写字母组成的字符串 S，和一个整数数组 shifts。
// 我们将字母表中的下一个字母称为原字母的 移位（由于字母表是环绕的， 'z' 将会变成 'a'）。
// 例如·，shift('a') = 'b'， shift('t') = 'u',， 以及 shift('z') = 'a'。
// 对于每个 shifts[i] = x ， 我们会将 S 中的前 i+1 个字母移位 x 次。
// 返回将所有这些移位都应用到 S 后最终得到的字符串。

//相加可能溢出的问题
string shiftingLetters(string S, vector<int>& shifts) 
{
    auto cal_next = [](const char c, int count) -> char
    {
        return ((c - 'a') + count) % 26 + 'a';
    };

    for(int i = static_cast<int>(shifts.size()) - 2; i >= 0; i--)
    {
        shifts[i] += (shifts[i + 1] % 26);
    };

    for(int i = 0; i < shifts.size(); i++)
    {
        S[i] = cal_next(S[i], shifts[i]);
    };
    return S;
};

int main()
{
    string S = "abc";
    vector<int> shifts{3,5,9};
    auto ret = shiftingLetters(S, shifts);
    return 0;
}