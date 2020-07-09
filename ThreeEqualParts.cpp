// 三等分
// 给定一个由 0 和 1 组成的数组 A，将数组分成 3 个非空的部分，使得所有这些部分表示相同的二进制值。
// 如果可以做到，请返回任何 [i, j]，其中 i+1 < j，这样一来：
// A[0], A[1], ..., A[i] 组成第一部分；
// A[i+1], A[i+2], ..., A[j-1] 作为第二部分；
// A[j], A[j+1], ..., A[A.length - 1] 是第三部分。
// 这三个部分所表示的二进制值相等。
// 如果无法做到，就返回 [-1, -1]。

//算法：如果两个二进制相等，则总1数相等，在不考虑多余前缀的情况下1的位置相等
#include <vector>
#include <map>
using namespace std;


vector<int> threeEqualParts(vector<int>& A) 
{
    //计数1的个数
    int one_count = 0;
    map<int,int> mp; //count, idx
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] == 1)
        {
            one_count++;
            mp.insert({one_count, i});
        }
    };
    //1的个数肯定是3的倍数
    if(one_count % 3 != 0)
    {   
        return {-1,-1};
    };
    if(one_count == 0)
    {
        return {0, static_cast<int>(A.size()) - 1};
    };
    int t = one_count / 3;
    //计算最后1后面的0的个数
    int last_count = A.size() - mp[one_count] - 1;
    //理论上
    int i_idx = mp[t] + last_count;
    int j_idx = mp[2 * t] + last_count;

    //校验
    if(2 * t + 1 < A.size() - 1 && i_idx < mp[t + 1] && j_idx < mp[2 * t + 1])
    {
        //区间校验
        int one_idx = t;
        int two_idx = 2 * t;
        int three_idx = one_count;
        for(int i = t; i > 1; i--)
        {
            int diff_1 = mp[one_idx] - mp[one_idx - 1];
            int diff_2 = mp[two_idx] - mp[two_idx - 1];
            int diff_3 = mp[three_idx] - mp[three_idx - 1];
            if(diff_1 != diff_2 || diff_2 != diff_3)
            {
                return {-1,-1};
            }
        };
        return {i_idx,j_idx + 1};
    }
    else
    {
        return {-1,-1};
    }
};

int main() 
{
    vector<int> v{1,0,1,1,0};
    auto ret = threeEqualParts(v);
    return 0;
}
