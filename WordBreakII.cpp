//单词拆分
// 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。
// 说明：
// 分隔时可以重复使用字典中的单词。
// 你可以假设字典中没有重复的单词。
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//进阶2：求出所有的拆分
class Solution 
{
public:
vector<string> wordBreak(string s, vector<string>& wordDict) 
{
    auto iter = _m.find(s);
    if(_m.find(s) != _m.end()) //存在
    {
        return iter->second;
    };
    if(s.empty()) return {""};
    vector<string> res;
    for(string word : wordDict)
    {
        if(s.substr(0,word.size()) != word) continue;
        vector<string> rem = wordBreak(s.substr(word.size()), wordDict);
        for(string str: rem)
        {
            res.push_back(word + (str.empty() ? "" : " ") + str);
        }
    };
    _m[s] = res;
    return res;
};
private:
    unordered_map<string, vector<string>> _m; //单词及其拆分,每个string都是一个拆分
};

//Error
// class solution
// {
// //原问题：求出是否能拆分
// bool wordBreak(string s, vector<string>& wordDict) 
// {
//     bool dp[s.size()];
//     //入哈希方便查找
//     unordered_set<string> set;
//     for(auto w : wordDict)
//     {
//         set.insert(w);
//     };
//     return wordBreak_dp(s,wordDict, dp, set);
// };
// bool wordBreak_dp(string s, vector<string>& wordDict, bool dp[], const unordered_set<string>& set)
// {
//     int pre_true = 0; //前面可以拆分[0,pre_true]
//     for(int i =0; i< s.size(); i++)
//     {
//         if(set.find(s.substr(0,i + 1)) != set.end() || wordBreak_dp(s.substr(pre_true, i - pre_true + 1), wordDict,dp, set))
//         {
//             dp[i] = true;
//             pre_true = i;
//         } 
//         else
//         {
//             dp[i] = false;
//         }
//     }
// }


    
}

