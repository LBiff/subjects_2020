//Manacher算法：求解一个字符串中最大回文子串，或者求解每一字符处的回文串，是暴力求解的加速
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

//
pair<int,string> Manacher(string s)
{
    vector<int> half_v(2 * s.size() + 1, 0);  //回文半径
    string s_p = PreProssString(s);
    int R = -1;  //右边界
    int C = -1; //右边界的中心索引
    int idx = 0;
    while(idx < s_p.length())
    {
        if(idx > R)   //不在右边界内暴力搜
        {
            int l_idx = idx - 1;
            int r_idx = idx + 1;
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
        }
        else if(half_v[C- (idx - C)] < (R - idx))  //对称点在右边界内并且idx相对于C对称点的半径在左半径内
        {
            half_v[idx++] = half_v[C- (idx - C)];
        }
        else if(half_v[C- (idx - C)] == (R - idx)) //对称点在右边界内并且idx相对于C对称点的半径在左半径上往外扩
        {
            int r_idx = R + 1;
            int l_idx = idx - (R - idx) - 1;
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

        }
        else  //在右边界内并且idx相对于C对称点的半径在左半径外，到右边界处
        {
             half_v[idx++] = R - idx;
        }
    };
    
    //后处理
    int max_idx = max_element(half_v.begin(), half_v.end()) - half_v.begin();
    bool is_virtual_axis = (max_idx % 2) == 0;

    int max_len = (1 + 2 * half_v[max_idx]) / 2;
    string max_string;
    for (int idx = max_idx - half_v[max_idx]; idx < max_idx + half_v[max_idx]; idx++)
    {
        if((idx % 2) != 0)
        {
            max_string += s_p[idx];
        }
    }
    return make_pair(max_len, max_string);
    
};


// leetcode实现
class Solution 
{
public:
string PreProcessStr(const string& s)
{
    string ret;
    if(s.empty())
    {
        return ret;
    };
    ret += "#";
    for(auto s_i : s)
    {
        ret += s_i;
        ret += "#";
    };
    return ret;
};

//马拉车的简单版本
	// public static int[] manacherrs(String word) {
	// 	char[] mchs = manachercs(word);
	// 	int[] rs = new int[mchs.length];
	// 	int center = -1;
	// 	int pr = -1;
	// 	for (int i = 0; i != mchs.length; i++) 
	// 	{
	// 		rs[i] = pr > i ? Math.min(rs[(center << 1) - i], pr - i) : 1;
	// 		while (i + rs[i] < mchs.length && i - rs[i] > -1) 
	// 		{
	// 			if (mchs[i + rs[i]] != mchs[i - rs[i]]) 
	// 			{
	// 				break;
	// 			}
	// 			rs[i]++;
	// 		}
	// 		if (i + rs[i] > pr) 
	// 		{
	// 			pr = i + rs[i];
	// 			center = i;
	// 		}
	// 	}
	// 	return rs;
	// }
//马拉车
string longestPalindrome(string s) 
{
    string p_s = PreProcessStr(s);  //预处理

    vector<int> half_v;  //回文半径
    int C = -1;
    int R = -1;
    int idx = 0;

    int max_half_len = 0;
    int max_idx = 0;
    while(R < int(p_s.length() - 1))
    {
        if(idx > R)  //暴力查找
        {
            int new_half = 0;
            int r_idx = idx + 1;
            int l_idx = idx - 1;
            while(l_idx >= 0 && r_idx < static_cast<int>(p_s.size()) && p_s[l_idx] == p_s[r_idx])
            {
                new_half++;
                l_idx--;
                r_idx++;
            };
            if(idx + new_half > R)
            {
                R = idx + new_half;
                C = idx;
            };

            half_v.push_back(new_half);

            if(new_half > max_half_len)
            {
                max_half_len = new_half;
                max_idx = idx;
            }

            idx++;

        }
        else  //在R内
        {
            int idx_l = 2 * C - idx; //左对称点
            int c_l = 2 * C - R;
            if(idx_l - half_v[idx_l] == c_l)  //压中左边界， 从R暴力扩
            {
                int new_half = R - idx;

                int r_idx = R + 1;
                int l_idx = 2 * idx - R - 1;
            
                while(l_idx >= 0 && r_idx < static_cast<int>(p_s.size()) && p_s[l_idx] == p_s[r_idx])
                {
                    new_half++;
                    l_idx--;
                    r_idx++;            
                };
                if(idx + new_half > R)
                {
                    R = idx + new_half;
                    C = idx;
                };

                half_v.push_back(new_half);

                if(new_half > max_half_len)
                {
                    max_half_len = new_half;
                    max_idx = idx;
                };

                idx++;
            }
            else if(idx_l - half_v[idx_l] > c_l) //左半径在R内
            {
                half_v.push_back(half_v[2*C - idx]);

                if(half_v[2*C - idx] > max_half_len)
                {
                    max_half_len = half_v[2*C - idx];
                    max_idx = idx;
                }

                idx++;
            }
            else //左半径在R外
            {
                half_v.push_back(R - idx);  //回文到R
                if(R - idx > max_half_len)
                {
                    max_half_len = R - idx;
                    max_idx = idx;
                };
                idx++;
            }
        }
    };

    string ret;
    if(max_idx % 2 == 0)  //偶数则为分隔符#
    {
        int l_idx = max_idx - 1;
        int r_idx = max_idx + 1;
        int half_len = 1;
        while(half_len <= max_half_len)
        {
            ret = p_s[l_idx] + ret;
            ret += p_s[r_idx];
            l_idx -= 2;
            r_idx += 2;
            half_len += 2;
        }
        return ret;
    }
    else  //奇数则为字符
    {
        ret += p_s[max_idx];
        int half_len = 2;
        int l_idx = max_idx - 2;
        int r_idx = max_idx + 2;
        while(half_len <= max_half_len)
        {
            ret = p_s[l_idx] + ret;
            ret += p_s[r_idx];
            half_len += 2;
            l_idx -= 2;
            r_idx += 2;
        };
        return ret;
    }
};
};


int main()
{
    string a = "abdcdvfvdcgg";
    string c = "abdcdvffvdcgg";
    auto b = Manacher(c);
    return 0;
};