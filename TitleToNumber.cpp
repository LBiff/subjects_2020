//HUAWEI
//给定一个Excel表格中的列名称，返回其相应的列序号。
//  A -> 1
//  B -> 2
//  C -> 3
//  ...
//  Z -> 26
//  AA -> 27
//  AB -> 28 
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

int titleToNumber(string s) 
{
    int ret = 0;
    int tmp = 0;
    for(int i = s.length() - 1; i >= 0; i--)
    {
        ret += pow(26, tmp++) * (s[i] - 'A' + 1);
    };

    return ret;
}