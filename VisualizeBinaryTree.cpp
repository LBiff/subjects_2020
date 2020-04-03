//二叉树的可视化
#include <string>
#include <stdexcept>
#include <iostream>
#include "BTNode.h"
using namespace std;

//左右补falg,左右补空格，总长度为17
string GetSeventeenStr(const int ori_v, const string flag, int total_len)
{
    if(flag.length() != 1)
    {
        throw invalid_argument("The length of flag must be one.");
    };
    string s = to_string(ori_v);
    s = flag + s;
    s += flag;
    int len = s.length();
    int l_len = (total_len - len) / 2;
    int r_len = total_len - l_len;
    for(int l = 0; l < l_len; l++)
    {
        s = " " + s;
    };
    for(int r = 0; r < r_len; r++)
    {
        s += " ";
    };
    return s;
};
//右-中-左打印
void PrintInorder(const Node* head, string flag, int height, int total_len)
{
    if(!head)
    {
        return;
    };
    PrintInorder(head->_r, "v", height + 1, total_len);
    string s = GetSeventeenStr(head->_v,flag, total_len);
    //先打印高度的空格
    for(int i =0; i< height*total_len; i++)
    {
        cout << " ";
    };
    cout << s << endl;
    PrintInorder(head->_l, "^", height + 1,total_len);
};


void PrintTree(const Node* head)
{
    if(!head)
    {
        return;
    };

    PrintInorder(head,"H",0, 5);
};



// int main()
// {
//     Node n1(1);
//     Node n2(2);
//     Node n3(3);
//     Node n4(4);
//     Node n5(5);
//     Node n6(6);
//     Node n7(7);
//     n1._l = &n2;
//     n1._r = &n3;
//     n2._l = &n4;
//     n2._r = nullptr;
//     n3._l = &n5;
//     n3._r = &n6;
//     n4._l = nullptr;
//     n4._r = &n7;
//     n5._l = nullptr;
//     n5._r = nullptr;
//     n6._l = nullptr;
//     n6._r = nullptr;
//     n7._l = nullptr;
//     n7._r = nullptr;

//     PrintTree(&n1);
//     return 0;
// }