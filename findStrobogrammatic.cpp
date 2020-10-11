// 中心对称数是指一个数字在旋转了 180 度之后看起来依旧相同的数字（或者上下颠倒地看）。
// 找到所有长度为 n 的中心对称数。
#include <vector>
#include <string>
using namespace std;

//thinking
vector<string> findStrobogrammatic(int n) 
{
    vector<string> ret;
    vector<pair<char,char>> Strobogrammatic_chars{{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}};
    vector<char> vc{'0','1','8'};
    if(n & 1 == 1) //奇数
    {
        if(n == 1)
        {
            return {"1","0"};
        };
        int mid_idx = n / 2; //对称轴
        for(int i = 0; i < vc.size(); i++)
        {
            string tmp;
            tmp.resize(n);
            tmp[mid_idx] = vc[i];
            //填充对称轴之前的，不包括0位置
            for(int j = 1; j < mid_idx; j++)
            {
                for(int k = 0; k < Strobogrammatic_chars.size(); k++)
                {
                    tmp[j] = Strobogrammatic_chars[k].first;
                    tmp[n - 1 - j] = Strobogrammatic_chars[k].second;
                }
            };
            tmp[0] = '1';
            tmp.back() = '1';
            ret.push_back(tmp);
        }
    }
    else
    {
        for(int i = 1; i <= vc.size() / 2 - 1; i++)
        {
            for(int j = 0; j < Strobogrammatic_chars)
        }
    }
    
}