//汉诺塔问题: 将n个盘子借助help杆从from杆移动到to杆，不违反小压大的原则，求解最短步骤

#include <iostream>
using namespace std;

//将1-n个盘子从from移动到to借助help
void HaNoI(int n, string from, string to, string help)
{
    if(n == 1)
    {
        cout<< 1 << ": " << from << " => " << to << endl; 
        return;  
    }
    else
    {
        HaNoI(n-1, from, help, to);
        cout<< n << ": " << from << " => " << to << endl;
        HaNoI(n - 1,help, to, from); 
    }
};

int main()
{
    HaNoI(3, "from", "to", "mid");
    return 0;
}