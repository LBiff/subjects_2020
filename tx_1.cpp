#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> Get(const vector<int>& v1,const vector<int>& v2)
{
    auto& v1_tmp = v1.size() > v2.size() ? v1 : v2; //长的
    auto& v2_tmp = v1.size() > v2.size() ? v2 : v1; 
    int idx_1 = 0;
    int idx_2 = 0;
    vector<int> ret;
    while(idx_1 < v1_tmp.size() && idx_2 < v2_tmp.size())
    {
        while(idx_1 < v1_tmp.size() && idx_2 < v2_tmp.size() && v1_tmp[idx_1] < v2_tmp[idx_2])
        {
            idx_2++;
        };
        bool find_ret = false;
        while(idx_1 < v1_tmp.size() && idx_2 < v2_tmp.size() && v1_tmp[idx_1] >= v2_tmp[idx_2])
        {
            if(v1_tmp[idx_1] == v2_tmp[idx_2])
            {
                ret.push_back(v1_tmp[idx_1]);
                find_ret = true;
                break;                
            };
            idx_1++;
        };
        if(find_ret)
        {
            idx_1++;
            idx_2++;
        }
        else
        {
            idx_2++;
        }
        
    };
    return ret;
};


// vector<int> Get(const vector<int>& v1,const vector<int>& v2)
// {
//     unordered_map<int,int> mp1;
//     unordered_map<int,int> mp2;
//     auto& v1_tmp = v1.size() > v2.size() ? v1 : v2; //长的
//     auto& v2_tmp = v1.size() > v2.size() ? v2 : v1; 
//     for(auto v1_i : v1)
//     {
//         auto iter = mp1.find(v1_i);
//         if(iter == mp1.end())
//         {

//         }
//     }
// }

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


// 6
// 6 5 4 3 2 1
// 5
// 6 5 3 2 1
int main()
{
    // vector<int> v2{6,5,4,3,2,1};
    // vector<int> v1{6,5,3,3,2,1};
    GetIntVByLineBySpace();
    auto v1 = GetIntVByLineBySpace();
    GetIntVByLineBySpace();
    auto v2 = GetIntVByLineBySpace();
    auto ret = Get(v1,v2);
    for(int i =0; i < static_cast<int>(ret.size()) - 1; i++)
    {
        cout << ret[i] <<" ";
    };
    if(!ret.empty())
    {
        cout << ret.back();
    }
    return 0;
}
