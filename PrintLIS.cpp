// 给定数组arr，设长度为n，输出arr的最长递增子序列。（如果有多个答案，请输出其中字典序最小的）

#include<vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

bool is_less(const vector<int>& v1, const vector<int> v2)
{
    //默认空值的字典序最大
    //默认相等时true
    if(v1.empty() && !v2.empty())
    {
        return false;
    };
    if(v2.empty() && !v1.empty())
    {
        return true;
    }
    int idx_1 = 0;
    int idx_2 = 0;
    while(idx_1 < v1.size() && idx_2 < v2.size())
    {
        if(v1[idx_1] < v2[idx_2])
        {
            return true;
        }
        else if(v1[idx_1] > v2[idx_2])
        {
            return false;
        };
        idx_1++;
        idx_2++;
    };
    if(idx_1 < v1.size())
    {
        return false;
    }

    return true;

};

//时间O(n^2),空间O(n^2)
//注意：对于以同一个坐标结尾的可能有好几个相同长度的
//对于不同坐标结尾的可能有好几个相同长度的
vector<int> GetMaxLen(vector<int>& src)
{
    if(src.empty())
    {
        return src;
    };
    if(src.size() == 1)
    {
        return {src[0]};
    };
    vector<vector<int>> dp_vv;  //每一个以i结尾的最长递增子序列可能有多个,存储字典序最小的
    dp_vv.push_back({src[0]});
    for(int i = 1; i < src.size(); i++)
    {
        dp_vv.push_back({src[i]});
        int max_len_tmp = 1;
        for(int j = 0; j < i; j++)
        {

            int max_len_tmp_bak = max_len_tmp;
            if(src[j] < src[i])
            {
                max_len_tmp = max(max_len_tmp, (int)(dp_vv[j].size() + 1));
                vector<int> tmp_v = dp_vv[j];
                tmp_v.push_back(src[i]);
                if(max_len_tmp == max_len_tmp_bak && is_less(tmp_v, dp_vv[i]))
                {
                    dp_vv[i] = tmp_v;
                }
                else if(max_len_tmp > max_len_tmp_bak)
                {
                    dp_vv[i] = tmp_v;
                }
            };
        };
    };

        int max_v = 1;
        vector<int> ret;
        ret.push_back(src[0]);
        for(int i = 0; i < dp_vv.size(); i++)
        {
            if(dp_vv[i].size() > max_v)
            {
                max_v = dp_vv[i].size();
                ret = dp_vv[i];
            }
            else if(dp_vv[i].size() == max_v && is_less(dp_vv[i], ret))
            {
                ret = dp_vv[i];
            }
        };

        return ret;
};


//以空格分隔获取一行整数数组
vector<int> GetIntVByLineBySpace()
{
    string s;
    string word;
    vector<int> v;
    getline(cin,s);
    istringstream record(s);
    while(record >> word)
    {
        v.push_back(atoi(word.c_str()));
    };
    return v;
};

int main()
{
    vector<int> src{1,2,8,6,4};
    // GetIntVByLineBySpace();
    // vector<int> src = GetIntVByLineBySpace();
    auto ret = GetMaxLen(src);
    // if(!ret.empty())
    // {
    //     cout << ret[0];
    //     for(int i =1; i < ret.size(); i++)
    //     {
    //         cout << " " << ret[i];
    //     }
    // }
    return 0;
}