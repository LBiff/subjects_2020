//24点。给定数，通过+-*/算出24能否

#include <vector>
using namespace std;

bool isGet(vector<double> v, double get_v)
{
    if(v.empty())
    {
        return get_v == 24;
    };
    for(int i = 0; i < v.size(); i++)
    {
        vector<double> v_bak(v);
        v_bak.erase(v_bak.begin() + i);
        if(isGet(v_bak, get_v + v[i])
        || isGet(v_bak, get_v - v[i])
        || isGet(v_bak, get_v * v[i])
        || isGet(v_bak, get_v / v[i]))
        {
            return true;
        }
    };
    return false;
};

bool Game24Points(int* arr, int arrLen) {
    if(arrLen < 4)
    {
        return false;
    }
    vector<double> v;
    for(int i = 0; i < arrLen; i++)
    {
        v.push_back(arr[i]);
    }
    
    return isGet(v, 0);
}