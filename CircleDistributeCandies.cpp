//循环发糖果
// 排排坐，分糖果。
// 我们买了一些糖果 candies，打算把它们分给排好队的 n = num_people 个小朋友。
// 给第一个小朋友 1 颗糖果，第二个小朋友 2 颗，依此类推，直到给最后一个小朋友 n 颗糖果。
// 然后，我们再回到队伍的起点，给第一个小朋友 n + 1 颗糖果，第二个小朋友 n + 2 颗，依此类推，直到给最后一个小朋友 2 * n 颗糖果。
// 重复上述过程（每次都比上一次多给出一颗糖果，当到达队伍终点后再次从队伍起点开始），直到我们分完所有的糖果。注意，就算我们手中的剩下糖果数不够（不比前一次发出的糖果多），这些糖果也会全部发给当前的小朋友。
// 返回一个长度为 num_people、元素之和为 candies 的数组，以表示糖果的最终分发情况（即 ans[i] 表示第 i 个小朋友分到的糖果数）。

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution 
{
public:
    vector<int> distributeCandies(int candies, int num_people) 
    {
        vector<int> ret;
        double times = floor((- 1 + sqrt(8 * candies + 1)) / (2.0 * num_people)); //能够全程发几轮
        int reduce = candies - times *(num_people *(num_people + 1) / 2);  //剩下的
        int last_idx = floor((-1 + sqrt(1 + 8 * reduce)) / 2.0); //全部发能够发到第几个人

        for(int i = 0; i<last_idx; i++)
        {
            ret.push_back((i + 1) * times + (times - 1) * num_people + (i + 1));
        };
        int last_count = reduce - (last_idx * (last_idx + 1) / 2);
        ret.push_back((last_idx + 1) * times + (times - 1) * num_people + last_count);
        for(int j = last_idx + 1; j< num_people; j++)
        {
            ret.push_back((j + 1) * times + (times - 1) * num_people);
        };

        return ret;
    }
};