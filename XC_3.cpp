// 作为一个新手程序员，数组越界是一个非常容易犯的错误。游游为了提醒自己，决定写一个小程序来分析自己的代码中是否存在这样的错误。
// 但它很快发现，这项工作对于它来说太过困难了。所以它希望你来帮忙实现一个简化后的版本。
// 在这个简化后的版本中，它所需要处理的语句只有以下两种类型：
// 1. 整形数组定义语句：格式为name[size]。例如：a[5]或者array[10]。数组可用的下标为[0, size)。定义后的数组所有的元素均为0；
// 2. 赋值语句：格式为name[index]=value。例如：a[0]=1或者a[a[0]]=a[a[3]]。
// 在被分析的代码中，数组越界错误只会出现在赋值语句中，且代码中只会有这一类错误。游游希望你帮它找出代码中第一次出现错误的语句，
// 并输出对应的行号。

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <iostream>
#include <sstream>
using namespace std;

static vector<string> GetStrVSpiltByChar(string s, char c)
{
    vector<string> v;
    size_t first_pos = s.find_first_of(c,0);
    v.push_back(s.substr(0, first_pos));
    int pre = first_pos;
    size_t pos =  s.find_first_of(c,pre + 1);
    while(pos != string::npos)
    {
        v.push_back(s.substr(pre+1, pos-pre -1));
        pre = pos;
        pos = s.find_first_of(c,pos + 1);
    };
    v.push_back(s.substr(pre+1));
    return v;   
};


int validateArrayUsages(vector<string>lines) {
    unordered_map<string,int> mp;

    
    auto is_right = [&mp](const string s) -> bool
    {
        auto ret = GetStrVSpiltByChar(s, '[');
        ret.back() = ret.back().substr(0, ret.back().find_first_of(']'));

        int cur_idx =  ret.size() - 1;
        int cur_num = atoi(ret.back().c_str());
        cur_idx--;
        while(cur_idx >= 0)
        {
            string name = ret[cur_idx];
            if(cur_num >= mp.find(name)->second)
            {
                return false;
            };
            cur_num = 
        }

    };

    int cur_line = 1;
    bool all_right = true;
    for(auto s : lines)
    {
        bool is_fuzhi = s.find_first_of('=') != string::npos;
        if(is_fuzhi)
        {
            int dh_pos = s.find_first_of('=');
            if(!(is_right(s.substr(0, dh_pos)) && is_right(s.substr(dh_pos + 1))))
            {
                all_right = false;
                break;
            }
        }
        else
        {
            int l_pos = s.find_first_of('[');
            auto name = s.substr(0,l_pos);
            auto idx = atoi(s.substr(l_pos + 1, s.size() - l_pos - 2).c_str());
            mp.insert({name, idx});
        };
        cur_line++;
    };
    return all_right ? 0 : cur_line;
}