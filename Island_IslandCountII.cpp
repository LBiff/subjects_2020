//岛屿数量Ⅱ
// 假设你设计一个游戏，用一个 m 行 n 列的 2D 网格来存储你的游戏地图。
// 起始的时候，每个格子的地形都被默认标记为「水」。我们可以通过使用 addLand 进行操作，
// 将位置 (row, col) 的「水」变成「陆地」。
// 你将会被给定一个列表，来记录所有需要被操作的位置，然后你需要返回计算出来 每次 addLand 操作后岛屿的数量。
// 注意：一个岛的定义是被「水」包围的「陆地」，通过水平方向或者垂直方向上相邻的陆地连接而成。
// 你可以假设地图网格的四边均被无边无际的「水」所包围。
#include <vector>
using namespace std;

//后续再完善，并查集的改造
//Thinking
class UnionFind
{
    UnionFind(int m, int n):_represent_node(m * n, -1), _group_size(m * n, 1), _count(0)
    {

    };

    int Quary()
    {
        return _count;
    };

    bool IsSameSet(int a, int b)
    {
        return FindRep(a) == FindRep(b);
    };

    bool IsLand(int a)
    {
        if(a > 0 && a < _represent_node.size() && _represent_node[a] != -1)
        {
            return true;
        };

        return false;
    };

    void SetReP(int a, int rep)
    {

    }
    void Union(int a, int b)
    {
        int rep_a = FindRep(a);
        int rep_b = FindRep(b);

        if(rep_a != rep_b)
        {
            if(_group_size[rep_a] <= _group_size[rep_b])
            {
                _represent_node[rep_a] = rep_b;
                _group_size[rep_b] += _group_size[rep_a];
                _group_size[rep_a] = 0;
            }
            else
            {
                _represent_node[rep_b] = rep_a;
                _group_size[rep_a] += _group_size[rep_b];
                _group_size[rep_b] = 0;
            }
        }
    };

private:
    //只有陆地才有代表结点
    int FindRep(int n)
    {
        if(_represent_node[n] != n)
        {
            _represent_node[n] = FindRep(_represent_node[n]);
        };
        return _represent_node[n];
    };
    vector<int> _represent_node;
    vector<int> _group_size; //只对代表结点有效
    int _count; //岛屿数量
};


vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) 
{
    vector<vector<int>> v(m, vector<int>(n, 0)); //都是水
    vector<int> ret;
    if((m * n)< 1)
    {
        return ret;
    };

    int total = 0;
    for(auto p : positions)
    {
        int x = p[0];
        int y = p[1];
        v[x][y] = 1;
        //左边
    }
}