//队列和栈的相互转换

//用两个队列实现一个栈:两个队列互倒，返回最后一个互换索引

#include <stack>
#include <queue>
#include <iostream>
#include <typeinfo>
using namespace std;

class StackByQueues
{
public:
    StackByQueues()
    {
        _queue = new queue<int>();
        _help = new queue<int>();
    };

    ~StackByQueues()
    {
        if(_queue)
        {
            delete _queue;
        };
        if(_help)
        {
            delete _help;
        }
    };

    void Push(const int& e)
    {
        _queue->push(e);
    };

    void Pop(int& e)
    {
        if(_queue->empty())
        {
            cout << "Pop: empty!!" << endl;
        }
        else
        {
            while(_queue->size() != 1)
            {
                int top = _queue->front();
                _queue->pop();
                _help->push(top);
            };
            e = _queue->front();
            _queue->pop();

            //交换
            queue<int>* tmp;
            tmp = _queue;
            _queue = _help;
            _help = tmp;
        }
    };


private:
    //采用栈的引用用来进行互换
    queue<int>* _queue;
    queue<int>* _help;
};

//两个栈实现队列 stack, help
//1.一次pop stack-->help剩一个弹出，help-->stack,   时间复杂度较高
//2. push,pop两个栈，push操作入push, pop操作从pop出，pop为空时尝试从push中全部倒出来

class QueueByStacks
{
public:
    QueueByStacks(){};
    ~QueueByStacks(){};

    void Push(const int& e)
    {
        _push_stack.push(e);
    }

    void Pop(int& e)
    {
        if(_pop_stack.empty())
        {
            //尝试从push栈中全部拿
            if(_push_stack.empty())
            {
                cout << "Pop: Empty!!!" << endl;
                return;
            }
            else
            {
                while(!_push_stack.empty())
                {
                    int tmp = _push_stack.top();
                    _pop_stack.push(tmp);
                    _push_stack.pop();
                };
                e = _pop_stack.top();
                _pop_stack.pop();
            }
            
        }
        else
        {
            e = _pop_stack.top();
            _pop_stack.pop();
        }
        
    }
private:
    stack<int> _push_stack;
    stack<int> _pop_stack;
};


//猫狗队列问题：两个队列（cat和dog),分别进，数据项封装进队列时间戳

class Pet
{
    // virtual void f(){};
};

class Cat : public Pet
{

};

class Dog : public Pet
{

};

int main()
{
    Cat c;
    Dog d;
    Pet* pp;
    pp = &c;
    cout << typeid(pp).name() << endl;

    cout << typeid(*pp).name() << endl;
    cout << typeid(Dog).name() << endl;
    bool bb = typeid(*pp) ==  typeid(c);
    if(typeid(pp) ==  typeid(&c))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;

    }
    




    // StackByQueues s;
    // int a;
    // s.Push(1);
    // s.Push(2);
    // s.Pop(a);
    // s.Pop(a);
    // s.Pop(a);
    // s.Pop(a);
    // QueueByStacks q;
    // int a;
    // q.Push(1);
    // q.Push(2);
    // q.Pop(a);
    // q.Pop(a);
    // q.Pop(a);
    // q.Push(3);
    // q.Pop(a);
    // q.Pop(a);

    return 0;
    
}