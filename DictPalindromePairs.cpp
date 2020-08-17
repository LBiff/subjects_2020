//字典回文对
//给定一组唯一的单词， 找出所有不同 的索引对(i, j)，使得列表中的两个单词， 
//words[i] + words[j] ，可拼接成回文串。

#include <vector>
#include <string>
#include<unordered_map>
using namespace std;

// 正确思路，枚举每一个字符串，从后查找可能的回文，查到一个在总列表中查找前面的反转。
vector<vector<int>> palindromePairs(const vector<string>& words) 
{
};

int main()
{
    vector<string> s = {"abcd","dcba","lls","s","sssll"};
    palindromePairs(s);
}