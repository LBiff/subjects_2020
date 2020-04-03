//图的拓扑排序---解决依赖型顺序问题
//要求图：1.有向图（不相互依赖》，2.无环（不循环依赖） 3.存在至少一个入度为0的节点

#include "Graph.cpp"
#include <forward_list>
//队列实现
forward_list<Node*> GraphTopoSort(Graph g)
{
    forward_list<Node*> ret;
    queue<Node*> zero_q; //入度为0 的节点
    hash_map<Node*, int,NodeHasher> in_map; //节点的入度
    //遍历找出入度为0的节点
    for(hash_map<uint64_t, Node*, NodeHasher>::iterator iter = g._nodes_map.begin();
        iter != g._nodes_map.end(); iter++)
        {
            in_map.insert(make_pair(iter->second, iter->second->in_degree));
            if(iter->second->in_degree == 0)
            {
                zero_q.push(iter->second);
                ret.push_front(iter->second);
            }
        }

    //从入度为0的节点开始
    while(!zero_q.empty())
    {
        Node* zero_node = zero_q.front();
        zero_q.pop();
        ret.push_front(zero_node);
        for(auto child : zero_node->out_nodes)
        {
            in_map.insert(make_pair(child, child->in_degree - 1));
            if(in_map.find(child)->second == 0) 
            {
                zero_q.push(child);
            }
        }
    };

    return ret;
}