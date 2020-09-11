// 线程安全的单例模式
// 单例大约有两种实现方法：懒汉与饿汉。

// 懒汉：故名思义，不到万不得已就不会去实例化类，也就是说在第一次用到类实例的时候才会去实例化，所以上边的经典方法被归为懒汉实现；
// 饿汉：饿了肯定要饥不择食。所以在单例类定义的时候就进行实例化。
// 【特点说明】：

// 由于要进行线程同步，所以在访问量比较大，或者可能访问的线程比较多时，采用饿汉实现，可以实现更好的性能。这是以空间换时间。
// 在访问量较小时，采用懒汉实现。这是以时间换空间。

// 懒汉模式
class singleton
{
public:
    static pthread_mutex_t mutex;
    static singleton* initance();
protected:
    singleton()
    {
        pthread_mutex_init(&mutex);
    }
private:
    static singleton* p;

};
 
pthread_mutex_t singleton::mutex;
singleton* singleton::p = NULL;
singleton* singleton::initance()
{
    if (p == nullptr)
    {
        pthread_mutex_lock(&mutex);
        if (p == NULL)
            p = new singleton();
        pthread_mutex_unlock(&mutex);
    }
    return p;
};


//饿汉模式
class singleton
{
public:
    static singleton* initance();
protected:
    singleton(){} 
private:
    static singleton* p;

};
singleton* singleton::p = new singleton;
singleton* singleton::initance()
{
    return p;
}