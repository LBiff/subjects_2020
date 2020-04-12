//数字外观描述
// 「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：
// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 1 被读作  "one 1"  ("一个一") , 即 11。
// 11 被读作 "two 1s" ("两个一"）, 即 21。
// 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
// 给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。
// 注意：整数序列中的每一项将表示为一个字符串。
#include <string>
using namespace std;

//输出外边数列的第n项
string countAndSay(int n) 
{
    auto describe = [](string n_s) -> string
    {
        string ret;
        int cur_count = 0; //前面的累加结果
        char cur_v ='#';

        for(int i = 0; i < n_s.size(); i++)
        {
            if(cur_count != 0 && n_s[i] == cur_v) //继续累加
            {
                cur_count++;
            }
            else if(cur_count != 0 && n_s[i] != cur_v) //结束累加
            {
                ret += to_string(cur_count);
                ret += cur_v;
                cur_count = 1;
                cur_v = n_s[i];
            }
            else //cur_count == 0
            {
                cur_count++;
                cur_v = n_s[i];
            }
        };
        if(cur_count != 0)
        {
             ret += to_string(cur_count);
             ret += cur_v;
        }
       
        return ret;
    };

    string ret = "1";
    for(int i = 1; i < n; i++)
    {
        ret = describe(ret);
    };

    return ret;
};

int main()
{
    auto ret = countAndSay(10);
    return 0;
}
