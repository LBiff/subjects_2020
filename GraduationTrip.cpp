//【字节】毕业旅行问题
// 小明目前在做一份毕业旅行的规划。打算从北京出发，分别去若干个城市，然后再回到北京，
// 每个城市之间均乘坐高铁，且每个城市只去一次。由于经费有限，希望能够通过合理的路线安排
// 尽可能的省一些路上的花销。给定一组城市和每对城市之间的火车票的价钱，找到每个城市只访问
// 一次并返回起点的最小车费花销。

#include <vector>
#include <cstdlib>
using namespace std;

//动态规划的基本思路是：有最优解，最优解规模可以拆分，即确定下一地点后，后面的是子问题
//flag二进制idx位为1表示包含
//city_idx 从1开始计数
bool is_contain(int city_idx, int flag)
{
    return flag & (1 << (city_idx - 1)) != 0;
};

//将p的idx位置0，表示从集合p中移除idx
int remove_bit(int p, int city_idx)
{
    return  (p & (~(1 << (city_idx - 1))));
};
int GraduationTrip(vector<vector<int>> vv)
{
    //dp[i]{j0,j1,j2..} 表示从第i个城市出发经过j集合中的城市后回到0城市最短值
    //{j0,j1,j2..}用int位表示，1表示存在，2表示不存在
    //纵坐标-城市，，横坐标--有的j可能集合，即2^n次方
    int row_city_size = vv.size();
    int col_j_size = 1 << (row_city_size - 1);
    vector<vector<int>> dp(row_city_size,vector<int>(col_j_size, INT_MAX));

    //初始化
    //dp[i]{}表示 从i城市出发不经过其他城市直接到0 == vv[i][0]
    for(int row = 0; row < row_city_size; row++)
    {
        dp[row][0] = vv[row][0]; 
    };

    //现在已知所有dp[i]{}, dp[m]{n} = vv[m][n] + dp[n]{};
    //总的转换方程: dp[i]{j0,j1...jn} = min(dp[j0]{j1...jn} + vv[i][j0], dp[j1]{j0...jn} + vv[i][j1]...)
    //按列计算，列内计算行，列优先
    for(int col = 1; col < col_j_size; col++)
    {
        for(int row = 0; row < row_city_size; row++)  //集合内选定起点城市
        {
            if(is_contain(row,col))
            {
                continue;
            };

            for(int k = 1; k < row_city_size; k++) //枚举子问题
            {
                if(is_contain(k,col))  //在集合中
                {
                    int mid_city = remove_bit(col,k);
                    dp[row][col] = min(dp[row][col], dp[k][mid_city] + vv[row][k]);
                }
            }


        }
    };
    return dp[0][1 << (row_city_size - 1) - 1];
};

