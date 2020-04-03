//前缀树

#include <cstdlib>
#include <hash_map>
#include <iostream>
using namespace std;
using namespace __gnu_cxx;

struct Node
{
    uint64_t _pass_count; //有多少个字符串是滑过此节点
    uint64_t _end_count; //有多少字符串以此节点为结尾
    hash_map<char, Node*> nexts;
    Node():_pass_count(0), _end_count(0){};
};

enum StringType
{
    END_WIEH_STRING,  //以该字符串结束
    PREFIX_WIEH_STRING //以该字符串为前缀
};

class PrefixTree
{
public:
    void Insert(string s)
    {
        if(s.empty())
        {
            return;
        };
        Node* pre_node = _root;
        for (size_t idx = 0; idx < s.length(); idx++)
        {
            hash_map<char, Node*>::iterator node_iter = pre_node->nexts.find(s[idx]);
            if(node_iter != pre_node->nexts.end())  //存在
            {
                node_iter->second->_pass_count++;
                pre_node = node_iter->second;
            }
            else
            {
                Node* new_node = new Node();
                new_node->_pass_count++;
                pre_node->nexts.insert(pair<char,Node*>(s[idx], new_node));
                pre_node = new_node;
            };
        }
        pre_node->_end_count++;
    };

    //删除一个以s为前缀
    void Del(string s, StringType s_type)
    {
        if(Search(s) > 0)
        {
            Node* pre_node = _root;
            Node* first_del_node = nullptr; //第一个待删除的节点
            Node* node;
            for (size_t idx = 0; idx < s.length(); idx++)
            {
                if(pre_node->nexts.find(s[idx]) != pre_node->nexts.end())
                {
                    node = pre_node->nexts.find(s[idx])->second;
                    node->_pass_count--;
                    if((node->_pass_count == 0)&& !first_del_node)
                    {
                        first_del_node = node;
                    };
                    pre_node = node;
                }
                else
                {
                    return;
                }
            };
            if(s_type == END_WIEH_STRING)
            {
                node->_end_count--;
            };

            Node* next_node;
            while(first_del_node) //存在待删除的节点，从该节点起到尾全部删除
            {
                if(!first_del_node->nexts.empty())  //不是最后一个节点
                {
                    next_node = first_del_node->nexts.begin()->second;
                    delete first_del_node;
                    first_del_node = next_node;
                }
                else
                {
                    delete first_del_node;
                    break;
                }
            }
        }
    };



    //查找s字符串出现的次数
    uint64_t Search(string s, StringType s_type = PREFIX_WIEH_STRING)
    {
        if(s.empty())
        {
            return 0;
        }
        Node* pre_node = _root;
        for (size_t idx = 0; idx < s.length(); idx++)
        {
            auto node_iter = pre_node->nexts.find(s[idx]);
           if(node_iter != pre_node->nexts.end()) //如果存在
           {
               pre_node = node_iter->second;
           }
           else
           {
               return 0;
           };
        };

        switch(s_type)
        {
            case END_WIEH_STRING: 
                return pre_node->_end_count;
            case PREFIX_WIEH_STRING:
                return pre_node->_pass_count;
            default:
                return pre_node->_end_count; 
        }
    };
private:
    Node* _root = new Node();
};

int main()
{
    PrefixTree pt;
    pt.Insert("abc");
    pt.Insert("abc");
    pt.Insert("abcd");
    pt.Insert("abcde");
    pt.Insert("abcsd");

    cout << pt.Search("abc", PREFIX_WIEH_STRING) << endl;
    cout << pt.Search("abcd", PREFIX_WIEH_STRING) << endl;
    cout << pt.Search("abce", PREFIX_WIEH_STRING) << endl;
    
    
    return 0;

}