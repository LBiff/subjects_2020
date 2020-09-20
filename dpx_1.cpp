#include <cstdint>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

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

 int countSubstrings(string s)
{
    if(s.empty())
    {
        return 0;
    }
    vector<int> half_v(2 * s.size() + 1, 0);  //回文半径
    string s_p = PreProssString(s);
    int R = -1;  //右边界
    int C = -1; //右边界的中心索引
    int idx = 0;

    //暴力搜
    auto Search = [&](int& l_idx, int& r_idx)
    {
         while(l_idx >=0  && r_idx < s_p.length() && s_p[l_idx] == s_p[r_idx])
        {
            l_idx--;
            r_idx++;
        };
        int new_half = idx - l_idx - 1;
        half_v[idx] = new_half;
        int new_r = idx + half_v[idx];
        if(new_r > R)
        {
            R = new_r;
            C = idx;
        }
        idx++;
    };

    while(idx < s_p.length())
    {
        if(idx > R)   //不在右边界内暴力搜
        {
            int l_idx = idx - 1;
            int r_idx = idx + 1;
            Search(l_idx, r_idx);
        }
        else if(half_v[C- (idx - C)] < (R - idx))  //对称点在右边界内并且idx相对于C对称点的半径在左半径内
        {
            half_v[idx++] = half_v[C- (idx - C)];
        }
        else if(half_v[C- (idx - C)] == (R - idx)) //对称点在右边界内并且idx相对于C对称点的半径在左半径上往外扩
        {
            int r_idx = R + 1;
            int l_idx = idx - (R - idx) - 1;
            Search(l_idx, r_idx);
        }
        else  //在右边界内并且idx相对于C对称点的半径在左半径外，到右边界处
        {
             half_v[idx++] = R - idx;
        }
    };
    
   int sz = half_v.size();
   int ret = 0;
   for(int i = 1; i < sz; i++)
   {
       if(i % 2 == 0) //压中原字符
       {
           ret += half_v[i] / 2 + 1;
       }
       else //压中预处理字符
       {
            ret += half_v[i] / 2;
       }
   };
   return ret;
    
};


int main()
{
    string c = "aaa";
    auto b = Count(c);
    return 0;
};