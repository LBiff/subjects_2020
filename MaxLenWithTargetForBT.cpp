//二叉树累积和等于给定值的最长路径（往下找）
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include "VisualizeBinaryTree.cpp"
#include "BTNode.h"
using namespace std;


vector<int> GetIntVByLineBySpace()
{
    string s;
    string word;
    vector<int> v;
    getline(cin,s);
    istringstream record(s);
    while(record >> word)
    {
        v.push_back(atoi(word.c_str()));
    };
    return v;
};

//构建树
Node* CreateTree(const vector<vector<int>>& vv, int root_v, int node_count)
{
    vector<Node*> node_v(node_count);
    //构建节点
    for(int i =0;i < node_count; i++)
    {
        Node* new_node = new Node(vv[i][3]);
        node_v[vv[i][0] - 1] = new_node;
    };
    //连接节点
    for(int j = 0; j< node_count; j++)
    {
       node_v[vv[j][0]- 1]->_l = vv[j][1]==0 ? nullptr :  node_v[vv[j][1] - 1];
       node_v[vv[j][0]- 1]->_r = vv[j][2]==0 ? nullptr :  node_v[vv[j][2] - 1];
    }
    return node_v[root_v - 1];
};

int PreOrder(const Node* head, int level, int target, int pre_sum, int max_len, unordered_map<int,int>& map)
{
    if(!head)
    {
        return max_len;
    };
    int cur_sum = pre_sum + head->_v;
    if(map.find(cur_sum) == map.end())
    {
        map.insert({cur_sum, level});
    };
    auto iter = map.find(cur_sum - target);
    if(iter != map.end())
    {
        max_len = max(max_len, level - iter->second);
    };
    max_len = PreOrder(head->_l, level + 1, target, cur_sum, max_len, map);
    max_len = PreOrder(head->_r, level + 1, target, cur_sum, max_len, map);
    if(map.find(cur_sum)->second == level)
    {
        map.erase(cur_sum);
    }
    return max_len;
};

//查找最长路径
int GetMaxLen(const Node* head, int target)
{
    unordered_map<int,int> map; //<value, level> 从head累加和为value的最短层level
    map.insert({0,0});
    return PreOrder(head, 1, target,0,0,map);
};

int main()
{
    vector<int> para_1{9,1};
    int node_count = para_1[0];
    int root_idx =para_1[1];
    // int idx = 0;
    vector<vector<int>> nodes{{1, 2, 3, -3},
                              {2, 4, 5, 3},
                              {4, 0, 0, 1},
                              {5, 8,9, 0},
                              {8, 0, 0, 1},
                              {9, 0, 0, 6},
                              {3, 6, 7, -9},
                             {6, 0, 0, 2},
                              {7, 0, 0, 1}};
    // while(idx < node_count)
    // {
    //     nodes.push_back(GetIntVByLineBySpace());
    // }
    Node* head  = CreateTree(nodes, root_idx, node_count);;
    int target = -9;
    PrintTree(head);
    cout << GetMaxLen(head, target);
    return 0;
}