#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

int min_time = -1;
// “0”表示空地，“1”表示墙壁，“#”表示陷阱
void Get(vector<string> s, int cur_x, int cur_y, int cur_time, const int& extra_time, unordered_set<string>& st)
{
    int sz = s.size();
    if(s[cur_x][cur_y] == '#')
    {
        cur_time += extra_time;
    }
    if(cur_x == sz -1 && cur_y == sz -1)
    {
        if(min_time == -1)
        {
            min_time = cur_time;
        }
        else
        {
            min_time = min(min_time, cur_time);
        };

        return;
    };

    s[cur_x][cur_y] = '!';

    bool up = cur_x > 0 && s[cur_x - 1][cur_y] != '1' && s[cur_x - 1][cur_y] != '!';
    bool down = cur_x < sz - 1 && s[cur_x + 1][cur_y] != '1' && s[cur_x + 1][cur_y] != '!';
    bool left = cur_y > 0 && s[cur_x][cur_y - 1] != '1' && s[cur_x][cur_y - 1] != '!';
    bool right = cur_y < sz - 1 && s[cur_x][cur_y + 1] != '1' && s[cur_x][cur_y + 1] != '!';
    if(up)
    {
       Get(s,cur_x - 1, cur_y, cur_time + 1, extra_time,st); 
    };
    if(down)
    {
       Get(s,cur_x + 1, cur_y, cur_time + 1, extra_time, st); 
    };
    if(left)
    {
       Get(s,cur_x, cur_y - 1, cur_time + 1, extra_time,st); 
    };
    if(right)
    {
       Get(s,cur_x, cur_y + 1, cur_time + 1, extra_time,st); 
    };
};

int main()
{
    int n;
    int extra_time;
    cin >> n >> extra_time;
    vector<string> vs;
    while(n-- > 0)
    {
        string tmp;
        cin >> tmp;
        vs.push_back(tmp);
    };
    unordered_set<string> st;
    Get(vs, 0,0,0, extra_time, st);
    cout << min_time << endl;
    return 0;
}