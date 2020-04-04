//3的倍数
// 给你一个整数数组 digits，你可以通过按任意顺序连接其中某些数字来形成 3 的倍数，
//请你返回所能得到的最大的3的倍数。
// 由于答案可能不在整数数据类型范围内，请以字符串形式返回答案。
// 如果无法得到答案，请返回一个空字符串。
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

//1. 采用删除法
//2. 现将全部按字符串降序排列
//3. 分别收集字符和%3==1 和 2的字符，按长度优先，否则字典序优先排序
// 如果全字符拼接%3== 0则按字典序拼接
// 如果==1  删除一个%1 或者两个%2
//如果 == 2  删除两个1 或者 一个2

//如果默认是0-9的话
class Solution 
{
public:
    string largestMultipleOfThree(vector<int>& digits) 
    {
        vector<int> cnt(10), modulo(3);
        int sum = 0;
        for (int digit: digits) 
        {
            ++cnt[digit];
            ++modulo[digit % 3];
            sum += digit;
        }

        int remove_mod = 0, rest = 0;
        if (sum % 3 == 1) 
        {
            if (modulo[1] >= 1) 
            {
                remove_mod = 1;
                rest = 1;
            }
            else 
            {
                remove_mod = 2;
                rest = 2;
            }
        }
        else if (sum % 3 == 2) 
        {
            if (modulo[2] >= 1) 
            {
                remove_mod = 2;
                rest = 1;
            }
            else 
            {
                remove_mod = 1;
                rest = 2;
            }
        }
        string ans;
        for (int i = 0; i <= 9; ++i) 
        {
            for (int j = 0; j < cnt[i]; ++j) 
            {
                if (rest && remove_mod == i % 3) 
                {
                    --rest;
                }
                else 
                {
                    ans += static_cast<char>(i + 48);
                }
            }
        }
        if (ans.size() && ans.back() == '0') 
        {
            ans = "0";
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    vector<int> d{1,1,1,2};
    Solution s;
    auto ret = s.largestMultipleOfThree(d);
    return 0;
}
