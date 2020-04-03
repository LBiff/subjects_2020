//插入排序

#include <vector>
using namespace std;

void InsertSort(vector<int>& vec)
{
    if(vec.size() < 2)
    {
        return;
    };

    for(int insert_idx = 1; insert_idx < vec.size(); insert_idx++)
    {
        int loc = insert_idx;
        while(loc > 0)
        {
            if(vec[loc] < vec[loc - 1])
            {
                std::iter_swap(vec.begin() + loc, vec.begin() + loc - 1); 
                loc--;
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
    vector<int> a{155,4,2536,4,8,5,44,2,1};
    InsertSort(a);
    return 0;

}