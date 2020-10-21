// 给定一组非负整数 nums，重新排列它们每位数字的顺序使之组成一个最大的整数。
// 注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。

#include <vector>
#include <string>
#include <algorithm>
using namespace std;


//按从大到小排，自定义排序规则
string largestNumber(vector<int>& nums) 
{
    vector<string> vs;
    for(auto n : nums)
    {
        vs.push_back(to_string(n));
    };

    sort(vs.begin(), vs.end(), [](const string& s1, string& s2)
    {
        return s1 + s2 > s2 + s1;
    });

    if(vs[0][0] == '0')
    {
        return "0";
    }
    string ret;
    for(auto s : vs)
    {
        ret += s;
    };
    return ret;
}