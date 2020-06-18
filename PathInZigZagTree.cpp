// 二叉树寻路
// 在一棵无限的二叉树上，每个节点都有两个子节点，树中的节点 逐行 依次按 “之” 字形进行标记。
// 如下图所示，在奇数行（即，第一行、第三行、第五行……）中，按从左到右的顺序进行标记；
// 而偶数行（即，第二行、第四行、第六行……）中，按从右到左的顺序进行标记。
// 给你树上某一个节点的标号 label，请你返回从根节点到该标号为 label 节点的路径，
// 该路径是由途经的节点标号所组成的。
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

vector<int> pathInZigZagTree(int label) 
{
    //label层数，从0计数
    int label_level = floor(log2(label));
    //计算正常映射
    auto CalNormalLevel = [](const int level, const int cur_idx)
    {
        //偶数层判断
        bool is_even_level = ((level & 1) == 0);
        if (is_even_level) //偶数层正常标记
        {
            return cur_idx;
        }
        int level_l = pow(2, level);
        int level_r = 2 * level_l - 1;
        return level_l + (level_r - cur_idx);
    };
    //计算正常的倒序映射
    stack<int> reverse_stk;
    int cur_node = CalNormalLevel(label_level, label);

    while(cur_node > 0)
    {
        reverse_stk.push(cur_node);
        cur_node /= 2; //查找父节点
    };

    //倒序计算规则映射
    vector<int> ret;
    int cur_level = 0;
    while(!reverse_stk.empty())
    {
        int top = reverse_stk.top();
        reverse_stk.pop();
        ret.push_back(CalNormalLevel(cur_level++,top));
    };

    return ret;
};

int main()
{
    auto ret = pathInZigZagTree(14);
    return 0;
}


