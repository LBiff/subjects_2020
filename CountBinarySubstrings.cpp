//查找01字符串中【连续】的0和1数量相等的子串数量
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//Thinking
//0改-1，前缀和求解
int countBinarySubstrings(string s) 
{
    int count = 0;
    pair<bool, int> p_pre; //<0/1,count>
    pair<bool, int> p_cur;

    int ret = 0;
    int pre_idx = 0;
    int cur_idx;
    for(int i = 1; i< s.size();i++)
    {
        if(s[i - 1] != s[i])
        {
            ret += min(pre_idx, cur_idx);
            pre_idx = cur_idx;
            cur_idx = 1;
        }
        else
        {
            cur_idx++;
        }
    }
};

int main()
{
    string s{"00110011"};
    auto ret = countBinarySubstrings(s);
    return 0;
}