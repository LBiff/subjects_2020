// 实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。

#include <string>
using namespace std;

string toLowerCase(string str) 
{
    int a = 'a';
    int diff = 'a' - 'A';

    for(auto& i : str)
    {
        i = i < a ? char(i + diff) : i;
    };

    return str;
};


int main()
{
    auto ret = toLowerCase("Hello");
    return 0;
}