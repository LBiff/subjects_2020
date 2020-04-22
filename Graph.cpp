//图的建立

#include <cstdlib>
#include <forward_list>
#include <hash_set>
#include <vector>
#include <hash_map>
#include <functional>
#include <iostream>
#include <queue>
#include <stack>
using namespace __gnu_cxx;
using namespace std;

class Node;

class Edge
{
public:
    uint64_t _weight;//权重
    Node* _from_node;
    Node* _to_node;
    Edge():_weight(0),_from_node(nullptr),_to_node(nullptr){};
    Edge(uint64_t weight, Node* form_node, Node* to_node)
    {
        _weight = weight;
        _from_node = _from_node;
        _to_node = to_node;
    };

    ~Edge()
    {
        if(_from_node)
        {
            delete _from_node;
        };
        if(_to_node)
        {
            delete _to_node;
        }
    };


};




class Node
{
public:
    uint64_t _value;  
    uint64_t in_degree; //入度
    uint64_t out_degree; //　出度
    vector<Node*> out_nodes;
    vector<Edge*> out_edges;

    Node(uint64_t value):in_degree(0), out_degree(0), _value(value){};

    ~Node()
    {
        for(auto out_node : out_nodes)
        {
            delete out_node;
        };
        for(auto out_edge : out_edges)
        {
            delete out_edge;
        }
    };

};

//node的比较器
class NodeHasher
{
public:
    size_t operator()(const Node* node_1) const
    {
        uint64_t value = node_1->_value;
        return std::hash<uint64_t>()(value);
    };

};


class EdgeHasher
{
public:
    size_t operator()(Edge* edge) const
    {
        uint64_t value = edge->_from_node->_value;
        return std::hash<uint64_t>()(value);
    }
};


class EdgeGreaterComp
{
    bool operator()(const Edge e_1, const Edge e_2)
    {
        return e_1._weight > e_2._weight;
    }
};

//图
class Graph
{
public:
    hash_set<Edge*, EdgeHasher> _edges;
    hash_map<uint64_t, Node*, NodeHasher> _nodes_map;  //node_value, Node* 

    Graph(vector<int[3]> g_matrix) // 边权重,from节点值，to节点值
    {
        for(auto g_m_i : g_matrix)        
        {
            uint64_t edge_weight = g_m_i[0];
            uint64_t from_node_value = g_m_i[1];
            uint64_t to_node_value = g_m_i[2];

            Node* from_node;
            Node* to_node;
            if(_nodes_map.find(from_node_value) == _nodes_map.end())
            {
                from_node = new Node(from_node_value);
                _nodes_map.insert(pair<uint64_t, Node*>(from_node_value, from_node));
            }
            else
            {
                from_node = _nodes_map.find(from_node_value)->second;
            };

            if(_nodes_map.find(to_node_value) == _nodes_map.end())
            {
                to_node = new Node(to_node_value);
                _nodes_map.insert(pair<uint64_t, Node*>(to_node_value, to_node));
            }
            else
            {
                to_node = _nodes_map.find(to_node_value)->second;
            };

            Edge* edge = new Edge();

            from_node->out_degree++;
            from_node->out_edges.push_back(edge);
            from_node->out_nodes.push_back(to_node);
            from_node->_value = from_node_value;

            to_node->in_degree++;
            to_node->_value = to_node_value;

            edge->_from_node = from_node;
            edge->_to_node = to_node;
            edge->_weight = edge_weight;        

        }
    };

    //图的宽度（广度）优先遍历 breadth first search
    //利用队列实现，宽度优先就是一层一层遍历
    void Bfs(uint64_t start_value)
    {
        if(_nodes_map.find(start_value) != _nodes_map.end())
        {
            queue<Node*> q;
            Node* start_node = _nodes_map.find(start_value)->second;
            hash_set<Node*, NodeHasher> entried_set;  //已经进过队列
            q.push(start_node);
            entried_set.insert(start_node);
            while(!q.empty())
            {
                Node* cur_node = q.front();
                q.pop();
                cout << cur_node->_value << endl;
                for(auto child : cur_node->out_nodes)
                {
                    if(entried_set.find(child) != entried_set.end())
                    {
                        q.push(child);
                        entried_set.insert(child);
                    }
                }
            };

        }
    };

    //深度优先遍历
    //以起始节点开始，　1、首先以一个未被访问过的顶点作为起始顶点，沿当前顶点的边走到未访问过的顶点；
    //2、当没有未访问过的顶点时，则回到上一个顶点，继续试探别的顶点，直至所有的顶点都被访问过。
    //栈实现，注意记录每一节点的父节点，方便回溯
    void Dfs(uint64_t start_value)
    {
        auto start_node_iter = _nodes_map.find(start_value);
        if(start_node_iter != _nodes_map.end())
        {

            Node* start_node = start_node_iter->second;
            stack<Node*> node_stack;
            hash_set<Node*, NodeHasher> node_hash;
            node_stack.push(start_node);
            node_hash.insert(start_node);
            cout << start_node->_value << endl;
            while(!node_stack.empty())
            {
                Node* stack_top = node_stack.top();
                cout << stack_top->_value << endl;

                node_stack.pop();
                for(auto child : stack_top->out_nodes)
                {
                    if(node_hash.find(child) != node_hash.end())
                    {
                        node_stack.push(child);
                        node_hash.insert(child);
                    }
                }
            }
        }
    }
};


int main()
{

}