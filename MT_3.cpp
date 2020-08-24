// 小美的仓库整理
// 时间限制： 3000MS
// 内存限制： 65536KB
// 题目描述：
//        小美是美团仓库的管理员，她会根据单据的要求按顺序取出仓库中的货物，每取出一件货物后会把剩余货物重新堆放，使得自己方便查找。已知货物入库的时候是按顺序堆放在一起的。如果小美取出其中一件货物，则会把货物所在的一堆物品以取出的货物为界分成两堆，这样可以保证货物局部的顺序不变。

//        已知货物最初是按1~n的顺序堆放的，每件货物的重量为w_i,小美会根据单据依次不放回的取出货物。请问根据上述操作，小美每取出一件货物之后，重量和最大的一堆货物重量是多少？



// 输入描述
// 输入第一行包含一个正整数n，表示货物的数量。(1<=n,m<=50000)

// 输入第二行包含n个正整数，表示1~n号货物的重量w_i。(1<=w_i<=100)

// 输入第三行有n个数，表示小美按顺序取出的货物的编号，也就是一个1~n的全排列。

// 输出描述
// 输出包含n行，每行一个整数，表示每取出一件货物以后，对于重量和最大的一堆货物，其重量和为多少。


#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int GetMax(vector<pair<int, bool>>& cur_status, int del_idx)
{
    cur_status[del_idx].second = false;
    int max_v = 0;
    int cur_sum = 0;
    for(auto c : cur_status)
    {
        if(c.second == false)
        {
            max_v = max(max_v, cur_sum);
            cur_sum = 0;
            continue;
        }
        else
        {
            cur_sum += c.first;
            max_v = max(max_v, cur_sum);
        }
    };

    return max_v;
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


int main()
{
    int count = GetIntVByLineBySpace()[0];
    auto weight = GetIntVByLineBySpace();
    vector<pair<int, bool>> vv;
    for(auto w : weight)
    {
        vv.push_back({w,true});
    };
    auto del_idx = GetIntVByLineBySpace();
    
    for(int i = 0; i < del_idx.size(); i++)
    {
        int ret = GetMax(vv, del_idx[i] - 1);
        cout << ret << endl;
    };
    return 0;
}