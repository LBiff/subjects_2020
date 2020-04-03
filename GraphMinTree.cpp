//图的最小生成树

//K算法，考察边，需要并查集考察回路，小根堆依次选取最小权重边

#include "UnionFindSet.cpp"
#include "Graph.cpp"
#include <queue>
#include <vector>

vector<Edge> KruskalMinTree(const Graph& g)
{
    vector<Edge> ret;
    //用节点构建并查集合
    UnionFindSet<Node*> union_set_node;
    for(auto iter = g._nodes_map.begin(); iter != g._nodes_map.end(); iter++)
    {
        union_set_node.Insert(iter->second);
    };

    //构建边的小根堆
    priority_queue<const Edge> edge_heap;
    for(auto iter = g._edges.begin(); iter != g._edges.end(); iter++)
    {
        edge_heap.push(**iter);
    }

    greater<int> a;
    while(!edge_heap.empty())
    {
        const Edge edge = edge_heap.top();
        edge_heap.pop();
        if(!union_set_node.isSameSet(edge._from_node, edge._to_node))  //不在一个集合则无环就要
        {
            ret.push_back(edge);
            union_set_node.UnionSet(edge._from_node, edge._to_node);
        }
    };

    return ret;
}

//P算法， 考察节点
vector<Edge> PrimMinTree(const Graph& g)
{
    vector<Edge> ret;
    //选取开始节点
    Node* node = g._nodes_map.begin()->second;
    hash_set<Node*> noded_set;
    priority_queue<Edge,vector<Edge>, EdgeGreaterComp> edge_heap;

    noded_set.insert(node);
    for(auto edge_i : node->out_edges)
    {
        edge_heap.push(*edge_i);
    }
    while(!edge_heap.empty())
    {
        Edge edge = edge_heap.top();
        edge_heap.pop();
        if(noded_set.find(edge._to_node) == noded_set.end())
        {
            ret.push_back(edge);
            noded_set.insert(edge._to_node);
            for(auto edge_i : edge._to_node->out_edges)
            {
                edge_heap.push(*edge_i);
            }
        }
    }
}

