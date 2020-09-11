// 输出TOPK, 对于字符串，小字典序优先输出
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;



//静态TopK
//哈希建立频率，k最小堆维护TopK

//比较器涉及到下沉逻辑，返回true的下沉!!!!!
//大根堆小的下沉
//不管是大根堆还是小跟堆，最上面的肯定是要被替换的
class comparator_less
{
public:
    bool operator()(const pair<string, int>& p1, const pair<string, int>& p2)
    {
        if(p1.second < p2.second)
        {
            return true;
        }
        else if(p1.second == p2.second)
        {
            return p1.first < p2.first ? true : false;  //对于大根堆来讲，小频率的下沉，小字典序的下沉
        }
        else
        {
            return false;
        }
    }
};

class comparator_greater
{
public:
    bool operator()(const pair<string, int>& p1, const pair<string, int>& p2)
    {
        if(p1.second > p2.second)
        {
            return true;
        }
        else if(p1.second == p2.second)
        {
            return p1.first < p2.first ? true : false; //对于小根堆来讲，大频率的下沉，小字典序的下沉
        }
        else
        {
            return false;
        }
    }
};



void topKFrequent(vector<string>& words, int k)
{
    //map建立词频的索引
    unordered_map<string, int> str_f_map;
    for(auto s : words)
    {
        auto iter = str_f_map.find(s);
        if(iter != str_f_map.end()) 
        {
            iter ->second++;
        }
        else
        {
            str_f_map.insert({s, 1});
        }
    };

    //小跟堆， 最多的k
    priority_queue<pair<string, int>, vector<pair<string, int>>,comparator_greater> l_h;  //默认k
    for (auto iter = str_f_map.begin(); iter != str_f_map.end(); iter++)
    {
        pair<string, int> p_tmp = {iter->first, iter->second};
        if(l_h.size() < k) 
        {
            l_h.push(p_tmp);
        }
        else //等于k
        {
            //校验资格
            if(p_tmp.second >  l_h.top().second || (p_tmp.second ==  l_h.top().second && p_tmp.first <  l_h.top().first))
            {
                l_h.pop();
                l_h.push(p_tmp);
            }
        }
    };

    //大跟堆， 最少的k
    priority_queue<pair<string, int>, vector<pair<string, int>>,comparator_less> g_h;  //默认k
    for (auto iter = str_f_map.begin(); iter != str_f_map.end(); iter++)
    {
        pair<string, int> p_tmp = {iter->first, iter->second};
        if(g_h.size() < k) 
        {
            g_h.push(p_tmp);
        }
        else //等于k
        {
            //校验资格
            if(p_tmp.second <  l_h.top().second || (p_tmp.second ==  l_h.top().second && p_tmp.first <  l_h.top().first))
            {
                g_h.pop();
                g_h.push(p_tmp);
            }
        }
    };

  //输出需要重排序
};

int main()
{
    // int n;
    // int k;
    // cin >> n >> k;
    // vector<string> words;
    // while(n-- > 0)
    // {
    //     string tmp;
    //     cin >> tmp;
    //     words.push_back(tmp);
    // };
    vector<string> words{"1","1","2","2","3"};
    int k =2;
    topKFrequent(words, k);
    return 0;
}