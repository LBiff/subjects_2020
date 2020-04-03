//矩阵最长增长路径
//给定一个整数矩阵matrix， 每个位置你可以向左、 右、 下、 上移动， 找到其中最长的递增路径。

#include <vector>
#include <algorithm>
using namespace std;

//从坐标处开始查找得到的最长路径
//无后效性问题： 给定参数，不论该过程被哪个子过程调用，返回值是一样的
//针对本题就是：不论是从上下左右哪到达的该坐标，返回值一样的
//改进：加傻缓存
int IncreasePath(vector<vector<int>>& vv, int row, int col, vector<vector<int>>& dp)
{
    if(dp[row][col] != -1)
    {
        return dp[row][col];
    }
    //上
    int path = (row > 0 &&  vv[row - 1][col] > vv[row][col]) 
                ? IncreasePath(vv, row - 1, col,  dp) + 1
                : 1;
    //下
    if(row < vv.size() - 1 && vv[row + 1][col] > vv[row][col])
    {
        path = std::max(IncreasePath(vv,row + 1, col,  dp) + 1, path);
    };

    //左
    if(col > 0 && vv[row][col - 1] > vv[row][col])
    {
        path = std::max(IncreasePath(vv,row, col - 1,  dp) + 1, path);
    };

    //右
    if(col < vv[0].size() - 1 && vv[row][col + 1] > vv[row][col])
    {
        path = std::max(IncreasePath(vv,row, col + 1,  dp) + 1, path);
    };

    dp[row][col] = path;
    return path;
};

int longestIncreasingPath(vector<vector<int>>& matrix)
{
    if(matrix.empty())
    {
        return 0;
    }
    vector<int> ret;
    vector<vector<int>> dp(matrix.size());
    for(int i =0; i< matrix.size(); i++)
    {
        for(int j=0; j< matrix[0].size(); j++)
        {
            dp[i].push_back(-1);
        }
    };

    for(int i =0; i< matrix.size(); i++)
    {
        for(int j = 0; j < matrix[0].size(); j++)
        {
            ret.push_back(IncreasePath(matrix,i,j,dp));
        }
    }

    return *max_element(ret.begin(), ret.end());
}



int main()
{
//  [7,6,1,1]
//  [2,7,6,0]
//  [1,3,5,1]
//  [6,6,3,2]
    vector<vector<int>> vv({{9,9,4},{6,6,8},{2,1,1}});
    int a = longestIncreasingPath(vv);
    return 0;
}