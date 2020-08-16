#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int leaf_count = 0;

void CalCount(unordered_map<int, int> pre, unordered_map<int, int> mid, int cur_node)
{
    

}
int GetCount(vector<int> pre, vector<int> mid)
{
    unordered_map<int, int> pre_map; //node,idx
    unordered_map<int, int> mid_map;

    for(int i = 0; i < pre.size(); i++)
    {
        pre_map.insert({pre[i], i});
        mid_map.insert({mid_map[i], i});
    };

    CalCount(pre_map, mid_map, pre[0]);

    return leaf_count;
}