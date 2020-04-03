//给定一个整数 n ，你需要找到与它最近的回文数（不包括自身）。
//“最近的”定义为两个整数差的绝对值最小。
#include <string>
using namespace std;

class Solution 
{
public:
    string nearestPalindromic_2(string str) 
    {
        long str_n = stol(str);
        //最小寻找
        long low = 0;
        long up = 0;
        for(int i =str_n - 1; i>= 0; i--)
        {
            if(is_p(i))
            {
                low =i;
                break;
            }
        };

        long max = LONG_MAX;
        for(int i = str_n + 1; i<= max; i++)
        {
            if(is_p(i))
            {
                up = i;
                break;
            }
        };

        if(up - str_n == str_n - low)
        {
            return to_string(low);
        };

        return (up - str_n) < (str_n - low) ? to_string(up) : to_string(low);
    }
    bool is_p(long l)
    {
        string s = to_string(l);
        for(int i =0; i<= (s.length() - 1) / 2; i++)
        {
            if(s[i] != s[s.length() - 1 - i])
            {
                return false;
            }
        };
        return true;
    };

    string nearestPalindromic(string str) 
    {
        if(str == "0")
        {
            return to_string(1);
        }
        if(str.length() == 1)
        {
            return to_string(stol(str) - 1);
        };
        long str_n  = stol(str);
        long str_raw = stol(GetRawStr(str));
        long small  = stol(GetSmallerStr(str));
        long big  = stol(GetBiggerStr(str));
        if(str_n != str_raw)
        {
            small = str_n > str_raw ? str_raw : small;
            big = str_n > str_raw ? big : str_raw;
            if(big - str_n == str_n - small)
            {
                return to_string(small);
            }
        };
        if(big - str_n == str_n - small)
        {
            return to_string(small);
        }
        return big - str_n > str_n - small ? to_string(small) : to_string(big);
    };

//获取字符串中间对称形成的原字符串
//右边拷贝到左边
    string GetRawStr(const string& s)
    {
        string ret = s;
        for(int i =0; i <= (s.length() - 1) / 2; i++)
        {
            ret[s.length() -1 - i] = ret[i];
        }
        return ret;
    };

//获取比之刚更大的
//奇数实轴所指数位置+1， 虚数虚轴所指数位置前一位+1， 在不考虑前加0的前提下
    string GetBiggerStr(const string& s)
    {
        string ret = "0";
        ret += s;
        for(int i = (s.length() - 1) / 2 + 1; i>= 0; i--)
        {
            if(ret[i] == '9')
            {
                ret[i] = '0';
            }
            else
            {
                ret[i] += 1;
                break;
            }
        };

        //处理特殊情况
        if(ret[0] == '1')
        {
            return GetRawStr(ret);
        }
        else  //等于0舍去0
        {
            string ret_0;
            for(int i =1; i< ret.length(); i++)
            {
                ret_0 += ret[i];
            }
            return GetRawStr(ret_0);
        }
    };

//获取比之刚更小的
//奇数实轴-1， 虚数虚轴前一位-1，前不用加0
    string GetSmallerStr(const string& s)
    {
        string ret = s;
        for(int i = (s.length() -1) / 2; i>= 0; i--)
        {
            if(ret[i] == '0')
            {
                ret[i] ='9';
            }
            else
            {
                ret[i]--;
                break;
            }
        };
        //特殊处理
        if(ret[0] == '0')
        {
            string ret_0;
            for(int i =0; i< ret.size() - 1; i++)
            {
                ret_0 += '9';
            }

            return ret_0;
        }
        return GetRawStr(ret);
    }
};

int main()
{
    Solution s;
    string ret = s.nearestPalindromic_2("2");
    return 0;
}