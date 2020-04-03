//KMP算法：KMP算法的核心是利用匹配失败后的信息，尽量减少模式串与主串的匹配次数以达到快速匹配的目的。
//具体实现就是通过一个next()函数实现，函数本身包含了模式串的局部匹配信息。KMP算法的时间复杂度O(N)

#include <string>
#include <vector>
using namespace std;

//建立next数组
vector<int> GenerateNext(string s_2)
{
    vector<int> next(s_2.size());
    if(s_2.empty())
    {
        return next;
    };

    if(s_2.size() == 1)
    {
        next = {-1};
    }
    else
    {
        //强行规定
        next[0] = -1;
        next[1] = 0;

        size_t idx = 2;
        int pre_next = 0;
        while(idx < s_2.size())
        {
            if(s_2[idx - 1] == s_2[pre_next])
            {
                next[idx++] = ++pre_next;
            }
            else if(pre_next > 0)
            {
                pre_next = next[pre_next];
            }
            else
            {
               next[idx++] = 0;
            }
        }
    };

    return next;

};


//求解s_1中是否包含s_2,若包含返回第一次出现的位置，否则-1 
int KMP(string s_1, string s_2)
{
    if(s_2.empty() || s_2.size() > s_1.size())
    {
        return -1;
    }

    //创建s_2的最长前后缀匹配长度数组 next
    //next数组的生成
    vector<int> next = GenerateNext(s_2);
   
    //字符串加速匹配
    size_t str1_idx = 0;
    size_t str2_idx = 0;
    while(str1_idx < s_1.size() && str2_idx < s_2.size())
    {
        if(s_1[str1_idx] == s_2[str2_idx])
        {
            if(str2_idx == s_2.size() - 1)
            {
                return str1_idx - str2_idx;
            }
            str1_idx++;
            str2_idx++;
        }
        else
        {
            int next_v = next[str2_idx];
            if(next_v > 0)
            {
                str2_idx = next_v;
            }
            else
            {
                str1_idx++;
            }
        }
    }
    return -1;
};



//题目：给定原字符串，在其后面添加最少的字符使其包含起始位置不同的原字符串【京东】
string AddMinChar(string s)
{
    if(s.size() == 1)
    {
        return s+s;
    };
    //获取下一位置的最长前缀和后缀匹配长度
    vector<int> next = GenerateNext(s + "a");
    int n = next.back();
    s.insert(s.end(), s.begin() + n, s.end());
    return s;
}


int main()
{
    string s_1 = "abcdabc";
    // string s_2 = "a";
    // int a = KMP(s_1, s_2);
    string a = AddMinChar(s_1);
    return 0;
}
