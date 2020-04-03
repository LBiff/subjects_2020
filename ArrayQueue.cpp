//数组实现固定大小队列
//一个数组，一个start指向下一个要放的位置，一个end指向 下一个要取的位置， 循环数组
#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class ArrayQueue
{
public:
    ArrayQueue(uint64_t size)
    {
        if(size < 1)
        {
            throw invalid_argument("The size of array must greater than 0.");
        };
        _count = 0;
        _array.assign(size,T());
        _next_push_idx = 0;
        _next_pop_idx = 0;
    };

    ~ArrayQueue()
    {

    };

    bool Push(const T& e)
    {
        if(_count < _array.size())
        {
            _array[_next_push_idx] = e;
            _next_push_idx = _next_push_idx + 1 > _array.size() - 1 ? 0 : _next_push_idx + 1;
            _count++;
            return true;
        }
        else
        {
            return false;
        }
        
    };

    bool Pop(T& e)
    {
        if(_count > 0)
        {
            e = _array[_next_pop_idx];
            _next_pop_idx = _next_pop_idx + 1 > _array.size() - 1 ? 0 : _next_pop_idx + 1;
            _count--;
            return true;
        }
        else
        {
            return false;
        }
        
    }

    void PrintQueue()
    {
        cout << _count << "[" <<_next_pop_idx << "," << _next_push_idx << ") ==> ";
        if(_count > 0)
        {
            uint64_t idx = _next_pop_idx;
            cout << _array[idx] << " ";
            idx = idx + 1 > _array.size() -1 ? 0 : idx + 1;
            while(idx != _next_push_idx)
            {
                cout << _array[idx] << " ";
                idx = idx + 1 > _array.size() -1 ? 0 : idx + 1;
            };

            if(_count == _array.size())
            {
                cout << "  Full!!";
            }
            cout << endl;
        }
        else
        {
            cout << "Empty!!" << endl;
        }
        
    }


private:
    uint64_t _count; //目前队列元素数
    vector<T> _array;
    uint64_t _next_push_idx; //下次要加入的位置
    uint64_t _next_pop_idx; //队列尾
};

int main()
{
    ArrayQueue<int> a(3);
    a.PrintQueue();
    a.Push(1);
    a.PrintQueue();
    a.Push(2);
    a.PrintQueue();
    a.Push(3);
    a.PrintQueue();
    a.Push(4);
    a.PrintQueue();

    int b;
    a.Pop(b);
    a.PrintQueue();
    a.Pop(b);
    a.PrintQueue();
    a.Pop(b);
    a.PrintQueue();
    a.Pop(b);
    a.PrintQueue();

    a.Push(88);
    a.PrintQueue();



}
