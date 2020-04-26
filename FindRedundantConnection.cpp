//HUAWEI
// 在本问题中, 树指的是一个连通且无环的无向图。
// 输入一个图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 的树及一条附加的边构成。
// 附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边。
// 结果图是一个以边组成的二维数组。每一个边的元素是一对[u, v] ，满足 u < v，
// 表示连接顶点u 和v的无向图的边。
// 返回一条可以删去的边，使得结果图是一个有着N个节点的树。如果有多个答案，
// 则返回二维数组中最后出现的边。答案边 [u, v] 应满足相同的格式 u < v。

#include <vector>
#include <unordered_map>
using namespace std;

//并查集去做
class Solution 
{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        //各自为政
        for(auto v : edges)
        {
            auto iter_1 = map.find(v[0]);
            auto iter_2 = map.find(v[1]);

            if(iter_1 == map.end())
            {
                map.insert({v[0], v[0]});
            };
            if(iter_2 == map.end())
            {
                map.insert({v[1], v[1]});
            };
        };

        for(auto v : edges)
        {
            if(FindParent(v[0]) == FindParent(v[1]))
            {
                return v;
            }
            else
            {
                 Union(v[1],v[0]);
            }
        };

        return {-1,-1};
    };

    //合并
    void Union(int i_1, int i_2)
    {
        int p_1 = FindParent(i_1);
        int p_2 = FindParent(i_2);
        if(p_1 != p_2)
        {
            map.find(p_1)->second = p_2;
        }
    };

    //查找代表节点的过程中打平
    int FindParent(int n)
    {
        auto iter = map.find(n);
        if(iter != map.end())
        {
            if(iter->second != n)
            {
                iter->second = FindParent(iter->second);
            };
            return iter->second;
        }
        else
        {
            return -1;
        }
        
    }

private:
    unordered_map<int,int> map; //节点，和其代表节点
};

int main()
{
    Solution s;
    vector<vector<int>> vv{{1,2},{1,3},{2,3}};
    auto ret = s.findRedundantConnection(vv);
    return 0;
}