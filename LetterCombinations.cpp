//电话号码的组合
// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
#include <vector>
#include <string>
using namespace std;

vector<string> letterCombinations(string digits) 
{
    vector<string> ret; //返回结果
    if(digits.empty())
    {
        return ret;
    };
    //映射原始数字为对应的string eg:2->"abc"
    auto cal_s = [](int i) ->string
    {
        switch(i)
        {
            case 2: return "abc";
            case 3: return "def";
            case 4: return "ghi";
            case 5: return "jkl";
            case 6: return "mno";
            case 7: return "pqrs";
            case 8: return "tuv";
            case 9: return "wxyz";
            default: return "";
        };
    };
    //对s进行append每个字符的扩展
    //eg s="a", append="def"
    //1. 改"a"为"ad",,直接修改，避免删除"a"，再添加"ad"的时间损失
    //2.后面依次添加 "ae","af"
    //时间复杂度1.:O(append.length())，最大为O(4),即O(1)
    auto extern_s = [&](string& s, string append) 
    {
        string s_bak = s;
        s += append[0];
        for(int i =1; i< append.length(); i++)
        {
            ret.push_back(s_bak + append[i]);
        };
    };
    //因为采用的是直接暴力添加方法，ret先添加空"",否则循环进不去，""最后会被修改
    ret.push_back("");
    //遍历digits
    for(auto nc: digits)
    {
        //Warning: 下两行不可直接写为： for(int i =0; i< ret.size(); i++); 
        //因为每次进循环后ret都会被修改，方法只是在现有的基础上添加
        size_t ret_size = ret.size();
        for(int i =0; i< ret_size; i++) //时间复杂度2.因为每次进循环ret的size都会变化，1,3,3^2,3^3..等比数列
        {
            //对当前生成的组合每个进行新的cal_s(nc-'0')的组合添加到后面，原来的会被修改
            extern_s(ret[i], cal_s(nc-'0'));  //O(1)
        }
    };
    return ret;
};

int main()
{
    vector<string> ret = letterCombinations("2");
    return 0;
}