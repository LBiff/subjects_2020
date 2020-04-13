//【字节笔试2020】
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

//给定优惠券的种类和需要买的商品，优惠券可以无限使用不收回，求解最少可以花多钱买

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

//用大根堆存储优惠券，每次检查当前优惠券是否可用
//商品降序
int MinCost_2(const vector<int>& v_1, vector<int>& v_2)
{
    //没有优惠券
    if(v_1.empty())
    {
        return accumulate(v_2.begin(),v_2.end(), 0);
    };
    if(v_2.empty())
    {
        return 0;
    };

    sort(v_2.begin(), v_2.end(), [](const int& i1, const int& i2)
    {
        return i1 > i2 ? true : false;
    }); //降序

    priority_queue<int, vector<int>, less<int>> q; //大根堆
    for(auto i : v_1)
    {
        q.push(i);
    };
    
    int cur_card = q.top();
    q.pop();
    int ret = 0;
    for(auto v2_i : v_2)
    {
        if(cur_card <= v2_i)
        {
            ret += v2_i - cur_card;
        }
        else
        {
            while(!q.empty())
            {
                cur_card = q.top();
                q.pop();
                if(cur_card <= v2_i)
                {
                    ret += v2_i - cur_card;
                    break;
                };
            }
        }
    };

    return ret;
};

//v_1是券，v_2是商品
//标记，在一起进行降序，商品前一个card是能用的最大的card
int MinCost_3(vector<int>& v_1, vector<int>& v_2)
{
    enum Type
    {
        card,
        wears
    };

    //没有优惠券
    if(v_1.empty())
    {
        return accumulate(v_2.begin(),v_2.end(), 0);
    };
    if(v_2.empty())
    {
        return 0;
    };

    vector<pair<int, Type>> pv;

    for(auto v1_i : v_1)
    {
        pv.push_back({v1_i, card});
    };

    for(auto v2_i : v_2)
    {
        pv.push_back({v2_i, wears});
    };

    //value升序
    sort(pv.begin(), pv.end(), [](const pair<int,Type>& p1, const pair<int,Type>& p2)
    {
        return p1.first < p2.first ? true : false;
    });

    int pre_card = 0;
    int ret = 0;
    int total_get = 0;
    for(auto pv_i : pv)
    {
        if(total_get < v_2.size())
        {
            if(pv_i.second == card)
            {
                pre_card = pv_i.first;
            }
            else
            {
                ret += pv_i.first - pre_card;
                total_get++;
            }
        }
        else
        {
            break;
        }
    };
    return ret;
};

int main()
{
    vector<int> a{50,100,200};
    vector<int> b{99,199,200,300};
    auto ret = MinCost_3(a,b);
    // GetIntVByLineBySpace();
    // auto v_1 = GetIntVByLineBySpace();
    // auto v_2 = GetIntVByLineBySpace();
    // cout << MinCost(v_1,v_2) << endl;

    return 0;
}