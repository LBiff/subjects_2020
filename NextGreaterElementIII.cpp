// 给定一个32位正整数 n，你需要找到最小的32位整数，其与 n 中存在的位数完全相同，
// 并且其值大于n。如果不存在这样的32位整数，则返回-1。

//从右到左查找第一个降序对，a[i -1]与a[i],查找i->end刚好大于a[i-1]的数，不是第一个，是比其刚好大的，
//比如说是a[j],进行交换后，a[i]后面的数肯定是降序，进行反转为升序

#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int nextGreaterElement(unsigned int n) 
{
    if(n / 10 == 0)
    {
        return -1;
    }

    //查找第一个逆序对
    string s = to_string(n);
    char back = s.back();
    bool exist = false;
    int idx = s.size() - 2;
    for(; idx >= 0; idx--)
    {
        if(s[idx] < back)
        {
            exist = true;
            break;
        };
        back = s[idx];
    };
    if(!exist)
    {
        return -1;
    };

    //从后往前查找第一个比其刚好大的
    int greater_idx = idx;
    for(int i = s.size() - 1; i > idx; i--)
    {
        if(s[i] > s[idx])
        {
            greater_idx = i;
        }
    };

    //交换a[i]与a[j]
    swap(s[idx], s[greater_idx]);

    //将idx后进行反序
    sort(s.begin() + idx + 1, s.end());
    

    //溢出检查
    string tmp = s.substr(1);
    int tmp_i = atoi(tmp.c_str());
    string max_str = to_string(INT_MAX);
    char most_r = max_str[0]; //INT_MAX最大值为2
    if(s.length() > max_str.length() ||
        (s.length() == max_str.length() &&
          (s[0] > most_r || (s[0] == most_r && tmp_i > atoi(max_str.substr(1).c_str())))))
    {
        return -1;
    };

    return atoi(s.c_str());
};

int main()
{
    int a = nextGreaterElement(1105);
    return 0;
}