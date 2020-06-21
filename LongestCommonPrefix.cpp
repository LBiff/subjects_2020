// 最长公共前缀
// 编写一个函数来查找字符串数组中的最长公共前缀。
// 如果不存在公共前缀，返回空字符串 ""。
// 示例 1:
// 输入: ["flower","flow","flight"]
// 输出: "fl"
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

string longestCommonPrefix(vector<string>& strs) 
{
    if(strs.empty())
    {
        return "";
    }
    if(strs.size() == 1)
    {
        return strs[0];
    }
    //最长
    int max_len = 0;
    for(auto s : strs)
    {
        max_len = max(max_len, static_cast<int>(s.size()));
    };
    int idx = 0;
    string ret;
    while(idx < max_len)
    {
        bool is_same = true;
        char cur_c = strs[0][idx];
        for(int i = 1; i< strs.size(); i++)
        {
            if(strs[i][idx] != cur_c)
            {
                is_same = false;
                break;
            }
        };
        if(is_same)
        {
            ret += cur_c;
        }
        else
        {
            break;
        };
        idx++;
    };
    return ret;
}
