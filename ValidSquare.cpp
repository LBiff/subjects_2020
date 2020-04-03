//四点组成正方形
// 给定二维空间中四点的坐标，返回四点是否可以构造一个正方形。
// 一个点的坐标（x，y）由一个有两个整数的整数数组表示。
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//四边相等且对角线相等，但是先行进行x优先排序确定连接顺序
//避免同一点
 bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) 
{
    if(p1.size() != 2 || p2.size() != 2 || p3.size() != 2 || p4.size() != 2)
    {
        return false;
    };

    auto cal_dis = [](vector<int>& p1, vector<int>& p2) ->double
    {
        return sqrt(pow((p1[0] - p2[0]), 2) + pow((p1[1] - p2[1]), 2));
    };

    //先进行排序
    vector<vector<int>> vv{p1,p2,p3,p4};
    //x升序排列,x相等y升序
    sort(vv.begin(), vv.end(), 
    [](const vector<int>& v1, const vector<int>& v2)
    {
        return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];
    });
    //连接顺序0-1，1-3，3-2，2-0, 对角线 1-2, 0-3
    //长度相等
    //避免同一点
    int len_0_1 = cal_dis(vv[0], vv[1]);
    if(len_0_1 < 1e-12) return false;
    int len_1_3 = cal_dis(vv[1], vv[3]);
    if(len_1_3 < 1e-12) return false;
    int len_3_2 = cal_dis(vv[3], vv[2]);
    if(len_3_2 < 1e-12) return false;
    int len_2_0 = cal_dis(vv[2], vv[0]);
    if(len_2_0 < 1e-12) return false;
    int len_1_2 = cal_dis(vv[1], vv[2]);
    if(len_1_2 < 1e-12) return false;
    int len_0_3 = cal_dis(vv[0], vv[3]);
    if(len_0_3 < 1e-12) return false;

    return abs(len_0_1 - len_1_3) < 1e-12 &&
           abs(len_1_3 - len_3_2) < 1e-12 &&
           abs(len_3_2 - len_2_0) < 1e-12 &&
           abs(len_1_2 - len_0_3) < 1e-12;
};

int main()
{
    vector<int> p1{0,0};
    vector<int> p2{1,1};
    vector<int> p3{1,0};
    vector<int> p4{0,1};
    auto ret = validSquare(p1,p2,p3,p4);
    return 0; 
}