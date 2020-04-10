//区间中的最小数 * 区间所有数的和  max
// 给定一个数组序列, 需要求选出一个区间, 使得该区间是所有区间中经过如下计算的值最大的一个：
// 区间中的最小数 * 区间所有数的和最后程序输出经过计算后的最大值即可，不需要输出具体的区间。如给定序列  [6 2 1]则根据上述公式, 可得到所有可以选定各个区间的计算值:
// [6] = 6 * 6 = 36;
// [2] = 2 * 2 = 4;
// [1] = 1 * 1 = 1;
// [6,2] = 2 * 8 = 16;
// [2,1] = 1 * 3 = 3;
// [6, 2, 1] = 1 * 9 = 9;
// 从上述计算可见选定区间 [6] ，计算值为 36， 则程序输出为 36。
// 区间内的所有数字都在[0, 100]的范围内;

#include <vector>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <climits>
#include <string>
#include <stack>
using namespace std;

//从左到右假定每一个数都是最小，左右扩区间
//O(n^2)
int SectionMinMultiSumMax_n2(const vector<int>& v)
{
    int ret = INT_MIN;
    for(int i = 0; i<v.size(); i++)
    {
        if(v[i] == 0)
        {
            ret = 0 > ret ? 0 : ret;
        }
        else  //假定该数最小
        {
            int sum = v[i];
            int l = i - 1;
            int r = i+ 1;
            while(l >= 0 && v[l] >= v[i])
            {
                sum += v[l--];
            };
            while(r < v.size() && v[r] >= v[i])
            {
                sum += v[r++];
            };

            ret = sum * v[i] > ret ? sum * v[i] : ret;
        }
    };
    return ret;
};

//O(n)
//单调栈解决边界问题
//正反遍历取左右边界，求和问题可以记录累加和
int SectionMinMultiSumMax_n(const vector<int>& v)
{
    if(v.empty())
    {
        return -1;
    };
    //单调栈查找其左右边界，左右边界小于其
    //从顶到底递增，单调递增栈 
    //()双开区间
    stack<int> l_r_s; //从左到右遍历栈
    vector<int> l_r_v(v.size());
    stack<int> r_l_s; //从右到左遍历栈
    vector<int> r_l_v(v.size());

    //右边界
    for(int i = 0; i < v.size(); i++)
    {
        while(!l_r_s.empty() && v[l_r_s.top()] > v[i])
        {
            int top_i =l_r_s.top();
            l_r_s.pop();
            l_r_v[top_i] = i;
        };
        l_r_s.push(i);
    };
    while(!l_r_s.empty())
    {
        int top_i =l_r_s.top();
        l_r_v[top_i] = top_i + 1;
        l_r_s.pop();
    };

    //右到左遍历
    //左边界
    for(int i = v.size() - 1; i >= 0; i--)
    {
        while(!r_l_s.empty() && v[r_l_s.top()] > v[i])
        {
            int top_i =r_l_s.top();
            r_l_s.pop();
            r_l_v[top_i] = i;
        };
        r_l_s.push(i);
    };
    while(!r_l_s.empty())
    {
        int top_i =r_l_s.top();
        r_l_v[top_i] = top_i - 1;
        r_l_s.pop();
    };

    return 0;
}
int main()
{
    vector<int> v{81,87,47,59,81,18,25,40,56,0};
    // string s_line;
    // getline(cin, s_line);
    // getline(cin, s_line);
    // istringstream iss(s_line);
    // string s_tmp;
    // while(iss >> s_tmp)
    // {
    //     v.push_back(atoi(s_tmp.c_str()));
    // };
    
   cout <<  SectionMinMultiSumMax_n2(v) << endl;

   return 0;
};

    