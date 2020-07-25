//黑白图的抠图功能
//输入二维的01矩阵，对于一个像素只有上下左右相等才会消除，给定魔术棒的点击点

#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

struct Point
{
    int _x;
    int _y;
};

void GetParas(vector<Point>& vp, Point& click_p)
{
    //获取行数和列数
    string s;
    getline(cin,s);
    size_t spilt_1 = s.find_first_of(",");
    int row_count = s.substr(0, spilt_1);

}