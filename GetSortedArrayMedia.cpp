//两个有序数组的中位数

#include <vector>
#include <algorithm>
using namespace std;

// class Solution 
// {
//  //在v_1和v_2中查找第k小的数  start_1是开始位置，包含
// //v1_idx查询结束时下一步要查询的索引
// int FindKth(const vector<int>& v1,const vector<int>& v2, const int& k, int& v1_idx, int& v2_idx)
// {
//     if(v1.empty())
//     {
//         v1_idx = -1;
//         v2_idx = k;
//         return v2[k - 1];
//     }
//     else if(v2.empty())
//     {
//         v1_idx = k;
//         v2_idx = -1;
//         return v1[k - 1];
//     }

//     int start_1 = 0; // []
//     int start_2 = 0;
//     int end_1 = 0;
//     int end_2 = 0;
//     int del_count = 0;

//     int v1_go = k / 2;  //v1前进考察数
//     int v2_go = k / 2;
//     while(del_count < k - 1)
//     {
//         //有一个不用考察
//         if(v1_go == 0) //不用考察,直接考察v2
//         {
//             v1_idx = -1;
//             v2_idx = start_2 + k - del_count;
//             return v2[start_2 + k - del_count - 1];
//         };
//         if(v2_go == 0) //不用考察,直接考察v1
//         {
//             v2_idx = -1;
//             v1_idx = start_1 + k - del_count;
//             return v1[start_1 + k - del_count - 1];
//         };

//         //两个都有考察位置，但不一定满足考察要求
//         //理论考察位置
//         end_1 = start_1 + v1_go - 1;
//         end_2 = start_2 + v2_go - 1;

//         //待考察数不足
//         if(end_1 > v1.size() - 1)
//         {
//             end_1 = v1.size() - 1;  //到边界

//             if(v1[end_1] < v2[end_2])
//             {
//                 del_count += end_1 - start_1 + 1;
//                 v1_go = 0;  //表示直接从v2考察
//             }
//             else
//             {
//                 start_2 = end_2 + 1;
//                 del_count += v2_go;
//                 v1_go = (k - del_count) / 2;
//                 v2_go = (k - del_count) / 2;
//             }
//             continue;
//         }
//         else if(end_2 > v2.size() - 1)   //v2待考察数不足
//         {
//              end_2 = v2.size() - 1;  //到边界

//             if(v1[end_1] > v2[end_2])
//             {
//                 del_count += end_2 - start_2 + 1;
//                 v2_go = 0;  //表示直接从v1考察
//             }
//             else
//             {
//                 start_1 = end_1 + 1;
//                 del_count += v1_go;
//                 v1_go = (k - del_count) / 2;
//                 v2_go = (k - del_count) / 2;
//             }
//             continue;
//         }
//         else  //考察数都满足
//         {
//             if(v1[end_1] > v2[end_2])
//             {
//                 start_2 = end_2 + 1;
//                 del_count += v2_go;
//             }
//             else
//             {
//                 start_1 = end_1 + 1;
//                 del_count += v1_go;
//             };
//             v1_go = (k - del_count) / 2;
//             v2_go = (k - del_count) / 2;
//         }
//     };
    
//     if(start_1 >= v1.size())
//     {
//         v1_idx = -1;
//         v2_idx = start_2 + 1;
//         return v2[start_2];
//     }
//     else if(start_2 >= v2.size())
//     {
//         v1_idx = start_1 + 1;
//         v2_idx = -1;
//         return v1[start_1];
//     }
//     else
//     {
//         bool ret_1 = v1[start_1] < v2[start_2];
//         v1_idx = ret_1 ? start_1 + 1 : start_1;
//         v2_idx = ret_1 ? start_2 : start_2 + 1;
//        return ret_1 ? v1[start_1] : v2[start_2];
//     }
// };


// //二分查找
// //奇偶分情况的处理： n长数组通用 ((n+1)/2 + (n + 2)/2)/2
// // nums1是 n个数， num2是m个数
// //转换为寻找第(n+1)/2小的数 和 (n + 2)/2小的数
// double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
// {
//     int totaol_size = nums1.size() + nums2.size();
//     int v1_idx = -1;
//     int v2_idx = -1;
//     if(totaol_size % 2 == 1)  //奇数
//     {
//         return FindKth(nums1,nums2,(totaol_size+ 1) / 2, v1_idx, v2_idx);
//     }
//     else
//     {
//         int ret_1 =  FindKth(nums1,nums2,( totaol_size+ 1) / 2, v1_idx, v2_idx); //(n+1)/2
//         int ret_2 = 0;
//         if(v1_idx == -1)
//         {
//             ret_2 = nums2[v2_idx];
//         }
//         else if(v2_idx == -1)
//         {
//             ret_2 = nums1[v1_idx];
//         }
//         else
//         {
//             if(v1_idx > nums1.size() - 1)
//             {
//                 ret_2 =  nums2[v2_idx];
//             }
//             else if(v2_idx > nums2.size() - 1)
//             {
//                 ret_2 = nums1[v1_idx];
//             }
//             else
//             {
//                ret_2 = min(nums2[v2_idx], nums1[v1_idx]);
//             }
//         }
//         return (ret_1 +ret_2)/2.0;
//     }
// };
// };


