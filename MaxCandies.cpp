// 你能从盒子里获得的最大糖果数
// 给你 n 个盒子，每个盒子的格式为 {status, candies, keys, containedBoxes} ，其中：
// 状态字 status{i}：整数，如果 box{i} 是开的，那么是 1 ，否则是 0 。
// 糖果数 candies{i}: 整数，表示 box{i} 中糖果的数目。
// 钥匙 keys{i}：数组，表示你打开 box{i} 后，可以得到一些盒子的钥匙，每个元素分别为该钥匙对应盒子的下标。
// 内含的盒子 containedBoxes{i}：整数，表示放在 box{i} 里的盒子所对应的下标。
// 请你按照上述规则，返回可以获得糖果的 最大数目 。
#include <vector>
#include <queue>
using namespace std;

//广度优先搜
int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, 
               vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) 
{
    int num = status.size();
    vector<bool> has_box(num, false);  //现在已经找到的盒子
    vector<bool> can_open(num, false);  //获得钥匙或者初始已经打开
    vector<bool> used(num, false); //已经开过并统计过
    int count = 0; //获得的糖果的数量
    
    //初始化所有盒子的初始开闭状态
    for(int i = 0; i < status.size(); i++)
    {
        can_open[i] = (status[i] == 1);
    };

    queue<int>  q;
    //初始化的时候先初始化可以打开的盒子，并拿出其中的糖果，入队列进行下步递归
    for(auto i : initialBoxes)
    {
        has_box[i] = true;
        if(can_open[i])
        {
            q.push(i);
            used[i] = true;
            count += candies[i];
        }
    };
    //广度优先搜索
    //队列中是能够打开的并且糖果已经取了，需要进行拆箱操作
    //找到盒子再去匹配钥匙
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        //找钥匙
        for(auto k : keys[top])
        {
            can_open[k] = true;
            //去开之前没有打开的盒子
            if(has_box[k] && !used[k])
            {
                q.push(k);
                used[k] = true;
                count += candies[k];
            }

        };

        //查看内嵌箱子
        for(auto b : containedBoxes[top])
        {
            has_box[b] = true;
            if(can_open[b] && !used[b])
            {
                q.push(b);
                used[b] = true;
                count += candies[b];
            }
        }
    };
    return count;
};

int main() 
{
    vector<int> status{1,0,1,0};
    vector<int> candies{7,5,4,100};
    vector<vector<int>> keys{{},{},{1},{}};
    vector<vector<int>> containedBoxes{{1,2},{3},{},{}};
    vector<int> initialBoxes{0};
    auto ret = maxCandies(status, candies, keys,containedBoxes, initialBoxes);
    return 0;
}

