//在字符串前面添加成为最短回文字符串
//马拉车检测
#include <string>
#include <vector>
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

//本题解法：把原字符串反转，查找R第一次到达最右
//还可以观察L是否在0，就不用反转了
//好像KMP也能做? 214. 最短回文串
string shortestPalindrome(string s) 
{
    if(s.empty())
    {
        return "";
    }
    //将字符串反转，转换为R第一次到达0
    string h_s = s;
    int l_idx = 0;
    int r_idx = h_s.size() - 1;
    while(l_idx < r_idx)
    {
        swap(h_s[l_idx++], h_s[r_idx--]);
    };
    h_s = PreProssString(h_s);
    //马拉车检测R第一次到达最右
    int C = -1;
    int R = -1;
    int idx = 0;
    vector<int> half_v(h_s.size());
    int h_s_len = h_s.length();
    while(idx < h_s_len && R < h_s_len - 1)
    {
        if(idx > R)   //不在右边界内暴力搜
        {
            int l_idx = idx - 1;
            int r_idx = idx + 1;
            while(l_idx >=0  && r_idx < h_s.length() && h_s[l_idx] == h_s[r_idx])
            {
                l_idx--;
                r_idx++;
            };
            int new_half = idx - l_idx - 1;
            half_v[idx] = new_half;
            int new_r = idx + new_half;
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
            while(l_idx >=0  && r_idx < h_s.length() && h_s[l_idx] == h_s[r_idx])
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

    //还原
    string help;
    int min_l = C - half_v[idx - 1];
    for(int i =1; i < min_l; i+=2)
    {
        help += h_s[i];
    };
    help += s;
    return help;
};


int main()
{
    string s = "abbacd";
    auto ret = shortestPalindrome(s);
    return 0;
};