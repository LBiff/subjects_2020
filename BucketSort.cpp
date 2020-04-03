//桶排序
//求解数组数值范围，全范围内准备桶，遍历对应进桶，桶可只计数,按次序出桶
//时间O(N),空间O(N)

#include<vector>
#include <cmath>
#include <tuple>
#include <algorithm>
using namespace std;

void BucketSort(vector<int>& vec)
{
    if(vec.size() < 2)
    {
        return;
    }
    //求解范围
    int vec_max = vec[0];
    int vec_min = vec[0];

    for(int i =1; i<vec.size();i++)
    {
        if(vec[i] > vec_max)
        {
            vec_max = vec[i];
        }
        else if(vec[i] < vec_min)
        {
            vec_min = vec[i];
        }
    };

    //准备桶
    int bucket_count = vec_max - vec_min + 1;
    vector<int> buckets; //索引0开始
    buckets.assign(bucket_count,0); //预先分配
    //入桶统计
    int idx = 0;
    for (int j = 0; j < vec.size(); j++)
    {
        idx = vec[j] - vec_min;
        buckets[idx]++;
    };

    //出桶
    int vec_idx = 0;
    for (int k = 0; k < buckets.size(); k++)
    {
        int bucket_k_count = buckets[k];
        while((bucket_k_count--) > 0)
        {
            vec[vec_idx++] = k + vec_min;
        }
    }
};


//最大间隔问题：无序数组，返回排序后相邻两数的最大差值， 数值范围很大，要求O(N)
int MaxGap(const vector<int>& vec)
{
    if(vec.size() < 2)
    {
        return 0;
    }
    //求解范围
    int vec_max = vec[0];
    int vec_min = vec[0];

    for(int i =1; i<vec.size();i++)
    {
        if(vec[i] > vec_max)
        {
            vec_max = vec[i];
        }
        else if(vec[i] < vec_min)
        {
            vec_min = vec[i];
        }
    };

    //N个数准备N+1个桶，其中必然存在空桶，此举在于排除最大差值在同一个桶内,确保最大值在两个桶内
    int bucket_count = vec.size() + 1;
    vector<std::tuple<bool, int,int>> buckets; //是否存值，max,min
    
    buckets.assign(bucket_count, {false, INT32_MIN,INT32_MAX});
    //入桶2-65 0-63 14
    int bid = 0;
    for (int j = 0; j < vec.size(); j++)
    {
        //              重要
        /****************************************/
        bid = static_cast<int>(((double)vec[j] - (double)vec_min) / (((double)vec_max - (double)vec_min) / (double)bucket_count));
        if(bid == bucket_count)
        {
            bid--;
        } 
        /*****************************************/
        std::get<0>(buckets[bid]) = true;
        if(vec[j] > std::get<1>(buckets[bid]))
        {
            std::get<1>(buckets[bid]) = vec[j];
        }
        if(vec[j] < std::get<2>(buckets[bid]))
        {
           std::get<2>(buckets[bid]) = vec[j];
        }
    };

    int largest = INT32_MIN;
    int last_max = std::get<1>(buckets[0]);
    //桶遍历,,第一个和最后一个桶肯定有值
    for (int k = 1; k < buckets.size(); k++)
    {
        if(std::get<0>(buckets[k])) 
        {
            largest = largest < (std::get<2>(buckets[k]) - last_max) ? 
                      std::get<2>(buckets[k]) - last_max : largest;
            last_max = std::get<1>(buckets[k]);
        }
    };

    return largest;
};

int GetMaxGap(vector<int> a)
{
   std::sort(a.begin(), a.end());
   int max = INT32_MIN;
   for (int i = 1; i < a.size(); i++)
   {
       if((a[i] - a[i-1]) > max)
       {
           max = a[i] - a[i-1];
       }
   };
   return max;
}


int main()
{
    vector<int> a{64,2,32,45,211,52,15,2,12,1,2,1,5,2,335,2,15,2,5};

    int b= MaxGap(a);
    int c = GetMaxGap(a);
    return 0;
}
