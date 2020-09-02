// 米字型划分8个区域，各区域填充区域号打印矩阵
#include <iostream>
using namespace std;

int CalIdx(int x, int y, int n)
{
    double x_new = x + 0.5;
    double y_new = y + 0.5;
    
    double b1_d = x_new + y_new - n;
    double b2_d = y_new - x_new;
    double b3_d = n - 2 * x_new;
    double b4_d = n - 2 * y_new;
    if(b1_d == 0|| b2_d==0 || b3_d == 0 || b4_d == 0)
    {
        return 0;
    }
    // 在/线的左上
    bool b1 = b1_d < 0;
    //在\线的右上
    bool b2 = b2_d > 0;
    //在-线上
    bool b3 = b3_d > 0;
    //在线|左边
    bool b4 = b4_d > 0;

    //1区
    if(b1 && !b4)
    {
        return 1;
    };
    // 2
    if(b4 && b2)
    {
        return 2;
    };
    // 3
    if(!b2 && b3)
    {
        return 3;
    };
    // 4
    if(!b3 && b1)
    {
        return 4;
    };
    // 5
    if(!b1 && b4)
    {
        return 5;
    };
    // 6
    if(!b4 && !b2)
    {
        return 6;
    };
    // 7
    if(b2 && !b3)
    {
        return 7;
    };
    if(b3 && !b1)
    {
        return 8;
    };

    return -1;
};

int main()
{
    int n; 
    cin >> n;
    if(n < 1)
    {
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        cout << CalIdx(i, 0, n);
        for(int j = 1; j < n; j++)
        {
            cout << " " << CalIdx(i, j, n);
        };
        cout << endl;
    };

    return 0;
}