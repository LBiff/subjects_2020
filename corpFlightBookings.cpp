// 这里有 n 个航班，它们分别从 1 到 n 进行编号。
// 我们这儿有一份航班预订表，表中第 i 条预订记录 bookings[i] = [i, j, k] 意味着我们在从 i 到 j 的每个航班上预订了 k 个座位。
// 请你返回一个长度为 n 的数组 answer，按航班编号顺序返回每个航班上预订的座位数。

#include <vector>
using namespace std;

//直接遍历填写-超时
vector<int> corpFlightBookings_1(vector<vector<int>>& bookings, int n) 
{
    vector<int> ret(n, 0);
    for(auto b : bookings)
    {
        for(int i = b[0] - 1; i < b[1]; i++)
        {
            ret[i] += b[2];
        }
    };

    return ret;
};

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) 
{
    
}