// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，
// 并返回他们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
#include <vector>
#include <algorithm>
using namespace std;

//Thinking
struct Node
{
    Node(int v, int idx) : _v(v), _idx(idx){};
    int _v;
    int _idx;
};

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<Node> nv;
        for(int i =0; i< nums.size(); i++)
        {
            nv.push_back(Node(nums[i], i));
        };

        sort(nv.begin(), nv.end(), [&](const Node& n1, const Node& n2)
        {
            return n1._v < n2._v;
        });
        int l = 0;
        int r = nv.size() - 1;
        while(l < r)
        {
            int sum = nv[l]._v + nv[r]._v;
            if(sum == target)
            {
                return {nv[l]._idx, nv[r]._idx};
            }
            else if(sum < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        };
        return vector<int>();
    }
};