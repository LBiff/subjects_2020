//验证二叉树
// 二叉树上有 n 个节点，按从 0 到 n - 1 编号，其中节点 i 的两个子节点分别是 leftChild[i] 和 rightChild[i]。
// 只有 所有 节点能够形成且 只 形成 一颗 有效的二叉树时，返回 true；否则返回 false。
// 如果节点 i 没有左子节点，那么 leftChild[i] 就等于 -1。右子节点也符合该规则。
// 注意：节点没有值，本问题中仅仅使用节点编号。
//https://leetcode-cn.com/problems/validate-binary-tree-nodes/

#include <vector>
#include <unordered_set>
#include <stack>
using namespace std;

bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
{
    //根据入度信息判断入度
    vector<int> in_degree(n,0); //每个节点的入度
    for(auto l : leftChild)
    {
        if(l != -1)
        {
            in_degree[l] += 1;
        }
    };
    for(auto r : rightChild)
    {
        if(r != -1)
        {
            in_degree[r] += 1;
        }
    };

    //根据入度信息查找root节点，查找到一个即可，
    //将存在多root必然不是有效的判断下沉到遍历判断有环或者不连通中，因为都需要遍历
    int root = -1;
    for(int i = 0; i < in_degree.size(); i++)
    {
        if(in_degree[i] == 0)
        {
            root = i;
            break;
        }
    };

    //不存在root节点
    if(root == -1)
    {
        return false;
    };

    //从根节点进行深搜
    stack<int> stk;
    unordered_set<int> set;

    stk.push(root);
    set.insert(root);
    while(!stk.empty())
    {
        int top = stk.top();
        stk.pop();
        int l_c = leftChild[top];
        int r_c = rightChild[top];
        if(l_c != -1)
        {
            //能找到说明存在环
            if(set.find(l_c) != set.end())
            {
                return false;
            }
            stk.push(l_c);
            set.insert(l_c);
        };
        if(r_c != -1)
        {
            //说明存在环
            if(set.find(r_c) != set.end())
            {
                return false;
            }
            stk.push(r_c);
            set.insert(r_c);
        }
    };

    //说明不全部连通
    if(set.size() < n)
    {
        return false;
    }
    else
    {
        return true;
    }
};

int main()
{
    vector<int> v1{1,-1,3,-1};
    vector<int> v2{2,-1,-1,-1};
    auto ret = validateBinaryTreeNodes(4,v1,v2);
    return 0;
}