//转换为寻找v1和v2中第n/2小的数
//13_26
class Solution_2 
{
public:
    double findMedianSortedArrays(vector<int>& v_1, vector<int>& v_2) 
    {
        
    }

    //返回第k+1和k+2个数
    bool FindK_1_2thLess(vector<int>& v_1, vector<int>& v_2, int k, int& k_1, int& k_2)
    {
        
        //特殊处理
        if (k > v_1.size() + v_2.size() - 2)
        {
            return false;
        };
        //淘汰制查询[]
        int start_1 = 0;  //下一个要考察的字符串
        int start_2 = 0;

        int end_1 = (k / 2) > (v_1.size() - 1) ? (v_1.size() - 1) : k / 2 ; //待考察
        int end_2 = (k / 2) > (v_2.size() - 1) ? (v_2.size() - 1) : k / 2 ;

        int del_count = 0;
        while(del_count < k)
        {
            end_2 = (k - del_count) / 2 + start_2;
            end_1 = (k - del_count) / 2 + start_1;
            if(end_1 > v_1.size() - 1)
            {
                k_1 = v_2[start_2 + k - del_count - 1];
                k_2 = v_2[start_2 + k - del_count];
                return true;
            }
            if(end_2 > v_2.size() - 1)
            {
                k_1 = v_1[start_1 + k - del_count - 1];
                k_2 = v_1[start_1 + k - del_count];
                return true;
            };

            if(v_1[end_1] >= v_2[end_2])
            {
                del_count += end_2 - start_2;
                start_2 = end_2;
               
            }
            else
            {
                del_count += end_1 - start_1;
                start_1 = end_1;
            };
        };
        if(end_1 > v_1.size() - 1)
        {
            k_1 = v_2[start_2];
            k_2 = v_2[start_2 + 1];
            return true;
        }
        if(end_2 > v_2.size() - 1)
        {
            k_1 = v_1[start_1]; 
            k_2 = v_1[start_1 +1];
            return true;
        };
        return true;
    }


};

// int main()
// {
//     Solution_2 s;
//     vector<int> a{1,2,4,6,8};
//     vector<int> b{1,3,4,7,9};
//     int k_1 = 0;
//     int k_2 = 0;;
//     s.FindK_1_2thLess(a,b,3,k_1, k_2);
//     return 0;
// };


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{

    //偶数删除前中位的前所有，奇数删除中位前
    int need_del = (nums1.size() + nums2.size()) % 2 == 0 ?
                    (nums1.size() + nums2.size()) / 2 - 1 : (nums1.size() + nums2.size()) / 2;
    int del = 0;
    int l_1 = 0;
    int r_1 = nums1.size() - 1;
    int l_2 = 0;
    int r_2 = nums2.size() - 1 ;
    while(r_1 < nums1.size() && r_2 < nums2.size() && del < need_del)
    {
        int mid_1 = l_1 + (r_1 - l_1) / 2;
        int mid_2 = l_2 +(r_2 - l_2) / 2;
        if(nums1[mid_1] < nums2[mid_2]) //删除1区间前半部分
        {
            int del_tmp = del;
            del_tmp += mid_1 - l_1 + 1;
            if(del_tmp > need_del) //可能会删过
            {
                break;
            };
            del = del_tmp;
            l_1 = mid_1 + 1;
        }
        else if(nums1[mid_1] > nums2[mid_2])
        {
            int del_tmp = del;
            del_tmp += mid_2 - l_2 + 1;
            if(del_tmp > need_del) //可能会删过
            {
                break;
            };
            del = del_tmp;
            l_2 = mid_2 + 1;
        }
        else //两个都可以删了
        {
            int del_tmp = del;
            del_tmp += mid_1 - l_1 + 1;
            del_tmp += mid_2 - l_2 + 1;
            if(del_tmp > need_del) //可能会删过
            {
                break;
            };
            del = del_tmp;
            l_1 = mid_1 + 1;
            l_2 = mid_2 + 1;
        }
    };

    return 0;
};

int main()
{
    vector<int>nums1{1, 3,4,6,7};
    vector<int>nums2{2,4,5,6};
    auto ret = findMedianSortedArrays(nums1,nums2);
    return 0;

}

