//阿里笔试0727
//n层收藏品，只能取每层的两边，取m件，不能超过最大的m件的价值， 求最大价值

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;

//以空格分隔获取一行整数数组
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

int maxValue(vector<vector<int>>& vv, int sel_count)
{
    if(sel_count < 1 || vv[0].empty())
    {
        return 0;
    }

    priority_queue<int, vector<int>, greater<int>> less_heap; //小根堆
    //先计算最大价值
    for(auto v : vv)
    {
        for(int i = 1; i< v.size(); i++)
        {
            if(less_heap.size() >= sel_count)
            {
                if(v[i] > less_heap.top())
                {
                   less_heap.pop();
                    less_heap.push(v[i]);
                }
            }
            else
            {
                less_heap.push(v[i]);
            }
        }
    };
    int max_v = 0;
    while(!less_heap.empty())
    {
        max_v += less_heap.top();
        less_heap.pop();
    };

    //取两边
     priority_queue<int, vector<int>, less<int>> big_heap; //大根堆
    for(auto v : vv)
    {
        big_heap.push(v[1]);
        if(v.size() > 2)
        {
            big_heap.push(v.back());
        }
        
    };

    int get_max_v = 0;
    int get_count = 0;
    int pre_v = 0;
    while(1)
    {
        if(big_heap.empty())
        {
            break;
        }
        if(get_count < sel_count)  //没拿满直接拿
        {
           pre_v = big_heap.top();
           big_heap.pop();
           get_max_v += pre_v;
           get_count++;
        }
        else //拿满了
        {
            if(get_max_v >= max_v)
            {
                get_max_v -= pre_v; //吐出来
                pre_v = big_heap.top(); //继续选小的
                big_heap.pop();
                get_max_v += pre_v;
            }
            else
            {
                break;
            }
            
        }
    };

    return get_max_v;
};  

int main()
{
    auto v1 = GetIntVByLineBySpace();
    int level_count = v1[0];
    int sel_count = v1[1];
    vector<vector<int>> vv;
    while(level_count-- > 0)
    {
        vv.push_back(GetIntVByLineBySpace());
    };
    // vector<vector<int>> vv{{2,5,2},{4,3,4,1,5}};
    // int sel_count = 3;
    cout << maxValue(vv, sel_count);
    return 0;
}