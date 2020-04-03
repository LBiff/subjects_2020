//获取字符串数组的最小字节序拼接结果
//str1.str2 < str2.str1 则str1小，小到大贪心拼接
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//拼接比较器
class StringLessComparer
{
public:
    bool operator()(const string& s_1, const string& s_2)
    {
        string str1_2 = s_1+ s_2;
        string str2_1 = s_2 + s_1;
        if(str1_2 < str2_1)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};


int main()
{
     vector<string> a{"b", "ba","dbd", "fs"};
     std::sort(a.begin(), a.end(), StringLessComparer());
     string ret;
     for(auto a_i : a)
     {
         ret += a_i;
     };

     return 0;

}