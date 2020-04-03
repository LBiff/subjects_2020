//RandomPop问题:设计一种结构对于key值的增删查O(1),可以等概率返回一个key值
///两个hash_map同时操作(<key,idx>, <idx,key>),idx是加入的时间戳，insert_idx额外记录当前的个数，
//方便计算返回随机数，
//删除操作时候，删除最后一个idx的记录，将最后记录覆盖真正要删除的记录，其索引为真正要删除记录的idx,
//可以做到idx连续，每次只删除最后的

#include <string>
#include <hash_map>
#include <utility>
#include <random>
#include <ctime>
#include <iostream>
using namespace std;

class RandomPop
{
    RandomPop() : idx(0){};
    ~RandomPop(){};

    void add(const string& s)
    {
        _map_k_idx.insert(std::make_pair(s,idx));
        _map_idx_k.insert(std::make_pair(idx,s));
    };

    void del(const string& s)
    {
        //未找到
        auto k_iter = _map_k_idx.find(s);
        if(k_iter == _map_k_idx.end())
        {   
            return;
        }
        else
        {
            //1.找到idx
            int del_idx = k_iter->second;
            //2.覆盖处理
            //2.1　查找最后一条k
            string last_k = _map_idx_k.find(del_idx)->second;
            //2.2 最后key覆盖删除的Key
            _map_k_idx.insert(make_pair(last_k,del_idx));
            _map_k_idx.erase(k_iter);

            _map_idx_k.insert(make_pair(del_idx,last_k));
            _map_idx_k.erase(_map_idx_k.find(del_idx));

            _map_k_idx.erase(k_iter);
            auto idx_iter = _map_idx_k.find(del_idx);
            _map_idx_k.erase(idx_iter);
        }
    };

    string RandomPoll()
    {
        if(!_map_k_idx.empty())
        {
            srand(time(0));
            int random_idx = rand() % (idx - 1);
            return _map_idx_k.find(random_idx)->second;
        }
        else
        {
            cout << "Poll: Empty!!" << endl;
        }
    }
        
private:
    __gnu_cxx::hash_map<string,int> _map_k_idx; //<key,idx>
    __gnu_cxx::hash_map<int,string> _map_idx_k; //<idx,key>
    int idx; //下次添加的索引
};

int main()
{
    
}

