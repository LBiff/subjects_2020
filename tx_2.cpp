#include <unordered_map>
#include <vector>
using namespace std;

int Get(int per_count, const vector<vector<int>>& team)
{
    unordered_map<int, vector<int>> mp; //人，所属团队
    for(int i = 0; i < team.size(); i++)
    {
        for(auto p : team[0])
        {
            auto iter = mp.find(p);
            if(iter == mp.end())
            {
                mp.insert({p, {i}});
            }
            else
            {
                iter->second.push_back(i);
            }
        }
    };

    // //传达给0;
    // vector<bool> p_idxs(per_count, false); // 每个人是否知晓
    // p_idxs[0] = true;
    // auto iter = mp.find(0);
    // if(iter == mp.end())
    // {
    //     return 1;
    // };

    // for()

}