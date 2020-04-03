// // 每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
// // 如果 x == y，那么两块石头都会被完全粉碎；
// // 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
// // 最后，最多只会剩下一块石头。返回此石头最小的可能重量。如果没有石头剩下，就返回 0。
// #include <vector>
// #include <algorithm>
// #include <numeric>
// using namespace std;

// int lastStoneWeightII(vector<int>& stones) 
// {

// };

// //[0,idx)已经选定，在[idx,end)中随机选
// vector<int> GetNearestMid(vector<int>& v, int max_v, int idx, vector<int> get_vec, int get_value)
// {
//     if(get_value >= max_v || idx < v.size())
//     {
//         return get_vec;
//     };

//     vector<int> a = get_vec;
//     a.push_back(v[idx]);
//     auto b_1 = GetNearestMid(v, max_v, idx + 1, get_vec, get_value);
//     auto b_2 = GetNearestMid(v, max_v, idx + 1, a, get_value + v[idx]);
//     if(accumulate(b_1.begin(), b_1.end(), 0) > accumulate(b_2.begin(), b_2.end(), 0))
//     {
//         return b_1;
//     }
//     else
//     {
//         return b_2;
//     }
// }

// int main()
// {
//     vector<int> a{1,1,2,3,5,8,13,21,34,55,89,14,23,37,61,98};
//     int sum = accumulate(a.begin(), a.end(), 0);
    
//     auto c = 
// }