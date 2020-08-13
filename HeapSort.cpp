//堆排序

#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

//向大根堆后添加数并重新调整微大根堆
void HeapInsertValue(vector<int>& vec, int value)
{
    vec.push_back(value);
    int v_idx = vec.size() - 1;
    int parent_idx = (v_idx - 1) / 2;

    while(parent_idx >= 0)
    {
        if(vec[v_idx] > vec[parent_idx])
        {
            std::iter_swap(vec.begin() + v_idx, vec.begin() + parent_idx);
            v_idx = parent_idx;
            parent_idx = (parent_idx - 1) / 2;
        }
        else
        {
            break;
        }
    }
};

//idx为新加入元素的索引，idx前为调整好的大根堆
void HeapInsertIdx(vector<int>& vec, int idx)
{
    assert(idx <= vec.size() - 1);
    if(idx < 1)
    {
        return;
    };
    int parent_idx = (idx - 1) / 2;
    while(parent_idx >= 0)
    {
        if(vec[idx] > vec[parent_idx])
        {
            std::iter_swap(vec.begin() + idx, vec.begin() + parent_idx);
            idx = parent_idx;
            parent_idx = (parent_idx -1) / 2;
        }
        else
        {
            break;
        }
    }
};

//逻辑上从后删除idx位置的元素
void HeapIfy(vector<int>& vec, int idx)
{
    assert(idx <= vec.size() -1);
    //将其位置与根节点进行交换，弹出最大值
    std::iter_swap(vec.begin() + idx, vec.begin());
    int heap_end = idx - 1;
    int idx_new = 0;
    //向下沉将idx之前的重新调整为大根堆
    while(idx_new <= heap_end)
    {
        int left_idx = 2 * idx_new + 1;
        int right_idx = 2 * idx_new + 2;
        int largest_idx = left_idx <= heap_end && vec[left_idx] > vec[idx_new] ? left_idx : idx_new;
        largest_idx = right_idx <= heap_end && vec[right_idx] > vec[largest_idx] ? right_idx : largest_idx;
        if(largest_idx == idx_new)
        {
            break;
        }
        else
        {
            std::iter_swap(vec.begin() + idx_new, vec.begin() + largest_idx);
            idx_new = largest_idx;
        }
        
    }
};

void HeapSort(vector<int>& vec)
{
    if(vec.size() < 2)
    {
        return;
    };
    //建立大根堆
    for(int i=0; i< vec.size(); i++)
    {
        HeapInsertIdx(vec,i);
    };
    //从后依次取出最大值
    for(int j=vec.size() - 1; j >= 0; j--)
    {
        HeapIfy(vec, j);
    }
};

int main()
{
    vector<int> a{};
    HeapSort(a);
    return 0;
}