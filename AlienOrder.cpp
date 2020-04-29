//火星词典
//拓扑排序:每次删除入度为0的节点
// 现有一种使用字母的全新语言，这门语言的字母顺序与英语顺序不同。
// 假设，您并不知道其中字母之间的先后顺序。但是，会收到词典中获得一个 不为空的 单词列表。
//因为是从词典中获得的，所以该单词列表内的单词已经 按这门新语言的字母顺序进行了排序。
// 您需要根据这个输入的列表，还原出此语言中已知的字母顺序。

//拓扑排序
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

struct NodeAttri
{
    int _in_degree = 0;
    unordered_set<char> _out_c_set;
    NodeAttri(int in_v) : _in_degree(in_v){};
};
//只能词间比较
string alienOrder(vector<string> &words) 
{
    unordered_map<char, NodeAttri> map;
    //第一个单词入度为0
    for(auto c : words[0])
    {
        if(map.find(c) == map.end())
        {
            map.insert({c, NodeAttri(0)});
        }
    }
    //词间连接图
    for(int i =0; i< words.size() - 1; i++)
    {
        int min_length = min(words[i].size(), words[i+1].size());
        int j = 0;
        for(; j< min_length; j++)
        {
            //两个节点先建立起来
            if(map.find(words[i][j]) == map.end())
            {
                map.insert({words[i][j], NodeAttri(0)});
            };
            if(map.find(words[i + 1][j]) == map.end())
            {
                map.insert({words[i + 1][j], NodeAttri(0)});
            };
            //进行连接
            if(words[i][j] != words[i+1][j])
            {
                //没有该记录才添加
                auto iter_w1 = map.find(words[i][j]);
                auto iter_w2 = map.find(words[i + 1][j]);
                if(iter_w1->second._out_c_set.find(words[i+1][j])
                   == iter_w1->second._out_c_set.end())
                {
                    iter_w1->second._out_c_set.insert(words[i + 1][j]);
                    iter_w2->second._in_degree++;
                }
            }
        };

        //后续多的只需要建立节点,j压中下一多字符
        while(j < words[i].size() - 1)
        {
            if(map.find(words[i][j]) != map.end())
            {
                map.insert({words[i][j], NodeAttri(0)});
            };
            j++;
        };
        while(j < words[i + 1].size() - 1)
        {
            if(map.find(words[i + 1][j]) != map.end())
            {
                map.insert({words[i + 1][j], NodeAttri(0)});
            }
            j++;
        };
    };

    //正确输出的前提是每次只有一个入度为0的节点，且全部输出
    string ret;
    vector<char> zero_v;
    for(auto iter = map.begin(); iter != map.end(); iter++)
    {
        if(iter->second._in_degree == 0)
        {
            zero_v.push_back(iter->first);
        }
    };
    if(zero_v.size() != 1)
    {
        return "";
    };
    ret += zero_v[0];
    //保证每次只有一个形成单链表
    char head = zero_v[0];
    auto iter_head = map.find(head);
    while(iter_head->second._out_c_set.size() == 1)
    {
        char c = *(iter_head->second._out_c_set.begin());
        ret += c;
        iter_head = map.find(c);
    };
    return ret.size() == map.size() ? ret : "";
};

int main()
{
    vector<string> d{"z","x","z"};
    auto ret = alienOrder(d);
    return 0;
}