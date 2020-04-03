//打印折纸折痕上下顺序
//最终形成二叉树，顺序是二叉树的中序遍历，中序遍历就是从左到右的遍历

#include <iostream>
using namespace std;

//不实际建立二叉树，用bool标记

//正在打印第几层，总共几层，当前节点是否是下
void PrintNode(uint64_t level_i, uint64_t level_num, bool is_down)
{
    if(level_i > level_num)
    {
        return;
    };

    PrintNode(level_i + 1, level_num, true);
    cout << (is_down ? "Down" : "Up") << endl;
    PrintNode(level_i+1, level_num, false);
}
int main()
{
    PrintNode(0, 2,true);
    return 0;
}