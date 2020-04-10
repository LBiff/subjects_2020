//【字节】万万没想到之抓捕孔连顺
// 我叫王大锤，是一名特工。我刚刚接到任务：在字节跳动大街进行埋伏，抓捕恐怖分子孔连顺。
// 和我一起行动的还有另外两名特工，我提议
// 1. 我们在字节跳动大街的N个建筑中选定3个埋伏地点。
// 2. 为了相互照应，我们决定相距最远的两名特工间的距离不超过D。

// 请听题：给定N（可选作为埋伏点的建筑物数）、D（相距最远的两名特工间的距离的最大值）以及可选建筑的坐标，计算在这次行动中，大锤的小队有多少种埋伏选择。
// 注意：
// 1. 两个特工不能埋伏在同一地点
// 2. 三个特工是等价的：即同样的位置组合(A, B, C) 只算一种埋伏方法，不能因“特工之间互换位置”而重复使用

// 输入描述:
// 第一行包含空格分隔的两个数字 N和D(1 ≤ N ≤ 1000000; 1 ≤ D ≤ 1000000)
// 第二行包含N个建筑物的的位置，每个位置用一个整数（取值区间为[0, 1000000]）表示，从小到大排列（将字节跳动大街看做一条数轴）
// 输出描述:
// 一个数字，表示不同埋伏方案的数量。结果可能溢出，请对 99997867 取模

//问题抽象为 在有序数组中查找三个数，最大差值小于等于D
//假设 A_B_C排序，则只要A_C距离<=D即可
//双指针，B在其中任意点即可

#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

//Error
int Arrest(const vector<int>& coords, int D)
{
    if(coords.size() < 3)
    {
        return 0;
    };

    int a_idx = 0;
    int c_idx = 2;
    int total = 0;
    while(1)
    {
        if(c_idx == coords.size() - 1) //边界条件
        {
            while(a_idx < coords.size() - 2)
            {
                if(coords[c_idx] - coords[a_idx] <= D)
                {
                    total += c_idx - a_idx - 1;
                };
                a_idx++;
            };
            break;
        };

        if(coords[c_idx] - coords[a_idx] < D) //弹簧还松就拉紧
        {
            total += c_idx - a_idx - 1;
            c_idx++;
        }
        else if(coords[c_idx] - coords[a_idx] > D) //拉的太紧就松
        {
            a_idx++;
        }
        else //相等弹簧收缩
        {
            while(a_idx < c_idx - 1)
            {
                total += c_idx - a_idx - 1;
                a_idx++;
            };
        }
    };

    return total;
};

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
int main()
{
    int D = GetIntVByLineBySpace()[1];
    vector<int> v = GetIntVByLineBySpace();
    cout << Arrest(v,D) << endl;
    return 0;
}


