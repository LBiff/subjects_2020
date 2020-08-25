//排序算法总结

//冒泡排序----------------------------------------------------------------------
//原理: 每次通过交换选择最大或最小到最后
//时间O(n^2), 最好O(n), 空间复杂度(o(1)

// 在内层循环之前设置一个标记变量，用于标记循环是否进行了交换，在内层循环结束时，
// 若判断没有进行交换，则说明剩下的序列中，每个元素都小于等于后面一个元素，
// 即已经有序，可终止循环。这样，冒泡排序的最好时间复杂度可以提升到O(n)。

//稳定性分析：可实现为稳定的
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

void BubbleSort(vector<int>& v)
{
    int end = v.size() - 1; //需要确定的索引
    for(int i = 0; i <= end; i++)
    {
        for(int j = 0; j < end; j ++)
        {
            if(v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    };
};

//插入排序-----------------------------------------------------------------
//基本思想：每次在排好序的序列中查找合适的位置进行插入
//复杂度分析: 时间O(n^2), 空间O(1)

//最好情况O(n), 已经排好序，内部循环不需要

//稳定性分析:可以实现为稳定的，在相等的时候不交换即可
void InsertSort(vector<int>& v)
{
    for(int end = 0; end < v.size() - 1; end++) //排好序的最后一个索引
    {
        //待处理
        int idx = end + 1;
        while(idx > 0)
        {
            if(v[idx] < v[idx - 1])
            {
                swap(v[idx], v[idx - 1]);
                idx--;
            }
            else
            {
                break;
            }
        }
    }
}

//选择排序------------------------------------------------------------
//基本思想: 每次选择最大或最小的放到最后或最前面
//时间O(n^2),最好(n^2), 空间O(1)
//稳定性：不稳定
void SelectSort(vector<int>& v)
{
    for(int end = 0; end < v.size(); end++) //待决定位置
    {
        int min_idx = end;
        for(int i = end + 1; i < v.size(); i++)
        {
            if(v[min_idx] > v[i])
            {
               min_idx = i; 
            }
        }
        swap(v[end], v[min_idx]);
    };
};

//归并排序------------------------------------------------------------------------------
//基本思想：利用二分的特性，将序列分成两个子序列进行排序，将排序后的两个子序列归并（合并）
//时间复杂度：nlgn， 空间O(n),
//稳定性分析：稳定的，在进行合并前相等按次序合并即可

//对[start,end]范围内进行排序
//递归的复杂度：
//  对于T(n) = a*T(n/b)+c*n^k;T(1) = c 的递归关系，
// 有如下结论：
// if (a > b^k)   T(n) = O(n^(logb(a)));
// if (a = b^k)   T(n) = O(n^k*logn);
// if (a < b^k)   T(n) = O(n^k);
void MergeSort(vector<int>& v, int start, int end)
{
    if(start >= end)
    {
        return;
    };
    int mid = start + (end - start) / 2;
    
    //左右归并
    MergeSort(v, start, mid);
    MergeSort(v, mid + 1, end);

    //合并
    vector<int> merge_v;
    int l_idx = 0;
    int r_idx = mid + 1;
    while(l_idx <= mid && r_idx <= end)
    {
        if(v[l_idx] < v[r_idx])
        {
            merge_v.push_back(v[l_idx]);
            l_idx++;
        }
        else
        {
            merge_v.push_back(v[r_idx]);
            r_idx++;
        }
    };

    while(l_idx <= mid)
    {
        merge_v.push_back(v[l_idx]);
        l_idx++;
    };

    while(r_idx <= end)
    {
        merge_v.push_back(v[r_idx]);
        r_idx++;
    };

    v = merge_v;
}


int a()
{
    vector<int> S;
    int* p = S.get_allocator().allocate(10);
    S.get_allocator().deallocate(p,10);
}


//快排，快速排序-------------------------------------------------------------------------
//基本思想：选取第一个数为基准，通过一次遍历将小于它的元素放到它的左侧，将大于它的元素放到它的右侧，
//         然后对它的左右两个子序列分别递归地执行同样的操作。
//复杂度：时间O(nlgn), 空间O(1),递归栈O(n)， 最好O(n)--在一次partition后发现没有交换则不再par
//稳定性：不稳定
#include <cassert>
using namespace std;
//???
//对[star,end]范围内进行快排的partition,划分为三部分
pair<int,int> QuickSortPartition(vector<int>& v, int start, int end)
{
    //边界
    if(start < 0 || end > v.size() - 1 || (end < start))
    {
        return {-1,-1};
    }

    //选取最后一个值为基准
    int flag = v[end];
    int less_idx = start - 1; // <- less_idx]是小于基准的
    int greater_idx = end + 1;  //[greater_idx -> 是大于等于基准的
    int idx = start;
    while(idx < greater_idx)
    {
        if(v[idx] < flag)
        {
            swap(v[idx], v[less_idx + 1]);
            less_idx++;
        }
        else if(v[idx] > flag)
        {
            swap(v[idx], v[greater_idx - 1]);
            greater_idx--;
        }
        idx++;
    };
   return {less_idx, greater_idx};
};

void QuickSort(vector<int>& v, int start, int end)
{
    if(start < end)  //可能出现r > l 的情况： >区间无 
    {
        auto p_ret = QuickSortPartition(v, start, end);
        QuickSort(v, start, p_ret.first);
        QuickSort(v, p_ret.second, end);
    }
};

// 快排的非递归
void QuickSort_NDP(vector<int>& v, int start, int end)
{
    if(start < 0 || end > v.size() - 1 || end < start)
    {
        return;
    };

    stack<pair<int,int>> stk;
    auto p = QuickSortPartition(v, start, end);
    if(p.first > start)
    {
        stk.push({start, p.first});
    };
    if(p.second < end)
    {
        stk.push({p.second, end});
    };
    while(!stk.empty())
    {
        auto top = stk.top();
        stk.pop();
        auto top_p = QuickSortPartition(v, top.first, top.second);
        if(top_p.first > top.first)
        {
            stk.push({top.first, top_p.first});
        };
        if(top_p.second < top.second)
        {
            stk.push({top_p.second, top.second});
        }
    };
}


//堆排序-------------------------------------------------------------------------------------
//基本思想：堆是完全二叉树，可以用数组进行存储
//         规则:索引从0开始，索引i的父为(i - 1)/ 2; 左孩子为 2i+1,右孩子为2i + 2
//         涉及到两种操作：
//         1. 将原数组重建为大根堆：可以逐步添加新元素，添加前为大根堆，先添加到后面，然后上浮
//         2. 逻辑上弹出最大到最后并将前面的重建：
//            2.1 将idx位置与最前面的交换，则idx位置则为idx前最大，
//            2.2 现在idx位置为之前的最大，原来idx交换到最前面下沉到合适位置重建前面
//复杂度: O(nlogn)，空间O(1)
//稳定性：不稳定

void HeapSort(vector<int>& v)
{
    if(v.size() < 2)
    {
        return;
    }
    //添加方式重建大根堆
    for(int i = 1; i < v.size(); i++)
    {
        //HeapInsertByIdx(v, i);
        //添加后上浮
        int parent_idx = (i - 1) / 2;
        int cur_idx = i;
        while(parent_idx >= 0)
        {
            if(v[parent_idx] < v[cur_idx])
            {
                swap(v[parent_idx], v[cur_idx]);
                cur_idx = parent_idx;
                parent_idx = (cur_idx - 1) / 2;
            }
            else
            {
                break;
            }
        }
    };
    //从后往前删除，每次弹出包含idx之前的最大到idx处，重建idx - 1之前
    for(int j = v.size() - 1; j > 0; j--)
    {
        // HeapIfyByIdx(v, j);
        //将该位置与最前交换，逻辑上删除
        swap(v[j], v[0]);
        int new_end_idx = j - 1;

        //新的front下沉到合适的位置
        int cur_idx = 0;
        
        while(cur_idx < new_end_idx)
        {
            int lc_idx = 2 * cur_idx + 1;
            int rc_idx = 2 * cur_idx + 2;
            int max_idx = lc_idx <= new_end_idx && v[lc_idx] > v[cur_idx] ? lc_idx : cur_idx;
            max_idx = rc_idx <= new_end_idx && v[rc_idx] > v[max_idx] ? rc_idx : max_idx;
            if(max_idx == cur_idx)
            {
                break;
            }
            swap(v[cur_idx], v[max_idx]);
            cur_idx = max_idx;
        }
    }
};

//基数排序-------------------------------------------------------
// 基数排序(Radix Sort)是桶排序的扩展，它的基本思想是：将整数按位数切割成不同的数字，然后按每个位数分别比较。
// 具体做法是：将所有待比较数值统一为同样的数位长度，数位较短的数前面补零。然后，从最低位开始，依次进行一次排序。
// 这样从最低位排序一直到最高位排序完成以后, 数列就变成一个有序序列。
//时间复杂度： 空间复杂度O(n)


// 希尔排序
// 基本思想：希尔排序是把序列按一定间隔分组，对每组使用直接插入排序；随着间隔减小，一直到1，使得整个序列有序。
// 复杂度分析：
// 稳定性分析：
void ShellSort(vector<int>& v)
{
    if(v.size() < 2)
    {
        return;
    };

    auto NextIdx = [](const int cur_idx, const int interval) -> int
    {
        return cur_idx + interval;
    };
    
    auto PreIdx = [](const int cur_idx, const int interval) -> int
    {
        return cur_idx - interval;
    };

    //实现为插入排序对于每一个小组，实现Error
    int interval = v.size() / 2;
    while(interval > 0)
    {
        int cur_idx = NextIdx(0, interval); //待插入的索引
        int pre_idx = PreIdx(cur_idx, interval);
        while(cur_idx < v.size() && pre_idx >= 0)
        {
            int handle_idx = cur_idx;
            int handle_pre_idx = PreIdx(handle_idx, interval);
            while(pre_idx >= 0)
            {
                if(v[handle_idx] < v[pre_idx])
                {
                    swap(v[handle_idx], v[pre_idx]);
                }
                handle_idx = pre_idx;
                pre_idx = PreIdx(handle_idx, interval);
            }
            
            cur_idx = NextIdx(cur_idx, interval);
            pre_idx = PreIdx(cur_idx, interval);
            
        };
        interval /= 2;
    };
}


int main()
{
    vector<int> v{};
    QuickSort_NDP(v,0,v.size() - 1);
    return 0;
}