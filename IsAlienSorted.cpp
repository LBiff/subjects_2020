//验证外星语词典
// 某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。
// 给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，返回 true；否则，返回 false。
#include <vector>
#include <string>
using namespace std;

bool isAlienSorted(vector<string>& words, string order) 
{
    if(words.size() < 2)
    {
        return true;
    }
    //建立新字典序的索引列表
    vector<int> idx_v(26,-1);
    for(int i = 0; i < order.size(); i++)
    {
        idx_v[order[i]-'a'] = i;
    };
    // s1 <= s2 升序排列 s1 <= s2
    auto is_greater = [&](const string& s1, const string& s2) -> bool 
    {
        int min_length = min(s1.length(), s2.length());
        int i = 0;
        for(; i< min_length;i++)
        {
            if(idx_v[s1[i] - 'a'] < idx_v[s2[i] - 'a'])
            {
                return true;
            }
            else if(idx_v[s1[i] - 'a'] > idx_v[s2[i] - 'a'])
            {
                return false;
            }
        };
        if(i < s1.length())
        {
            return false;
        };
        return true;
    };
    
    for(int i = 1; i< words.size(); i++)
    {
        if(is_greater(words[i-1], words[i]) != true)
        {
            return false;
        }
    };
    
    return true;
};

int main()
{
    vector<string> words{"apple","app"};
    string s = "worldabcefghijkmnpqstuvxyz";
    isAlienSorted(words, s);
}
