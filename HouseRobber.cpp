//打家劫舍问题

// 1.
// 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
// 影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
// 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
// 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，
// 能够偷窃到的最高金额。
#include <vector>
using namespace std;

int rob(vector<int>& nums) 
{
    return dp(nums, 0);
};

//dp[i]表示v[i...end]能够抢到的最大数目
//【状态】对于每个房屋有 抢 与 不抢 两种状态
//【转移】 
int dp(const vector<int>& v, int start)
{
    if(start >= v.size())
    {
        return 0;
    };

    return max(dp(v, start + 1), v[start] + dp(v, start + 2));
};

//转dp表
int rob(vector<int>& nums) 
{
    if(nums.empty())
    {
        return 0;
    }
    if(nums.size() == 1)
    {
        return nums[0];
    };

    vector<int> dp(nums.size() + 2, 0);
    for(int i = nums.size() - 1; i >= 0; i--)
    {
        dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
    };

    return dp[0];
};

//2.
// 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。
// 这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。
// 同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
// 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

//三种情况,（第一个和最后一个都不被抢)，（第一个被抢，最后一个不被），（最后一个被，第一个不被）
//且最大值肯定在最后两个

int rob(vector<int>& nums) 
{
    if(nums.size() == 1)
    {
        return nums[0];
    };
    return max(rob(nums,1,nums.size() - 1), //第一个不抢
               rob(nums,0,nums.size() - 2)); //最后一个不抢
};

int rob(const vector<int>& nums, int start, int end) 
{
    if(start > end)
    {
        return 0;
    }
    if(start == end)
    {
        return nums[start];
    };

    int size = end - start + 1;
    vector<int> dp(size + 2, 0);
    
    for(int i = size - 1; i >= 0; i--)
    {
        dp[i] = max(dp[i + 1], nums[start + i] + dp[i + 2]);
    };

    return dp[0];
};

//3. 
// 在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。
// 这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。
// 一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 
// 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
// 计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(nullptr) {}
};

//一个套路
#include <unordered_map>

unordered_map<TreeNode*, int> map;
int rob(TreeNode* root) 
{
    if(!root)
    {
        return 0;
    };
    auto iter = map.find(root);
    if(iter != map.end())
    {
        return iter->second;
    };

    //抢
    int do_it = root -> val + (root->left ? (rob(root->left->left) + rob(root->left->right)) : 0)
                            + (root->right ? (rob(root->right->left) + rob(root->right->right)) : 0);
    //不抢
    int not_do = rob(root->left) + rob(root->right);
    int ret = max(do_it, not_do);
    map.insert({root, ret});
    return ret;
};

//新思路
int rob(TreeNode* root)
{
    pair<int,int> ret = dp_2(root);
    return max(ret.first, ret.second);
};

//返回 first--不抢root, sec--抢root
pair<int,int> dp_2(TreeNode* root)
{
    if(!root)
    {
        return {0,0};
    };
    auto left = dp_2(root->left);
    auto right = dp_2(root->right);
    int do_it = root->val + left.first + right.first; //抢
    int not_do = max(left.first, left.second) + max(right.first, right.second);
    return {not_do, do_it};
}

