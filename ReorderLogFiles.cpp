//重新排列log文件
//你有一个日志数组 logs。每条日志都是以空格分隔的字串。

// 对于每条日志，其第一个字为字母数字标识符。然后，要么：
// 标识符后面的每个字将仅由小写字母组成，或；
// 标识符后面的每个字将仅由数字组成。
// 我们将这两种日志分别称为字母日志和数字日志。保证每个日志在其标识符后面至少有一个字。
// 将日志重新排序，使得所有字母日志都排在数字日志之前。字母日志按内容字母顺序排序，忽略标识符；在内容相同时，按标识符排序。数字日志应该按原来的顺序排列。
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> reorderLogFiles(vector<string>& logs)
{
    //自定义升序排序
    //i + 1, i =>false, 
    auto comparator = [](const string& s_1, const string& s_2) -> bool
    {
        size_t first_blank_idx_1 = s_1.find_first_of(' ');
        size_t first_blank_idx_2 = s_2.find_first_of(' ');

        bool is_num_1 = ('0' <= s_1[first_blank_idx_1 + 1] &&  s_1[first_blank_idx_1 + 1] <= '9');
        bool is_num_2 = ('0' <= s_2[first_blank_idx_2 + 1]  && s_2[first_blank_idx_2 + 1] <= '9');

        if((!is_num_1 && is_num_2) || (is_num_1 && !is_num_2))
        {
            if(!is_num_1 && is_num_2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(!is_num_1 && !is_num_2) //都是字母
        {
            string flag_1 = s_1.substr(0, first_blank_idx_1);
            string flag_2 = s_2.substr(0, first_blank_idx_2);
            
            string text_1 = s_1.substr(first_blank_idx_1 + 1, s_1.size() - first_blank_idx_1 - 1);
            string text_2 = s_2.substr(first_blank_idx_2 + 1, s_2.size() - first_blank_idx_2 - 1);
            return ((text_1 < text_2) || (text_1 == text_2 && flag_1 < flag_2)) ? true : false;
        }
        else //都是数字
        {
            return false;
        }
    };
    vector<string> ret = logs;
    stable_sort(ret.begin(), ret.end(), comparator);
    return ret;
};

int main()
{
    vector<string> vs{"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"};
    auto ret = reorderLogFiles(vs);
    return 0;
}
