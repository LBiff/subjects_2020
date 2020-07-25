// 给一个 C++ 程序，删除程序中的注释。这个程序source是一个数组，其中source[i]表示第i行源码。 
// 这表示每行源码由\n分隔。
// 在 C++ 中有两种注释风格，行内注释和块注释。
// 字符串// 表示行注释，表示//和其右侧的其余字符应该被忽略。
// 字符串/* 表示一个块注释，它表示直到*/的下一个（非重叠）出现的所有字符都应该被忽略。
// （阅读顺序为从左到右）非重叠是指，字符串/*/并没有结束块注释，因为注释的结尾与开头相重叠。
// 第一个有效注释优先于其他注释：如果字符串//出现在块注释中会被忽略。 
// 同样，如果字符串/*出现在行或块注释中也会被忽略。
// 如果一行在删除注释之后变为空字符串，那么不要输出该行。即，答案列表中的每个字符串都是非空的。
// 样例中没有控制字符，单引号或双引号字符。比如，source = "string s = "/* Not a comment. */";" 
// 不会出现在测试样例里。（此外，没有其他内容（如定义或宏）会干扰注释。）
// 我们保证每一个块注释最终都会被闭合， 所以在行或块注释之外的/*总是开始新的注释。
// 最后，隐式换行符可以通过块注释删除。 有关详细信息，请参阅下面的示例。
// 从源代码中删除注释后，需要以相同的格式返回源代码。
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;
vector<string> removeComments(vector<string>& source) 
{
    vector<string> ret;
    bool is_deled = false; //该行已经被块注释了,上行遗留下的状态
    for(auto s : source)
    {
        if(!is_deled)
        {
            size_t s_1 = s.find_first_of("//",0);
            size_t s_2 = s.find_first_of("/*", 0);
            
            auto find_line_block = 
            if(s_1 != string::npos && s_2 != string::npos) //找到
            {
                int start_col = min(s_1, s_2);
                ret.push_back(s.substr(start_col + 2, s.length() - start_col - 2));
                bool is_line_commit = s_1 < s_2; //是行注释
                is_deled = !is_line_commit;
            }
            else if(s_1 != string::npos)
            {
                ret.push_back(s.substr(s_1 + 2, s.length() - s_1 - 2));
                is_deled = false;
            }
            else if(s_2 != string::npos)
            {
                ret.push_back(s.substr(s_2 + 2, s.length() - s_2 - 2));
                is_deled = true;
            }
            else //没有注释则跳过
            {
                ret.push_back(s);
                is_deled = false;
            }
        }


    }
}