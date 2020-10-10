// 在二维地图上， 0代表海洋， 1代表陆地，我们最多只能将一格 0 海洋变成 1变成陆地。
// 进行填海之后，地图上最大的岛屿面积是多少？（上、下、左、右四个方向相连的 1 可形成岛屿）    

#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;

int largestIsland(vector<vector<int>>& grid) 
{
    int search_idx = 2; //标记搜索到的陆地
    unordered_map<int,int> mp; //idx陆地的面积
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[i].size(); j++)
        {
            if(grid[i][j] == 1)
            {
                //开始广搜
                int cur_size = 0;
                queue<pair<int,int>> stk_p;
                stk_p.push({i,j});
                grid[i][j] = search_idx; //进之前先改
                while(!stk_p.empty())
                {
                    auto top = stk_p.front();
                    cur_size++;
                    stk_p.pop();
                    //上
                    int cur_i = top.first;
                    int cur_j = top.second;
                    
                    if(cur_i > 0 && grid[cur_i - 1][cur_j] == 1)
                    {
                        grid[cur_i - 1][cur_j] = search_idx;
                        stk_p.push({cur_i - 1, cur_j});
                    };
                    //下
                    if(cur_i < grid.size() - 1 && grid[cur_i + 1][cur_j] == 1)
                    {
                        grid[cur_i + 1][cur_j] = search_idx;
                        stk_p.push({cur_i + 1, cur_j});
                    };

                    //左
                    if(cur_j > 0 && grid[cur_i][cur_j - 1] == 1)
                    {
                        grid[cur_i][cur_j - 1] = search_idx;
                        stk_p.push({cur_i, cur_j - 1});
                    };
                    //右
                    if(cur_j < grid[cur_i].size() - 1 && grid[cur_i][cur_j + 1] == 1)
                    {
                        grid[cur_i][cur_j + 1] = search_idx;
                        stk_p.push({cur_i, cur_j + 1});
                    }
                };

                mp.insert({search_idx, cur_size});
                search_idx++;
            }
        }
    };

    int max_size = 0;
    bool has_0 = false;
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[i].size(); j++)
        {
            if(grid[i][j] == 0)
            {
                has_0 = true;
                int cur_i = i;
                int cur_j = j;
                //上
                unordered_set<int> st; //记录连着的区域
                if(cur_i > 0 && grid[cur_i - 1][cur_j] > 0)
                {
                    st.insert(grid[cur_i - 1][cur_j]);
                };
                //下
                if(cur_i < grid.size() - 1 && grid[cur_i + 1][cur_j] > 0)
                {
                    st.insert(grid[cur_i + 1][cur_j]);
                };

                //左
                if(cur_j > 0 && grid[cur_i][cur_j - 1] > 0)
                {
                    st.insert(grid[cur_i][cur_j - 1]);
                };
                //右
                if(cur_j < grid[cur_i].size() - 1 && grid[cur_i][cur_j + 1] > 0)
                {
                   st.insert( grid[cur_i][cur_j + 1]);
                };
                
                int cur_size = 1;
                for(auto iter = st.begin(); iter != st.end(); iter++)
                {
                    cur_size += mp.find(*iter)->second;
                };

                max_size = max(max_size,cur_size);
            };
        };
    };

    if(!has_0)
    {
        //取mp最大
        for(auto iter = mp.begin(); iter != mp.end(); iter++)
        {
            max_size = max(max_size, iter->second);
        }
    }

    return max_size;
};

int main()
{
    vector<vector<int>> vv{{1,1},{1,1}};
    auto ret = largestIsland(vv);
    return 0;
}