//1244 力扣排行榜
// 新一轮的「力扣杯」编程大赛即将启动，为了动态显示参赛者的得分数据，需要设计一个排行榜 Leaderboard。
// 请你帮忙来设计这个 Leaderboard 类，使得它有如下 3 个函数：
// addScore(playerId, score)：
// 假如参赛者已经在排行榜上，就给他的当前得分增加 score 点分值并更新排行。
// 假如该参赛者不在排行榜上，就把他添加到榜单上，并且将分数设置为 score。
// top(K)：返回前 K 名参赛者的 得分总和。
// reset(playerId)：将指定参赛者的成绩清零。题目保证在调用此函数前，该参赛者已有成绩，并且在榜单上。
// 请注意，在初始状态下，排行榜是空的。

#include <unordered_map> //map是排序的
#include <numeric>
#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;


//map映射，multiset排序
class Leaderboard 
{
public:
    Leaderboard() 
    {

    }
    
    void addScore(int playerId, int score) 
    {
        auto iter = _map.find(playerId);
        if(iter != _map.end())
        {
            _set.erase(iter->second);
            iter->second += score;
            _set.insert(iter->second);

        }
        else
        {
            _set.insert(score);
            _map.insert({playerId, score});
        }
    };
    
    int top(int K) 
    {
        int sum = 0;
        auto iter = _set.begin();
        while(K-- > 0)
        {
            if(iter == _set.end())
            {
                break;
            };
            sum += (*iter);
            iter++;
        };

        return sum;
    };

    void reset(int playerId) 
    {
        auto iter = _map.find(playerId);
        if(iter != _map.end())
        {
            _set.erase(iter->second);
            _set.insert(0);
            iter->second = 0;
        }
    };
private:
    unordered_map<int, int> _map; //id, score
    multiset<int,greater<int>> _set; //内部自排序,默认升序，需要降序排
};

int main()
{
    Leaderboard l;
    vector<string> vs{"addScore","addScore","addScore","addScore","addScore","top","reset","reset","addScore","top"};
    vector<vector<int>> vv{{1,73},{2,56},{3,39},{4,51},{5,4},{1},{1},{2},{2,51},{3}};
    for(int i = 0; i<vs.size(); i++)
    {
        if(vs[i] == "top")
        {
            cout << "top== " << l.top(vv[i][0]) << endl;
        }
        else if(vs[i] == "addScore")
        {
            l.addScore(vv[i][0],vv[i][1]);
        }
        else if(vs[i] == "reset")
        {
            l.reset(vv[i][0]);
        }
    }
    return 0;
}