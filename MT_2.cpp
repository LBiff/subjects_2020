// 小美的跑腿代购
// 时间限制： 3000MS
// 内存限制： 65536KB
// 题目描述：
// 小美的一个兼职是美团的一名跑腿代购员，她有n个订单可以接，订单编号是1~n，但是因为订单的时效性，他只能选择其中m个订单接取，精明的小美当然希望自己总的获利是最大的，已知，一份订单会提供以下信息，跑腿价格v，商品重量w kg，商品每重1kg，代购费用要加2元，而一份订单可以赚到的钱是跑腿价格和重量加价之和。小美可是开兰博基尼送货的人，所以自然不会在意自己会累这种事情。请问小美应该选择哪些订单，使得自己获得的钱最多。

// 请你按照选择的订单编号的从小到大顺序，如果存在多种方案，输出订单编号字典序较小的方案。



// 输入描述
// 输入第一行包含两个正整数n，m，表示订单的数量和小美可以接的订单数量(1<=n,m<=10000)

// 接下来有n行，第i行表示i-1号订单的信息。每行有两个正整数v和w ，表示一个订单的跑腿价格和商品重量。(1<=v,w<=1000)

// 输出描述
// 输出包含m个1~n之间的正整数，中间用空格隔开，表示选择的订单编号。



#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int max_v = 0;
vector<int> sel_ret;

// cur_idx还没有处理
void GetMax(const vector<int> v, int cur_idx, int get_v, int m, vector<int> cur_sel)
{
    if(cur_idx > v.size() - 1)
    {
        return;
    }
    if(cur_sel.size() == m)
    {
        if(get_v > max_v)
        {
            max_v = get_v;
            sel_ret = cur_sel;
        }
        return;
    };
    if(cur_sel.size() > m)
    {
        return;
    }
    auto tmp_v = cur_sel;
    tmp_v.push_back(cur_idx);
    GetMax(v, cur_idx + 1, get_v + v[cur_idx], m, tmp_v);
    GetMax(v, cur_idx + 1, get_v, m, cur_sel);
};

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


class comparator
{
public: 
    bool operator()(const pair<int,int>& p1, const pair<int,int>& p2)
    {
        return p1.second > p2.second ? true : false;
    }
};
int main()
{
    auto p1 = GetIntVByLineBySpace();
    int n = p1[0];
    int m = p1[1];
    if(m > n)
    {
        return 0;
    };


    
    vector<int> v; //idx, v
    int cur_idx = 1;
    while(n-- > 0)
    {
        auto p = GetIntVByLineBySpace();
        v.push_back(p[0] + 2 * p[1]);
    };

    GetMax(v,0, 0, m, {});

    auto ret = sel_ret;
    // vector<pair<int,int>> v; //idx, v
    // int cur_idx = 1;
    // while(n-- > 0)
    // {
    //     auto p = GetIntVByLineBySpace();
    //     v.push_back({cur_idx++, p[0] + 2 * p[1]});
    // };

    // sort(v.begin(), v.end(), comparator());

    // int m_idx = v[m - 1].first;

    // vector<int> new_v;
    // for(int i = 0; i < m; i++)
    // {
    //     new_v.push_back(v[i].first);
    // }
    // sort(new_v.begin(), new_v.end());
    // if(!new_v.empty())
    // {
    //     cout << new_v[0];
    //     for(int i = 1; i < new_v.size(); i++)
    //     {
    //         cout << " " << new_v[i];
    //     }
    // }
    
    return 0;
}