#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

//找出处拿相同颜色且糖果总数最多的3位小朋友

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
        return p1.first > p2.first ? true : false;
    }
};

// vp:count,color
// ret： idx_3, color, sum
void GetMax(const vector<pair<int, int>>& vp, 
                                  vector<int>& idxs, int& color, int& sum)
{
    // 小根堆
    // v,color
    vector<priority_queue<pair<int,int>, vector<pair<int,int>>, comparator>> sh(2);  

    for(int i = 0; i < vp.size(); i++)
    {
        auto& sh_x = sh[vp[i].second - 1];
        if(sh_x.size() < 3)
        {
            sh_x.push({vp[i].first, i});
        }
        else
        {
            if(sh_x.top().first < vp[i].first)
            {
                sh_x.pop();
                sh_x.push({vp[i].first, i});
            }
        }
    };

    //idx_tmp, sum
    vector<pair<vector<int>, int>> vt(2);

    for(int i = 0; i < 2; i++)
    {
        if(sh[i].size() == 3)
        {
            for(int j = 0; j < 3; j++)
            {
                vt[i].second += sh[i].top().first;
                vt[i].first.push_back(sh[i].top().second);
                sh[i].pop();
            }
        };
        sort(vt[i].first.begin(), vt[i].first.end());
    };
   
    auto Ret = [&](int i)
    {
        if(i == 1)
        {
            idxs = vt[0].first;
            color = 1;
            sum = vt[0].second;
        }
        else
        {
            idxs = vt[1].first;
            color = 2;
            sum = vt[1].second;
        }
    };

    if(vt[0].first.size() == 3 && vt[1].first.size() == 3)
    {
        int sum_1 = vt[0].second;
        int sum_2 = vt[1].second;
        auto& idx1_tmp = vt[0].first;
        auto& idx2_tmp = vt[1].first;
        
        if(sum_1 > sum_2)
        {
            Ret(1);
        }
        else if(sum_1 == sum_2)
        {
            if(idx1_tmp[0] < idx2_tmp[0])
            {
               Ret(1);
            }
            else
            {
               Ret(2);
            }
        }
        else
        {
           Ret(2);
        }
    }
    else
    {
        if(vt[0].first.size() == 3)
        {
            Ret(1);
        };
        if(vt[1].first.size() == 3)
        {
            Ret(2);
        }
    }
};

int main()
{
    auto p1 = GetIntVByLineBySpace();
    int count = p1[0];
    vector<pair<int,int>> vp;
    while(count-- > 0)
    {
        auto p2 = GetIntVByLineBySpace();
        vp.push_back({p2[0], p2[1]});
    };
    vector<int> idxs(3);
    int color = 0;
    int sum = 0;;
    GetMax(vp,idxs, color, sum);
    cout << idxs[0] + 1<< " " << idxs[1] + 1 << " " << idxs[2] + 1<< endl;
    cout << color << endl;
    cout << sum <<  endl;
    return 0;
};

// 6
// 2 2
// 2 1
// 3 2
// 5 2
// 3 1
// 7 2

