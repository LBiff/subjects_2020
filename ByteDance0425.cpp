//字节实习面试题

//1.矩阵按行排序
// matrix
// n * m
// input
// 1,2,3,4
// 3,4,5,6
// 2,3,4,5
// output
// 1,2,2,3,3,3,4,4,4,4,5,5,6
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

//N个指针
vector<int> MatrixSortByRow(const vector<vector<int>>&  vv)
{
    vector<int> tmp;
    vector<int> l_idx_v(vv.size(), 0);
    bool is_end = false;
    while(!is_end)
    {
        int min_idx = -1;
        int min_v = INT_MAX;
        for(int i = 0; i < vv.size(); i++)
        {
            if(l_idx_v[i] < vv[0].size() && vv[i][l_idx_v[i]] < min_v)
            {
                min_idx = i;
                min_v = vv[i][l_idx_v[i]];
            }
        };

        if(min_idx == -1)
        {
            is_end = true;
        }
        else
        {
            tmp.push_back(min_v);
            l_idx_v[min_idx]++;
        }
    };
    return tmp;
};

//2. 10进转-3进制

//10进制n转换为k进制
string Trans(int n, int k)
{
    if(n == 0)
    {
        return "0";
    };
    string tmp;
    while(n != 0)
    {
        int mod = ((n % k) + abs(k)) % abs(k);  //关键！！！
        tmp = to_string(mod) + tmp;
         n = (n - mod) / k;  //关键！！！
    };

    return tmp;
};


//3.求最大连续匹配括号长度
// intput
// (()))(())
// ()()
// (()())
// ))((()()
// 求最大连续匹配括号长度
//动态规划求解
int MaxLen(string str)
{
    if(str.empty())
    {
        return 0;
    }
    int max_len = 0;
    vector<int> dp(str.length(),0);  //以i结尾的最长的有效匹配
    dp[0] = 0; //一个字符肯定是无效的
    for(int i = 1; i < str.length(); i++)
    {
        if(str[i] == '(') //肯定不行
        {
            dp[i] = 0;
        }
        else
        {
            int pre = i - dp[i - 1] - 1;  //前一次匹配的前一位置
            if(pre >= 0 && str[pre] == '(')
            {
                dp[i] = dp[i - 1] + 2 + (pre > 0 ? dp[pre - 1] : 0);
            }
        };
        max_len = max(max_len, dp[i]);
    };
    return max_len;
};


//4. 跳格子游戏
// 3  5  0  7  1 。。。  3  2  0  0
// int getMinSteps(int[] arr)
// 跳格子的游戏，每个格子上有一个数，从第一个格子出发，目标是到达最后一个格子，所在的格子上的数字，决定了下一步能够跳跃的最大距离。
// 找出最少的跳数
// 无法到达返回-1
// 尽量低的时间复杂度

//动态规划
//O(n * max_i)
int jump(vector<int>& nums) 
{
    if(nums.empty())
    {
        return 0;
    }
    int size = nums.size();
    vector<int> dp(size, size); //dp[i]表示从i位置到最后的的最少步数
    dp[size - 1] = 0; //最后是不用跳的
    for(int i = size - 2; i >= 0; i--)
    {
        for(int step = nums[i]; step > 0 ; step--)
        {
            if(i + step > size - 1)
            {
                continue;
            }
            dp[i] = min(dp[i], dp[i + step] + 1);
        }
    };

    return dp[0];
};

//贪心
//在当前位置能跳的的范围内选择最终能跳的最远的max（cur + i + nums[cur + i]）
int jump_2(vector<int>& nums) 
{
    int min_step = 0;
    int cur = 0;
    while(cur < nums.size() - 1)
    {
        //在可跳范围内选择能够跳的最远的
        int max_idx = -1;
        int max_v = -1;
        for(int i = nums[cur]; i > 0; i--)
        {
            if(cur + i < nums.size() && cur + i + nums[cur + i] > max_v)
            {
                //边界处理
                if(cur + i == nums.size() -1)
                {
                    min_step++;
                    return min_step;
                }
                max_v = cur + i + nums[cur + i];
                max_idx = cur + i;
            }
        };
        cur = max_idx;
        min_step++;
    };
    return min_step;
};

// int main()
// {
//     vector<int> v{2,3,1};
//     auto tmp = jump_2(v);
//     return 0;
// }


//5. 从num中去掉N个数字，找可能结果中最大的那一个
//num=315
// N=1
// 从num中去掉N个数字，找可能结果中最大的那一个
//如果求的是最大的一个，则最优结果是从左到右递减
//最小的一个，最优结果是从左到右递增
#include <stack>

string removeKdigits_min(string num, int k) 
{
    //保持栈内严格从底到顶递增
    stack<char> s;
    for(auto c : num)
    {
        while(!s.empty() && k > 0 && s.top() > c)
        {
            s.pop();
            k -= 1;
        }
        s.push(c);
    };

    //移除多余的
   for(int i = 0; i < k; i++)
   {
       s.pop();
   };

    string ret;
    //反序输出
    while(!s.empty())
    {
        ret = to_string(s.top() - '0') + ret;
        s.pop();
    };
    //删除所有的前置0
    int idx = 0;
    while(idx < ret.size() && ret[idx] == '0')
    {
        idx++;
    };
    ret = ret.substr(idx);
    return ret.empty() ? "0" : ret;
};

int main()
{
    auto tmp = removeKdigits_min("1234567890", 9);
    return  0;
}
