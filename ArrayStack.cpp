//用数组实现大小固定的栈
#include <cstdlib>

template<typename T>
class ArrayStack
{
public:
    ArrayStack(const uint64_t size) : _array_stack(NULL)
    {
        _array_stack_size = size;
        _array_stack = new T[size];
        _index = 0;
    };
    ~ArrayStack()
    {
        if(_array_stack)
        {
        delete []_array_stack;
        }
    };

    bool push(const T& ele)
    {
        if(_index >= _array_stack_size)
        {
            return false;
        }

        _array_stack[_index++] = ele;
        return true;
    };
    bool pop(T& pop_e)
    {
        if(_index < 1)
        {
            return false;
        };

        pop_e = _array_stack[--_index];
        return true;
    }

private:
    uint64_t _array_stack_size; 
    uint64_t _index;  //下一个Push的位置
    int* _array_stack;

};

int main()
{
    ArrayStack<int> a(3);
   bool b =  a.push(1);
   bool c = a.push(2);
   bool d = a.push(3);
   bool e = a.push(4);
   int aa,bb,cc,dd;
   bool f = a.pop(aa);
   bool g = a.pop(bb);
   bool h = a.pop(cc);
   bool i = a.pop(dd);

   bool k = a.push(33);
   bool l = a.pop(aa);


};