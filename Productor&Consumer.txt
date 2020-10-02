//生产者消费者模型

/*  手撕生产者与消费者模型
 *  一个场所，两种角色，三种关系
 *  场所：线程 安全的队列
 */
#include <iostream>
#include <queue>
#include <pthread.h>
class BlockQueue
{
    public:
    BlockQueue(int cap = 10):_capacity(cap){
        pthread_mutex_init(&_mutex, NULL);
        pthread_cond_init(&_cond_productor, NULL);
        pthread_cond_init(&_cond_consumer, NULL);
    }
    ~BlockQueue(){
        pthread_mutex_destroy(&_mutex);
        pthread_cond_destroy(&_cond_productor);
        pthread_cond_destroy(&_cond_consumer);
    }
    bool QueuePush(int data) {
        QueueLock();        //加锁
        while (QueueIsFull()) { //队列满了
        ProductorWait();    //生产者休眠
        }
        _queue.push(data);
        ConsumerWakeUp();       //唤醒消费者
        QueueUnLock();      //解锁
        return true;
    }
    bool QueuePop(int *data) {
        QueueLock();        //加锁
        while (QueueIsEmpty()) { //队列空
        ConsumerWait();    //消费者休眠
        }
        *data = _queue.front();
        _queue.pop();
        ProductorWakeUp();      //唤醒生产者
        QueueUnLock();      //解锁
        return true;
    }
    private:
    void QueueLock() {
        pthread_mutex_lock(&_mutex);
    }
    void QueueUnLock() {
        pthread_mutex_unlock(&_mutex);
    }
    void ProductorWait(){
        pthread_cond_wait(&_cond_productor, &_mutex);
    }
    void ProductorWakeUp() {
        pthread_cond_signal(&_cond_productor);
    }
    void ConsumerWait(){
        pthread_cond_wait(&_cond_consumer, &_mutex);
    }
    void ConsumerWakeUp(){
        pthread_cond_signal(&_cond_consumer);
    }
    bool QueueIsFull(){
        return (_queue.size() == _capacity);
    }
    bool QueueIsEmpty(){
        return _queue.empty();
    }
    private:
    std::queue<int> _queue;
    int _capacity;
    pthread_mutex_t _mutex;
    pthread_cond_t  _cond_productor;
    pthread_cond_t  _cond_consumer;
};
 
void* thr_consumer (void *arg)
{
    BlockQueue *q = (BlockQueue*)arg;
    while(1) {
    int  data;
    q->QueuePop(&data);
    std::cout<<"consumer  get data:"<<data<<std::endl;
    }
    return NULL;
}
void* thr_productor(void *arg)
{
    int i = 0;
    BlockQueue *q = (BlockQueue*)arg;
    while(1) {
    std::cout<<"productor put data:"<<i<<std::endl;
    q->QueuePush(i++);
    }
    return NULL;
}
int main (int argc, char *argv[])
{
    pthread_t ctid[4], ptid[4];
    BlockQueue q;
    int ret;
 
    for(int i = 0; i < 4; i++) {
    ret = pthread_create(&ctid[i], NULL, thr_consumer, (void*)&q);
    if (ret != 0) {
        std::cout<<"pthread create error\n";
    }
    }
    for(int i = 0; i < 4; i++) {
    ret = pthread_create(&ptid[i], NULL, thr_productor, (void*)&q);
    if (ret != 0) {
        std::cout<<"pthread create error\n";
    }
    }
    for(int i = 0; i < 4; i++) {
    pthread_join(ctid[i], NULL);
    }
    for(int i = 0; i < 4; i++) {
    pthread_join(ptid[i], NULL);
    }
    return 0;
}