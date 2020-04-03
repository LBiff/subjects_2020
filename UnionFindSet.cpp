//并查集
#include <hash_map>
#include <vector>
using namespace std;

template<typename T>
class UnionFindSet
{
public:
    UnionFindSet(vector<T> v_d)
    {
        _data = v_d;
        int idx = 0;
        //各自为政
        while(idx < v_d.size())
        {
            _map_data_represent_data.insert(pair<T, T>(v_d[idx], v_d[idx]));
            _map_data_size.insert(pair<T, int>(v_d[idx], 1));
            idx++;
        }
    };

    UnionFindSet(){};

    //插入新的独集合
    void Insert(const T d)
    {
         _map_data_represent_data.insert(pair<T, T>(d,d));
         _map_data_size.insert(pair<T, int>(d, 1));
    }


    //是否在一个集合
    bool isSameSet(T d_1, T d_2)
    {
      return  FindRepresent(d_1) == FindRepresent(d_2) ? true : false;
    };

    //合并d_1和d_2所在的两个集合
    void UnionSet(T d_1, T d_2)
    {
        T d_1_re = FindRepresent(d_1);
        T d_2_re = FindRepresent(d_2);
        if(d_1_re != d_2_re)
        {
            int d_1_size = _map_data_size.find(d_1_re)->second;
            int d_2_size = _map_data_size.find(d_2_re)->second;
            if(d_1_size <= d_2_size)
            {
                _map_data_represent_data.insert(pair<T, T>(d_1_re, d_2_re));
                _map_data_size.insert(pair<T, int>(d_2_re, d_1_size + d_2_size));
            }
            else
            {
                _map_data_represent_data.insert(pair<T, T>(d_2_re, d_1_re));
                _map_data_size.insert(pair<T, int>(d_1_re, d_1_size + d_2_size));
            }
        }
    }
private:

    //找代表节点,查找过程中并打平
    T FindRepresent(T d)
    {
       T father = _map_data_represent_data.find(d)->second;
       if(father != d)
       {
           father = FindRepresent(father);
       };
       _map_data_represent_data.insert(pair<T, T>(d, father));
       return father;
    }
private:
    __gnu_cxx::hash_map<T, T> _map_data_represent_data; //节点和其代表节点
    __gnu_cxx::hash_map<T, int> _map_data_size; //节点所在集合的大小，只有T是代表节点时才有效
    vector<T> _data;

};


int main()
{

}