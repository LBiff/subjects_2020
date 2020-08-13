// 我们把玻璃杯摆成金字塔的形状，其中第一层有1个玻璃杯，第二层有2个，依次类推到第100层，
// 每个玻璃杯(250ml)将盛有香槟。
// 从顶层的第一个玻璃杯开始倾倒一些香槟，当顶层的杯子满了，任何溢出的香槟都会立刻等流量的流向左右两侧的玻璃杯。
// 当左右两边的杯子也满了，就会等流量的流向它们左右两边的杯子，依次类推。（当最底层的玻璃杯满了，香槟会流到地板上）
// 例如，在倾倒一杯香槟后，最顶层的玻璃杯满了。倾倒了两杯香槟后，第二层的两个玻璃杯各自盛放一半的香槟。
// 在倒三杯香槟后，第二层的香槟满了 - 此时总共有三个满的玻璃杯。在倒第四杯后，第三层中间的玻璃杯盛放了一半的香槟，
// 他两边的玻璃杯各自盛放了四分之一的香槟，如下图所示。
// 现在当倾倒了非负整数杯香槟后，返回第 i 行 j 个玻璃杯所盛放的香槟占玻璃杯容积的比例（i 和 j都从0开始）。

//直接动态模拟
//res[i][j]表示第i层第j索引处的香槟的数量，以1位单位, 则[i][j]位置流向[i + 1][j]和[i + 1][j + 1]
//为了减少内存，用一维数组进行模拟

#include <cmath>
#include <climits>
#include <cstdlib>
#include <vector>
using namespace std;

//ERR
//二叉树直接模拟，节点索引从0开始，坐标(0,0)
int calIdx(__uint64_t row, __uint64_t col)
{
    int new_row = row + 1;
    int new_col = col + 1;
    return new_row * 1 + new_row *(new_row - 1) * 1 / 2 - (new_row - new_col) - 1;
}
double champagneTower(int poured, int query_row, int query_glass) 
{
    int quary_idx = calIdx(query_row, query_glass);
    int total_count = quary_idx + 1;
    vector<double> v(total_count, 0);
    v[0] = poured;
    for(int row = 1; row <= query_row; row++)
    {
        for(int col = 0; col <= row; col++)
        {
            if(row == query_row && col > query_glass)
            {
                return v.back() > 1 ? 1.0 : v.back();
            }
            int cur_idx = calIdx(row, col);
           //继承自row-1, col的, 右边的
           if(col <= row - 1)
           {
                int row_1_col_idx = calIdx(row - 1, col);
                if(v[row_1_col_idx] > 1)
                {
                    double pour_count =(v[row_1_col_idx] - 1) / 2;
                    v[cur_idx] += pour_count;
                    v[row_1_col_idx] -= pour_count;

                }
           }

            //继承自row-1, col - 1的， 左边的
            if(col - 1 >= 0)
            {
                int row_1_col_idx = calIdx(row - 1, col - 1);
                if(v[row_1_col_idx] > 1)
                {
                    double pour_count = (v[row_1_col_idx] - 1);
                    v[cur_idx] += pour_count;
                    v[row_1_col_idx] -= pour_count;
                }
            };
            if(v[cur_idx] == 0.0)
            {
                return 0;
            }
        }
    };

    return v.back() > 1 ? 1.0 : v.back();
};

int main()
{
    auto ret = champagneTower(2,1,0);
    return 0;
}