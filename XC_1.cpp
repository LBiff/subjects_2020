
// 游游今年就要毕业了，和同学们在携程上定制了日本毕业旅行。愉快的一天行程结束后大家回到了酒店房间，这时候同学们都很口渴，石头剪刀布选出游游去楼下的自动贩卖机给大家买可乐。
// 贩卖机只支持硬币支付，且收退都只支持10 ，50，100 三种面额。一次购买行为只能出一瓶可乐，且每次购买后总是找零最小枚数的硬币。（例如投入100圆，可乐30圆，则找零50圆一枚，10圆两枚）
// 游游需要购买的可乐数量是 m，其中手头拥有的 10,50,100 面额硬币的枚数分别是 a,b,c，可乐的价格是x(x是10的倍数)。
// 如果游游优先使用大面额购买且钱是够的情况下,请计算出需要投入硬币次数？
// 输入描述
// 依次输入，
// 需要可乐的数量为 m
// 10元的张数为 a
// 50元的张数为 b
// 100元的张树为 c
// 1瓶可乐的价格为 x

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/

//用这几个买的时候找的钱数
vector<int> CalZQ(int a, int b, int c, int v)
{
    vector<int> ret_v(3,0);
    //还剩的钱
    int ret = a * 100 + b * 50 + 10 * c - v;

    while(ret > 0 && ret >= 100)
    {
        ret_v[2]++;
        ret -= 100;
    };
    while(ret > 0 && ret >= 50)
    {
        ret_v[1]++;
        ret -= 50;
    };
    while(ret > 0 && ret >= 10)
    {
        ret_v[0]++;
        ret -= 10;
    };
    return ret_v;
};

//计算买一次投入硬币次数
int count(int& a, int& b, int& c, int cur_v)
{
    int ret = 0;
    int h_a = 0;
    int h_b = 0;
    int h_c = 0;
    int cur_v_bak = cur_v;

    while(cur_v_bak > 0 && c > 0 && cur_v_bak >= 100)
    {
        h_c++;
        ret++;
        c--;
        cur_v_bak-= 100;
    };
    while(cur_v_bak > 0 && b > 0 && cur_v_bak >= 50)
    {
        h_b++;
        ret++;
        b--;
        cur_v_bak-= 50;
    };
    while(cur_v_bak > 0 && a > 0 && cur_v_bak >= 10)
    {
        h_c++;
        ret++;
        a--;
        cur_v_bak-= 10;
    };

    auto fanhuan = CalZQ(h_a, h_b,h_c,cur_v);
    a += fanhuan[0];
    b += fanhuan[1];
    c += fanhuan[2];

    return ret;
};


int buyCoke(int m, int a, int b, int c, int x) {

    int ret = 0;
    while(m-- > 0)
    {
        ret += count(a,b,c,x);
    };

    return ret;
}
/******************************结束写代码******************************/

int main()
{
    auto ret = buyCoke(2,1,4,3,250);
    return 0;

}
int main_2() {
    int res;

    int _m;
    cin >> _m;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _a;
    cin >> _a;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _b;
    cin >> _b;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _c;
    cin >> _c;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _x;
    cin >> _x;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    
    res = buyCoke(_m, _a, _b, _c, _x);
    cout << res << endl;
    
    return 0;

}
