// 你将获得 K 个鸡蛋，并可以使用一栋从 1 到 N  共有 N 层楼的建筑。
// 每个蛋的功能都是一样的，如果一个蛋碎了，你就不能再把它掉下去。
// 你知道存在楼层 F ，满足 0 <= F <= N 任何从高于 F 的楼层落下的鸡蛋都会碎，
//从 F 楼层或比它低的楼层落下的鸡蛋都不会破。
// 每次移动，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层 X 扔下（满足 1 <= X <= N）。
// 你的目标是确切地知道 F 的值是多少。
// 无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少？

#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

//不加缓存 O(K*N^2)
//加缓存 O(KN)

//dp--有 K 个鸡蛋面对 N 层楼，这个状态下最少的扔鸡蛋次数
class Solution
{
public:
    int superEggDrop(int K, int N) 
    {
        //vv[i][j]表示有i个鸡蛋， j层楼的最坏情况下的鸡蛋不碎的最少扔鸡蛋次数
        vector<vector<int>> vv(K + 1, vector<int>(N + 1, -1));
        return mem_normal(K,N,vv);
    };

    //傻缓存
    int mem_normal(int K, int N, vector<vector<int>>& v)
    {
        if(K == 1) //逐层尝试
        {
            return N;
        };
        if(N == 0)
        {
            return 0;
        };

        int ret = INT_MAX;
        //循环只是一次选择和线性扫描无关
        for(int i = 1; i < N + 1; i++)
        {
            if(v[K - 1][i - 1] == -1)
            {
                v[K - 1][i - 1] = mem_normal(K - 1, i - 1,v);
            };
            if(v[K][N - i] == -1)
            {
                v[K][N - i] = mem_normal(K, N - i,v);
            }
            //取max因为求得是最坏情况
            ret = min(ret, max(v[K - 1][i - 1], //碎了
                            v[K][N - i]) + 1); //没碎
        }

        return ret;
    };

    //改二分搜索傻缓存
    int mem_BS(int K, int N, vector<vector<int>>& v)
    {
        if(K == 1) //逐层尝试
        {
            return N;
        };
        if(N == 0)
        {
            return 0;
        };

        int ret = INT_MAX;
        //循环只是一次选择和线性扫描无关
        //二分搜是因为dp(K - 1, i - 1) 和 dp(K, N - i)两函数组合函数分别单调，找出谷底
        int l = 1;
        int r = N;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(v[K - 1][mid - 1] == -1)
            {
                v[K - 1][mid - 1] = mem_BS(K - 1, mid - 1,v);
            };
            if(v[K][N - mid] == -1)
            {
                v[K][N - mid] = mem_BS(K, N - mid,v);
            };

            if(v[K - 1][mid - 1] > v[K][N - mid])  //碎了
            {
                r = mid - 1;
                ret = min(ret, v[K - 1][mid - 1] + 1);
            }
            else
            {
                l = mid + 1;
                ret = min(ret, v[K][N - mid] + 1);
            }
        };
        return ret;
    };

};


int main()
{
    Solution s;
    auto ret = s.superEggDrop(4,10000);
    return 0;
};