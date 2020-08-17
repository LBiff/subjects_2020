// 752. 打开转盘锁
// 你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。
// 每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。
// 锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。
// 列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
// 字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。

// 思路
// 穷举呗，再简单一点，如果你只转一下锁，有几种可能？总共有 4 个位置，每个位置可以向上转，也可以向下转，也就是有 8 种可能对吧。
// 比如说从 "0000" 开始，转一次，可以穷举出 "1000", "9000", "0100", "0900"... 共 8 种密码。然后，再以这 8 种密码作为基础，
// 对每个密码再转一下，穷举出所有可能...
// 仔细想想，这就可以抽象成一幅图，每个节点有 8 个相邻的节点，又让你求最短距离

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

//ERR 直接dfs用队列做
void GetMinPath(string cur_v, const unordered_set<string>& deadSet, string target, int& min_depth, int cur_count, 
                unordered_set<string>& traced)
{
    if(cur_v == target)
    {
        min_depth = min(min_depth, cur_count);
        return;
    };

    for(int i = 0; i < 3; i++)
    {
        string cur_v_tmp = cur_v;
        cur_v_tmp[i] = cur_v_tmp[i] == '9' ? '0' :  cur_v_tmp[i] + 1;
        if(traced.find(cur_v_tmp) == traced.end() && deadSet.find(cur_v_tmp) == deadSet.end())
        {
            traced.insert(cur_v_tmp);
            GetMinPath(cur_v_tmp, deadSet, target, min_depth,cur_count + 1, traced);
        };
        cur_v_tmp = cur_v;
        cur_v_tmp[i] = cur_v_tmp[i] == '0' ? '9' :  cur_v_tmp[i] - 1;
        if(traced.find(cur_v_tmp) == traced.end() && deadSet.find(cur_v_tmp) == deadSet.end())
        {
            traced.insert(cur_v_tmp);
            GetMinPath(cur_v_tmp, deadSet, target, min_depth,cur_count + 1, traced);
        };
    }
};



int openLock(vector<string>& deadends, string target) 
{
    unordered_set<string> deadSet;
    for(auto d : deadends)
    {
        deadSet.insert(d);
    };

    int min_depth = INT_MAX;
    unordered_set<string> traced{"0000"};
    GetMinPath("0000",deadSet,target,min_depth,0, traced);
    return min_depth == INT_MAX ? -1 : min_depth;
};

int main()
{
    vector<string> deadends{"8888"};
    string target = "0009";
    auto ret = openLock(deadends, target);
    return 0;
}