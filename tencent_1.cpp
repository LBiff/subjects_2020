//公司有n个人，有m个团队，人员编号从0~n-1, 一个人可能属于多个团队或者，给定每个团队的人员编号，
// 当一个人收到一个命令后，这个人所在的团队人员都会收到， 现将命令通知给0号员工，问最后有多少人知道了该命令

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int main() 
{

    vector<vector<int>> source_team{{1,2},{10,11,12,13,14},{0,1},{49,2},{6,7,8,2}};
    //存储<人员编号,所在的团队索引>
    unordered_map<int, vector<int>> mp;
    //根据源数据构建mp
    for(int i = 0; i < source_team.size(); i++)
    {
        for(int j = 0; j < source_team[i].size(); j++)
        {
            auto iter = mp.find(source_team[i][j]);
            if(iter != mp.end())
            {
                iter->second.push_back(i);
            }
            else
            {
                mp.insert({source_team[i][j], {i}});
            }
        }
    };
    //避免环产生，采用hash记录已经通知过的人
    unordered_set<int> st; 
    st.insert(0);
    
    //队列保存每一层需要通知的人
    queue<int> q;
    q.push(0);
    int count = 1;
    while(!q.empty())
    {
        int sz = q.size();
        while(sz-- > 0)
        {
            int top = q.front();
            q.pop();
            //找出其所关联的组
            auto iter = mp.find(top);
            if(iter != mp.end())
            {
              for(int i = 0; i < iter->second.size(); i++)
              {
                //对于每一个关联组的成员都通知（如果之前没通知的话)
                  auto& team = source_team[iter->second[i]];
                  for(int j = 0; j < team.size(); j++)
                  {
                      if(st.find(team[j]) == st.end())
                      {
                          count++;
                          q.push(team[j]);
                          st.insert(team[j]);
                      }
                  }
              }
            }
        }
    };
    cout << count << endl;
    return 0;
}