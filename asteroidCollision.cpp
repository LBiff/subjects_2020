// 给定一个整数数组 asteroids，表示在同一行的行星。
// 对于数组中的每一个元素，其绝对值表示行星的大小，正负表示行星的移动方向（正表示向右移动，负表示向左移动）。
// 每一颗行星以相同的速度移动。
// 找出碰撞后剩下的所有行星。碰撞规则：两个行星相互碰撞，较小的行星会爆炸。如果两颗行星大小相同，则两颗行星都会爆炸。
// 两颗移动方向相同的行星，永远不会发生碰撞。

// 输入: 
// asteroids = [5, 10, -5]
// 输出: [5, 10]
// 解释: 
// 10 和 -5 碰撞后只剩下 10。 5 和 10 永远不会发生碰撞。


//Warning 用栈或者队列解决
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) 
{
    deque<int> q; //双端队列
    for(auto a : asteroids)
    {
        if(q.empty() || q.back() * a >= 0)
        {
            q.push_back(a);
        }
        else
        {
            //相反将比其小的直接消掉
            bool is_active = true;
            while(!q.empty() && q.back() * a < 0 && abs(q.back()) < abs(a))
            {
                q.pop_back();
            }
            //相反且相等相互抵消
            if(!q.empty() && q.back() * a < 0 && abs(q.back()) == abs(a))
            {
                q.pop_back();
                is_active = false;
                continue;
            }
            else if(!q.empty() && q.back() * a < 0 && abs(q.back()) > abs(a))
            {
                is_active = false;
            }
            if(is_active)
            {
                q.push_back(a);
            }
        }
    };

    vector<int> ret;
    while(!q.empty())
    {
        ret.push_back(q.front());
        q.pop_front();
    };
    return ret;
};


int main()
{
    vector<int> asteroids{5, 10, -5};
    auto ret = asteroidCollision(asteroids);
    return 0;
}