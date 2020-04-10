//【字节】
//产品经理(PM)有很多好的idea，而这些idea需要程序员实现。现在有N个PM，在某个时间会想出一个 idea，
//每个idea 有提出时间、所需时间和优先等级。对于一个PM来说，最想实现的idea首先考虑优先等级高的，
//相同的情况下优先所需时间最小的，还相同的情况下选择最早想出的，没有 PM 会在同一时刻提出两个 idea。
//同时有M个程序员，每个程序员空闲的时候就会查看每个PM尚未执行并且最想完成的一个idea,
//然后从中挑选出所需时间最小的一个idea独立实现，如果所需时间相同则选择PM序号最小的。直到完成了idea
//才会重复上述操作。如果有多个同时处于空闲状态的程序员，那么他们会依次进行查看idea的操作。
//求每个idea实现的时间。
//输入第一行三个数N、M、P，分别表示有N个PM，M个程序员，P个idea。随后有P行，每行有4个数字，分别是PM序号、
//提出时间、优先等级和所需时间。输出P行，分别表示每个idea实现的时间点。

#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

//现实模拟题
//关键数据结构
//unordered_map<int, priority_queue<Idea, vector<Idea>,Comparator>> q_map; //pm_idx, ideas
//没必要具体实现
struct Idea
{
    int _pm_idx;
    int _raise_time;
    int _priority;
    int _need_time;
};
//按照最想降序
class Comparator
{
public:
    bool operator()(const const Idea& i1, const Idea& i2)
    {
        if(i1._priority < i2._priority)
        {
            return true;
        }
        else if(i1._priority == i2._priority)
        {
            if(i1._need_time < i2._need_time)
            {
                return true;
            }
            else if(i1._need_time == i2._need_time)
            {
                if(i1._raise_time < i2._raise_time)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    };
};

vector<int> GetIdeasTime(const vector<Idea>& ideas, int pm_num, int programmer_num)
{
    //按照最想降序
    unordered_map<int, priority_queue<Idea, vector<Idea>,Comparator>> q_map; //pm_idx, ideas
    for(auto i : ideas)
    {
        auto iter = q_map.find(i._pm_idx);
        if(iter != q_map.end())
        {
            iter->second.push(i);
        }
        else
        {
            priority_queue<Idea, vector<Idea>,Comparator> q_tmp;
            q_tmp.push(i);
            q_map.insert({i._pm_idx, q_tmp});
        }
    };

    vector<pair<bool,int>> programmers(programmer_num,{false,-1}); //程序员状态, <true--忙碌，int-忙完时间>
    int time = 0;
    int total_task = ideas.size();
    int get_count = 0;
    while(!get_count < total_task)
    {
        for(auto p : programmers)
        {
            if(!p.first)  //没有忙碌
            {
                priority_queue<int,vector<int>,less<int>> task; //所需时间时间的小根堆
                for(auto iter = q_map.begin(); iter != q_map.end(); iter++)
                {
                    if(!(iter->second.empty())) //直接弹出一个来做
                    {

                    }
                }
            }
        }
    }
}