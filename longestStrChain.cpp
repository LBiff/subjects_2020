// 给出一个单词列表，其中每个单词都由小写英文字母组成。
// 如果我们可以在 word1 的任何地方添加一个字母使其变成 word2，那么我们认为 word1 是 word2 的前身。例如，"abc" 是 "abac" 的前身。
// 词链是单词 [word_1, word_2, ..., word_k] 组成的序列，k >= 1，其中 word_1 是 word_2 的前身，word_2 是 word_3 的前身，依此类推。
// 从给定单词列表 words 中选择单词组成词链，返回词链的最长可能长度。

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

int longestStrChain(vector<string>& words) 
{
    //按照长度排序
    sort(words.begin(), words.end(),
    [](const string& s1, const string& s2)
    {
        return s1.size() < s2.size();
    });

    unordered_map<string, int> mp; //记录str的最长链的长度
    int max_v = 1;
    for(int i = 0; i < words.size(); i++)
    {
        int cur_max_len = 1;
        for(int j = 0; j < words[i].size(); j++)
        {
            auto tmp = words[i];
            tmp.erase(tmp.begin() + j);
            auto iter = mp.find(tmp);
            if(iter != mp.end())
            {
                cur_max_len = max(cur_max_len, iter->second + 1);
            }
        };
        mp.insert({words[i],cur_max_len});
        max_v = max(max_v, cur_max_len);
    };

    return max_v;
};

