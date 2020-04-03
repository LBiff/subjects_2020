//最长无重复子串
#include <string>
#include <hash_map>
#include <unordered_map>
using namespace std;
//考虑当前字符和前一字符的重复情况
//改进：用数组
int lengthOfLongestSubstring(string s) 
{
    if(s.empty())
    {
        return 0;
    }
    unordered_map<char, int> map; //char在遍历过程中最近一次出现的位置
    int pre = -1; //遍历到i时，i-1结束的最长不重复子串的开始前一位置
    int max_len = 0;
    for(int i =0; i< s.size(); i++)
    {
        auto iter = map.find(s[i]);
        int cur_len = 0;
        if(iter != map.end()) //找到
        {
            pre = max(iter->second, pre);
            cur_len = i - pre;
            iter->second = i;
        }
        else //未找到
        {
            map.insert({s[i], i});
            cur_len = i - pre;
        };
        max_len = max(cur_len, max_len);
    };
    
    return max_len;
};
//用数组进行改进

int lengthOfLongestSubstring(string s) 
{
    if(s.empty())
    {
        return 0;
    }
    vector<int> map(256,-1); //char在遍历过程中最近一次出现的位置
    int pre = -1; //遍历到i时，i-1结束的最长不重复子串的开始前一位置
    int max_len = 0;
    for(int i =0; i< s.size(); i++)
    {
        pre = max(map[s[i]], pre);
        int cur_len = i- pre;
        max_len = max(cur_len, max_len);
        map[s[i]] = i;
    };
    return max_len;
}

int main()
{
    int a = lengthOfLongestSubstring("abcabcbb");

    return 0;
}