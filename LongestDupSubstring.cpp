// 给出一个字符串 S，考虑其所有重复子串（S 的连续子串，出现两次或多次，可能会有重叠）。
// 返回任何具有最长可能长度的重复子串。（如果 S 不含重复子串，那么答案为 ""。）
 
// 示例 1：
// 输入："banana"
// 输出："ana"
// 示例 2：
// 输入："abcd"
// 输出：""

#include <string>
#include <unordered_set>
using namespace std;


//从大到小选取，因为大的肯定包括小的
//滑动窗口

string longestDupSubstring(string S) 
{
    unordered_set<string> st;
    //二分查找可能的最长
    int l_len = 1;
    int r_len = S.size() - 1;
    string ret;
    while(l_len <= r_len)
    {
        int mid_len = l_len + (r_len - l_len) / 2;
        bool is_find = false;
        for(int start = 0; start <= S.size() - mid_len + 1; start++)
        {
            auto sub_str = S.substr(start, mid_len);
            auto iter = st.find(sub_str);
            if(iter == st.end())
            {
                st.insert(sub_str);
            }
            else
            {
                is_find = true;
                ret = S.substr(start,mid_len);
                break;
            }
        };
        st.clear();
        if(is_find)
        {
            l_len = mid_len + 1;
        }
        else
        {
            r_len = mid_len - 1;
        }
    };
    return ret;
};

int main()
{
    auto ret = longestDupSubstring("abcd");
    return 0;
}