// 给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。
// 例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为 S = "time#bell#" 和 indexes = [0, 2, 5]。
// 对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。
// 那么成功对给定单词列表进行编码的最小字符串长度是多少呢？


//单词后缀压缩
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

int minimumLengthEncoding(vector<string>& words) 
{
    unordered_set<string> s;
    for(auto w : words)
    {
        s.insert(w);
    };

    //将是后缀的删去
    for(auto w : words)
    {
        for(int i = 1; i < w.size(); i++)
        {
            s.erase(w.substr(i));
        }
    };

    int ret = 0;
    for(auto s_i: s)
    {
        ret += s_i.size() + 1;
    };

    return ret;

}

//字典树
