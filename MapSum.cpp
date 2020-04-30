//677. 键值映射
// 实现一个 MapSum 类里的两个方法，insert 和 sum。
// 对于方法 insert，你将得到一对（字符串，整数）的键值对。字符串表示键，整数表示值。
//如果键已经存在，那么原来的键值对将被替代成新的键值对。
// 对于方法 sum，你将得到一个表示前缀的字符串，你需要返回所有以该前缀开头的键的值的总和。
// 示例 1:
// 输入: insert("apple", 3), 输出: Null
// 输入: sum("ap"), 输出: 3
// 输入: insert("app", 2), 输出: Null
// 输入: sum("ap"), 输出: 5

//前缀树的应用
#include <string>
#include <unordered_map>
using namespace std;

struct Node
{
    //内部数据
    int _v;  //只有是结束节点才有效
    //结构数据
    int _pre_sum; //以此字符作为前缀最后字母的所有的值的和
    bool is_end_node; //是不是结尾节点 
    //下一节点
    unordered_map<char, Node*> _map;
    Node(int v = -1) : _v(v),_pre_sum(0), is_end_node(false){};
};

class MapSum 
{
public:
    /** Initialize your data structure here. */
    MapSum() : _root(0)
    {
    }
    
    void insert(string key, int val) 
    {
        Node* pre_node = &_root;
        //pre_node节点是这个节点的上一节点
        for(auto c : key)
        {
            auto iter = pre_node->_map.find(c);
            if(iter == pre_node->_map.end()) //没有找到建立
            {
                Node* new_node = new Node();
                pre_node ->_map.insert({c, new_node});
                pre_node = new_node;
            }
            else //找到则更新
            {
                pre_node = iter -> second;
            }
        };

        bool is_new_key = !pre_node->is_end_node;
        //更新内部数据
        pre_node->is_end_node = true;
        //更新前缀和
        //如果是新节点，则全路径需要加val, 如果是旧节点需要加 val- old_v
        int need_add = 0;
        if(is_new_key)
        {
            pre_node -> _v = val;
            need_add = val;
        }
        else
        {
            need_add = val - pre_node ->_v;
             pre_node -> _v = val;
        };

        //从头一直更新到pre_node
        Node* node = &_root;
        for(auto c : key)
        {
            node = node->_map.find(c)->second;
            node->_pre_sum += need_add;
        }
    }
    
    int sum(string prefix) 
    {
        Node* pre_node = &_root;
        //pre_node节点是这个节点的上一节点
        for(auto c : prefix)
        {
            auto iter = pre_node->_map.find(c);
            if(iter == pre_node->_map.end()) //没有找到建立
            {
                return -1; //没有
            };
            pre_node = iter->second;
        };
        return pre_node->_pre_sum;
    };

private:
    Node _root;
};


int main()
{
    MapSum ms;
    ms.insert("apple",3);
    int s1 = ms.sum("ap"); //3
    ms.insert("app",2);
    int s2 = ms.sum("ap");
    return 0;
}