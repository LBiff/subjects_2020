//在 R 行 C 列的矩阵上，我们从 (r0, c0) 面朝东面开始
// 这里，网格的西北角位于第一行第一列，网格的东南角位于最后一行最后一列。
// 现在，我们以顺时针按螺旋状行走，访问此网格中的每个位置。
// 每当我们移动到网格的边界之外时，我们会继续在网格之外行走（但稍后可能会返回到网格边界）。
// 最终，我们到过网格的所有 R * C 个空间。
// 按照访问顺序返回表示网格位置的坐标列表。

#include <vector>
using namespace std;

//规律：行走的步数11223344， 每次改变方向 右下左上
vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) 
{
    int total_count = R * C;
    int cur_count = 1;
    vector<vector<int>> ret;
    vector<int> cur_idx{r0, c0};
    ret.push_back(cur_idx);
    //下一步要走的路线
    enum flag
    {
        right,
        down,
        left,
        up
    };
    int cur_flag = right;
    int cur_step = 1;
    auto PushCheck = [&]()
    {
        if(0 <= cur_idx[0] &&  cur_idx[0] < R && 0 <= cur_idx[1] && cur_idx[1] < C)
        {
            ret.push_back(cur_idx);
            cur_count++;
        };
    };

    while(cur_count < total_count)
    {
        if(cur_flag == right)
        {
            int tmp_1 = cur_step;
            while(tmp_1-- > 0)
            {
                 //向右走
                cur_idx[1] += 1;
                PushCheck();
            };
            if(cur_count == total_count) break;
            int tmp_2 = cur_step;
            while(tmp_2-- > 0)
            {
                 //向下走
                cur_idx[0] += 1;
                PushCheck();
            };
            if(cur_count == total_count) break;
            cur_flag = left;
        }
        else if(cur_flag == down)
        {
            int tmp_1 = cur_step;
            while(tmp_1-- > 0)
            {
                 //向下走
                cur_idx[0] += 1;
                PushCheck();
            };
            if(cur_count == total_count) break;
            int tmp_2 = cur_step;
            while(tmp_2-- > 0)
            {
                 //向左走
                cur_idx[1] -= 1;
                PushCheck();
            };
            if(cur_count == total_count) break;
            cur_flag = up;
        }
        else if(cur_flag == left)
        {
            int tmp_1 = cur_step;
            while(tmp_1-- > 0)
            {
                 //向左走
                cur_idx[1] -= 1;
                PushCheck();
            };
            if(cur_count == total_count) break;
            int tmp_2 = cur_step;
            while(tmp_2-- > 0)
            {
                 //向上走
                cur_idx[0] -= 1;
                PushCheck();
            };
            if(cur_count == total_count) break;
            cur_flag = right;
        }
        else //up
        {
            int tmp_1 = cur_step;
            while(tmp_1-- > 0)
            {
                 //向上走
                cur_idx[0] -= 1;
                PushCheck();
            };
            if(cur_count == total_count) break;
            int tmp_2 = cur_step;
            while(tmp_2-- > 0)
            {
                 //向右走
                cur_idx[1] += 1;
                PushCheck();
            };
            if(cur_count == total_count) break;
            cur_flag = down;
        };
        cur_step += 1;
    };
    return ret;
};

int main()
{

}
