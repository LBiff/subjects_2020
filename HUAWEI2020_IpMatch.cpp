//华为2020_地址匹配
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

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
    auto line_1 = GetIntVByLineBySpace();
    int total_size = line_1[0];//总组数
    unordered_map<int,vector<int>> map; //<idx, stack_size>
    while(total_size-- > 0)
    {
        auto get = GetIntVByLineBySpace();
        map.insert({get[0],get});
    };

    vector<vector<int>> all_lists;//所有的调用
    unordered_set<int> set; //已经被调用
    int max_size = 0;
    for(auto iter = map.begin(); iter != map.end(); iter++)
    {
        unordered_set<int> geted;
        int cur_size = 0;
        bool is_get = set.find(iter->first) != set.end(); //已经被调用
        if(!is_get) //没有被吊可以作为开始
        {
            int cur_idx = iter->first;
            geted.insert(cur_idx); //加入开始
            set.insert(iter->first);
            auto iter = map.find(cur_idx);
            while(iter->second.size() > 2)
            {
                cur_size += iter->second[1];
                for(int i = 2; i < iter->second.size(); i++)
                {
                    if(geted.find(cur_idx) != geted.end())
                    {
                        cout << "R" << endl;
                    }
                    else
                    {
                        geted.insert(cur_idx);
                    };
                    cur_size += iter->second[i];
                }

            }
            
        }
    }

}