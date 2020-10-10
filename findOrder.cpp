// 现在你总共有 n 门课需要选，记为 0 到 n-1。
// 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
// 给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。
// 可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。

#include <vector>
#include <queue>
#include <hash_fun.h>
#include <unordered_map>
using namespace std;

struct Node
{
    int value;
    vector<int> in_v; //入度
    vector<int> out_v; //出度
    Node(int v) : value(v){};
};

class NodeHasher
{
public:
    size_t operator()(const Node& n)
    {
        return hash<int>()(n.value);
    }
};

//拓扑排序
vector<int> rder(int numCourses, vector<vector<int>>& prerequisites) 
{
    unordered_map<Node, vector<Node>, NodeHasher()> mp;

    for(auto p : prerequisites) 
    {
        Node n1(p[1]);
        auto iter = mp.find(p[1]);
        if(iter == mp.end())
        {
            n1.out_v.push_back()
            mp.insert({n1, })
        }
    }



}