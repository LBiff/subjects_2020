//HUAWEI
// 统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
// 请注意，你可以假定字符串里不包括任何不可打印的字符。
// 示例:
// 输入: "Hello, my name is John"
// 输出: 5
// 解释: 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。
#include <string>
#include <sstream>
using namespace std;

int countSegments(string s) 
{
    stringstream ss;
    ss << s;
    string tmp;
    int ret = 0;
    while(ss >> tmp)
    {
        ret++;
    };
    return ret;
};

int main()
{
    auto ret = countSegments( "Hello, my name is John");
    return 0;
}
