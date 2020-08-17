// 有 k 种颜色的涂料和一个包含 n 个栅栏柱的栅栏，每个栅栏柱可以用其中一种颜色进行上色。
// 你需要给所有栅栏柱上色，并且保证其中相邻的栅栏柱 最多连续两个 颜色相同。然后，返回所有有效涂色的方案数。
// 注意:
// n 和 k 均为非负的整数。
// 示例:
// 输入: n = 3，k = 2
// 输出: 6

#include <vector>
using namespace std;


class Solution {
private:
    int count = 0;
public:
    int numWays(int n, int k) {
        if(k < 2)
        {
            return 1;
        };
        if(k < 2)
        {
            return 1;
        };
        vector<int> color_v(n, -1);
        backTrace(color_v, 0, n,k);
        return count;
    };

    void backTrace(vector<int> color_v, int cur_idx, int n, int k)
    {
        if(cur_idx >= n)
        {
            count++;
        };

        for(int i = 0; i < k; i++)
        {
            if(cur_idx < 2)
            {
                color_v[cur_idx] = i;
                backTrace(color_v, cur_idx + 1, n , k);
            }
            else
            {
                if(color_v[cur_idx - 1] == color_v[cur_idx - 2])
                {
                    if(i != color_v[cur_idx - 1])
                    {
                        color_v[cur_idx] = i;
                        backTrace(color_v, cur_idx + 1, n , k);
                    }
                }
                else
                {
                        color_v[cur_idx] = i;
                        backTrace(color_v, cur_idx + 1, n , k);
                }
            }
        }
    }
};
