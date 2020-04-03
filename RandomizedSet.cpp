// 设计一个支持在平均 时间复杂度 O(1) 下，执行以下操作的数据结构。
// insert(val)：当元素 val 不存在时，向集合中插入该项。
// remove(val)：元素 val 存在时，从集合中移除该项。
// getRandom：随机返回现有集合中的一项。每个元素应该有相同的概率被返回。
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() 
    {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) 
    {
        if(map.find(val) != map.end())
        {
            return false;
        }
        else
        {
            v.push_back(val);
            map.insert({val, v.size() - 1});
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) 
    {
        //查找索引
        auto iter = map.find(val);
        if(iter != map.end())
        {
            map.find(v.back())->second = iter->second; //更新交换的索引
            swap(v[iter->second], v[v.size() - 1]);
            v.erase(v.end() - 1);
            map.erase(val);
            return true;
        }
        else
        {
            return false;
        };
    }
    
    /** Get a random element from the set. */
    int getRandom() 
    {
        //srand(time(0));
        return v[rand() % (v.size())];
    }
private:
    vector<int> v; //存储值
    unordered_map<int, int> map; //<值，v索引>
};

int main()
{
    RandomizedSet set;
    set.insert(0);
    set.insert(1);
    set.remove(0);
    set.insert(2);
    set.remove(1);
    int a = set.getRandom();
    return 0;
}