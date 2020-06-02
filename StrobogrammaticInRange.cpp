//中心对称数
//中心对称数是指一个数字在旋转了 180 度之后看起来依旧相同的数字（或者上下颠倒地看）。
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

//中心对称数I
//判断一个数是不是中心对称数
//0,1,6,8,9可以翻转
bool isStrobogrammatic(string num) 
{
    int idx = 0;
    string tmp;
    unordered_map<char,char> map;
    map.insert({'0','0'});
    map.insert({'1','1'});
    map.insert({'6','9'});
    map.insert({'8','8'});
    map.insert({'9','6'});
    while(idx < num.size())
    {
        auto c = num[idx];
        if(c != '0' && c != '1' && c != '6' && c != '8' && c != '9') 
        {
            return false;
        };
        tmp = map.find(c)->second + tmp;
        idx++;
    };
    return tmp == num;
};

//中心对称数II
// 中心对称数是指一个数字在旋转了 180 度之后看起来依旧相同的数字（或者上下颠倒地看）。
// 找到所有长度为 n 的中心对称数
vector<string> findStrobogrammatic(int n) 
{
    vector<string> ret;
    if(n % 2) //奇数
    {
        //插入中间数
        ret.push_back("0");
        ret.push_back("8");
        ret.push_back("1");
    }
    else
    {
        ret.push_back("");
    }
    
    int len = n % 2 ? 1 : 0;
    //两边放对称
    while(len < n)
    {
        int size = ret.size();
        for(int i = 0; i < size; i++)
        {
            if(len < n - 2)
            {
                ret.push_back("0" + ret[i] + "0");
            };

            ret.push_back("6" + ret[i] + "9");
            ret.push_back("8" + ret[i] + "8");
            ret.push_back("9" + ret[i] + "6");

             //自身扩展
             //warning: 自身扩展需要放在最后，以免影响其他的扩展取值
            ret[i] = "1" + ret[i] + "1";
        };
        len += 2;
    };
    return ret;
}

//中心对称数III
// 写一个函数来计算范围在 [low, high] 之间中心对称数的个数。
//待实现
int strobogrammaticInRange(string low, string high) 
{
    //先计算两个位数之间的个数
    int l_bits = low.size();
    int h_bits = high.size();

};

int main()
{
    auto v = findStrobogrammatic(2);
    return 0;
}