//回文对问题
//给定一组唯一的单词， 找出所有不同 的索引对(i, j)，使得列表中的两个单词， words[i] + words[j] ，可拼接成回文串

//有点问题
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

//马拉车的预处理
string PreProssString(const string s)
{

    string ret;
    if(s.empty())
    {
        return ret;
    }
    ret += "#";
    for(auto s_i : s)
    {
        ret += s_i;
        ret += "#";
    };

    return ret;

};

//马拉车算法
vector<vector<int>> palindromePairs(vector<string>& words) 
{
    //空字符串可以与所有的拼接
    vector<vector<int>> ret;

    //加入哈希方便查找
    unordered_map<string,int> map;
    for (size_t i = 0; i < words.size(); i++)
    {
        map.insert(make_pair(words[i], i));
    };
    
    //情况一，全词逆序拼接
    for(size_t i = 0; i < words.size(); i++)
    {
        string s = words[i];
        string s_reverse;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            s_reverse += s[i];
        };
        auto iter = map.find(s_reverse); 
        if(iter != map.end() && iter != map.find(s))  //查找到
        {
            ret.push_back({(int)i, iter->second});
        }
    };

    //马拉车包含第一个字符的求解
    
    for(size_t s_idx = 0; s_idx < words.size(); s_idx++)
    {
        
        string s_raw = words[s_idx];
        string s = PreProssString(s_raw);
        int R = -1;
        int C = -1;
        vector<int> half_v(s.size(), 0);
        for(int i = 0; i< (int)s.size(); i++)
        {
            if(i > R) //在R右,暴力扩
            {
                int l = i - 1;
                int r = i + 1;
                int new_half = 0;
                while(l >=0 && r < (int)s.size() && s[l] == s[r])
                {
                    new_half++;
                    l--;
                    r++;
                };
                if( i + new_half > R)
                {
                    R = i + new_half;
                    C = i;
                }

                half_v[i] = new_half;
            }
            else if(half_v[2 * C - i] < (R - i)) //左对称在L内,等于i'
            {
                half_v[i] = half_v[2 * C - R];
            }
            else if(half_v[2 * C - i] == (R - i)) //左对称点半径压L边界,从R暴力扩
            {
                int new_half = R - i;

                int r_idx = R + 1;
                int l_idx = 2 * i - R - 1;
            
                while(l_idx >= 0 && r_idx < (int)s.size() && s[l_idx] == s[r_idx])
                {
                    new_half++;
                    l_idx--;
                    r_idx++;            
                };
                if(i + new_half > R)
                {
                    R = i + new_half;
                    C = i;
                };

                half_v[i] = new_half;
            }
            else //左对称点超L边界,回文到R
            {
                 half_v[i] = R - i;
            };
        };

        vector<int> radius_0; //左边界在0的回文索引
        for(size_t i = 0; i < half_v.size(); i++)
        {
            if(i - half_v[i] == 0)
            {
                radius_0.push_back(i);
            }
        };

        //翻转后面的拼接到前面
        for(size_t i=0; i<radius_0.size(); i++)
        {
            size_t r = radius_0[i] + half_v[radius_0[i]];
            string r_s_pre;
            for(int j = ((int)s.size()) -1 ; j > r; j--)
            {
                r_s_pre += s[j];
            };
            //删除预处理符号
            string r_s;
            for(int k = 1; k< (int)(r_s_pre.size()); k+= 2)
            {
                r_s += r_s_pre[k];
            }

            auto iter = map.find(r_s);
            auto iter_raw = map.find(s_raw);
            if(iter != map.end() && iter != iter_raw && r_s.length() != s_raw.length())
            {
                ret.push_back({iter->second, (int)s_idx});
            };
        }
        //翻转前面的拼接到后面
        vector<int> radius_end; //左边界在0的回文长度
        for(size_t i = 0; i < half_v.size(); i++)
        {
            if(i + half_v[i] == s.size() - 1)
            {
                radius_end.push_back(i);
            }
        };
        for(size_t i=0; i<radius_end.size(); i++)
        {
            size_t l = radius_end[i] - half_v[radius_end[i]];
            string l_s_pre;
            for(int j = l - 1 ; j >=0; j--)
            {
                l_s_pre += s[j];
            };

            //删除预处理符号
            string l_s;
            for(int k =0; k < l_s_pre.size(); k+=2)
            {
                l_s += l_s_pre[k];
            };

            auto iter = map.find(l_s);
            auto iter_raw = map.find(s_raw);
            if(iter != map.end() && iter != iter_raw  && l_s.length() != s_raw.length())
            {
                ret.push_back({(int)s_idx,iter->second});
            };

        };
    };

    //特殊处理空字符串
    // vector<int> empty_idx;
    // for(int i =0; i < words.size(); i++)
    // {
    //     if(words[i] == "")
    //     {
    //         empty_idx.push_back(i);
    //     }
    // };
    // for(int i = 0; i < empty_idx.size(); i++)
    // {
    //     for(int j=0; j < words.size(); j++)
    //     {
    //         if(j != empty_idx[i])
    //         {
    //             ret.push_back({empty_idx[i], j});
    //             ret.push_back({j,empty_idx[i]});
    //         }
    //     }
    // }
    return ret;
};

int main()
{
    vector<string> words{"abcd","dcba","lls","s","sssll",""};
    palindromePairs(words);
    return 0;
}