#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


unsigned long long ret = 0;
// 当前到达cur_idx台阶, pre_1_step表示上一步跨的步数，pre_2_step表示上上一步的步数
void GetMAx(unsigned long long cur_idx, unsigned long long max_step, unsigned long long tj_count, unsigned long long pre_1_step, unsigned long long pre_2_step)
{
    if(cur_idx > tj_count)
    {
        return;
    }
    if(cur_idx == tj_count)
    {
        ret++;
        ret %= (int)(pow(10, 9) + 7);
        return;
    };
    for(unsigned long long i = 1; i <= max_step; i++)
    {
        if(i != pre_1_step && i != pre_2_step)
        {
            GetMAx(cur_idx + i, max_step, tj_count, i, pre_1_step);
        }
    }
};


int main()
{
    int tj_count;
    int max_step;
    cin >> tj_count >> max_step;
    if(max_step < 1 || tj_count < 1)
    {
        cout << 0 << endl;
        return 0;
    }
    if(tj_count == 1)
    {
       cout << 1 << endl;
       return 0;
    }
    else if(tj_count == 2)
    {
        if(max_step == 1)
        {
            cout << 1 << endl;
            return 0;
        }
        cout << 2 << endl;
        return 0;
    }

    if(max_step > 1)
    {
        GetMAx(2,max_step, tj_count, 1, 1);
        GetMAx(2,max_step, tj_count, 2, 0);
    }
    else
    {
        GetMAx(2,max_step, tj_count, 1, 1);
    }
    cout << ret << endl;
    return 0;
}