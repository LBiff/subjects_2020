#include <string>
#include <iostream>
#include <sstream>
#include <vector>
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

void GetValue(int N, int M)
{
    vector<vector<int>> vv(N, vector<int>(N, 0));
    auto ssz = [&](int start_x, int start_y, int end_x, int end_y, int start_idx) -> int
    {
        for(int j = start_y; j <= end_y; j++)
        {
            vv[start_x][j] = start_idx++;
        };
        for(int i = start_x + 1; i <= end_x; i++)
        {
            vv[i][end_y] = start_idx++;
        };

        for(int j = end_y - 1; j >= start_y; j--)
        {
            vv[end_x][j] = start_idx++;
        };

        for(int i = end_x - 1; i >= start_x + 1; i--)
        {
            vv[i][start_y] = start_idx++;
        };
        return start_idx;
    };

    auto nsz = [&](int start_x, int start_y, int end_x, int end_y, int start_idx) -> int
    {
        for(int i = start_x; i <= end_x; i++)
        {
            vv[i][start_y] = start_idx++;
        };
        for(int j = start_y + 1; j <= end_y; j++)
        {
            vv[end_x][j] = start_idx++;
        };

        for(int i = end_x - 1; i >= start_x; i--)
        {
            vv[i][end_y] = start_idx++;
        };

        for(int j = end_y - 1; j >= start_y + 1; j--)
        {
            vv[start_x][j] = start_idx++;
        };
        return start_idx;
    };

    int start_x = 0;
    int start_y = 0;
    int end_x = N - 1;
    int end_y = N - 1;
    int start_idx = 1;
    bool is_ssz = true;

    while(start_x <= end_x && start_y <= end_y)
    {
        if(is_ssz)
        {
            start_idx = ssz(start_x, start_y, end_x, end_y, start_idx);
        }
        else
        {
            start_idx = nsz(start_x, start_y, end_x, end_y, start_idx);
        };
        is_ssz = !is_ssz;
        start_x++;
        end_x--;
        start_y++;
        end_y--;
    };


    while(M-- > 0)
    {
        auto p = GetIntVByLineBySpace();
        cout << vv[p[0]][p[1]] << endl;
    }
};

int main()
{
    auto test_count = GetIntVByLineBySpace()[0];
    while(test_count-- > 0)
    {
        auto p = GetIntVByLineBySpace();
        GetValue(p[0], p[1]);
    };
    return 0;
}