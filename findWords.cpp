// 给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。

#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;


vector<string> findWords(vector<string>& words) 
{
    unordered_map<char,int> mp{{'q', 1},
                               {'w', 1},
                               {'e', 1},
                               {'r', 1},
                               {'t', 1},
                               {'y', 1},
                               {'u', 1},
                               {'i', 1},
                               {'o', 1},
                               {'p', 1},
                               {'a',2},
                               {'s',2},
                               {'d',2},
                               {'f',2},
                               {'g',2},
                               {'h',2},
                               {'j',2},
                               {'k',2},
                               {'l',2},
                               {'z',3},
                               {'x',3},
                               {'c',3},
                               {'v',3},
                               {'b',3},
                               {'n',3},
                               {'m',3}};
    vector<string> ret;
    for(auto s : words)
    {
        int fir = mp.find(tolower(s[0]))->second;
        bool is_true = true;
        for(int i = 1; i < s.size(); i++)
        {
            if(mp.find(tolower(s[i])) -> second != fir)
            {
                is_true = false;
                break;
            }
        };
        if(is_true)
        {
            ret.push_back(s);
        }
    };

    return ret;
}