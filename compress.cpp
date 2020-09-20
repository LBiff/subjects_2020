// 给定一组字符，使用原地算法将其压缩。
// 压缩后的长度必须始终小于或等于原数组长度。
// 数组的每个元素应该是长度为1 的字符（不是 int 整数类型）。
// 在完成原地修改输入数组后，返回数组的新长度。
// 进阶：
// 你能否仅使用O(1) 空间解决问题？

#include <vector>
#include <string>
using namespace std;

int compress(vector<char>& chars) 
{
    if(chars.empty())
    {
        return 0;
    };

    auto cal_count_len = [](const int cur_count)
    {
        if(cur_count / 1000 > 0)
        {
            return 4;
        }
        else if(cur_count / 100 > 0)
        {
            return 3;
        }
        else if(cur_count / 10 > 0)
        {
            return 2;
        }
        return 1;
    };

    int ret = 0;
    char pre = chars[0];
    int cur_count = 1;
    int next_modify_idx = 0;
    for(int i = 1; i < chars.size(); i++)
    {
        if(chars[i] == pre)
        {
            cur_count++;
        }
        else
        {
            chars[next_modify_idx++] = pre;
            if(cur_count == 1)
            {
                ret += 1;
            }
            else
            {
                int len = cal_count_len(cur_count);
                ret += (len + 1);
                string tmp = to_string(cur_count);
                for(auto c : tmp)
                {
                    chars[next_modify_idx++] = c;
                }
            };
            pre = chars[i];
            cur_count = 1;
        }
    };

    chars[next_modify_idx++] = pre;
    if(cur_count == 1)
    {
        ret += 1;
    }
    else
    {
        int len = cal_count_len(cur_count);
        ret += (len + 1);
        string tmp = to_string(cur_count);
        for(auto c : tmp)
        {
            chars[next_modify_idx++] = c;
        }
    };
    return ret;
};

int main()
{
    vector<char> vc{'a','a','b','b','c','c','c'};
    auto ret = compress(vc);
    return 0;
}