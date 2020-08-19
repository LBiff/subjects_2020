// 773. 滑动谜题
// 在一个 2 x 3 的板上（board）有 5 块砖瓦，用数字 1~5 来表示, 以及一块空缺用 0 来表示.
// 一次移动定义为选择 0 与一个相邻的数字（上下左右）进行交换.
// 最终当板 board 的结果是 [[1,2,3],[4,5,0]] 谜板被解开。
// 给出一个谜板的初始状态，返回最少可以通过多少次移动解开谜板，如果不能解开谜板，则返回 -1 。
// 示例：
// 输入：board = [[1,2,3],[4,0,5]]
// 输出：1
// 解释：交换 0 和 5 ，1 步完成
// 输入：board = [[1,2,3],[5,4,0]]
// 输出：-1
// 解释：没有办法完成谜板

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;


int slidingPuzzle(vector<vector<int>>& board) 
{
    int zero_idx = 0;
    string init_s;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == 0)
            {
                zero_idx = i * 3 + j;
            };
            init_s += (board[i][j] + '0');
        };
    };
    unordered_set<string> traveled;
    init_s.push_back(zero_idx + '0'); //最后一位为0的索引
    traveled.insert(init_s);
     
    int ret = INT_MAX;
    vector<vector<int>> trans{{1,3},{0,2,4},{1,5},{0,4},{3,1,5},{2,4}};

    //BFS
    queue<string> q;
    q.push(init_s);
    int level = 0; //保存的数据所在的层数
    string target = "123450";
    while(!q.empty())
    {
        int sz = q.size();
        while(sz-- > 0)
        {
            string top_s = q.front();
            int zero_idx = top_s.back() - '0';
            q.pop();
            if(top_s.substr(0, 6) == target)
            {
                return level;
            }
            for(auto t : trans[zero_idx])
            {
                string s_tmp = top_s;
                swap(s_tmp[zero_idx], s_tmp[t]);
                if(s_tmp.substr(0,6) == target)
                {
                    return level + 1;
                };
                s_tmp[6] = t + '0';
                if(traveled.find(s_tmp) == traveled.end())
                {
                    traveled.insert(s_tmp);
                    q.push(s_tmp);
                }
                else
                {
                    continue;
                }
            };
        };
        level++;
    };

    return -1;
};

int main()
{
    vector<vector<int>> board{{1,2,3},{5,4,0}};
    auto ret = slidingPuzzle(board);
    return 0;
}

