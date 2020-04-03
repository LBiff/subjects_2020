//相似字符串组
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

//建立并查集，定义相似为两string不相等字符数2或0， 相似则合并，每合并一次集合-1
class Solution 
{
public:
    int numSimilarGroups(vector<string>& A) 
    {
        //去除重复

        //各自成集合
        uf_size = A.size();
        for(auto s : A)
        {
            _re_map.insert({s,s});
            _sub_size.insert({s,1});
        };

        //查找合并
        for(int i =0; i< A.size(); i++)
        {
            for(int j = 0; j < A.size(); j++)
            {
                if(IsSamilar(A[i], A[j]) && !IsSameSet(A[i], A[j]))
                {
                    Union(A[i], A[j]);
                    uf_size--;
                }
            }
        };

        return uf_size;
    };

    bool IsSamilar(const string& s1, const string& s2)
    {
        int diff_count = 0;
        for(int i = 0; i< s1.size(); i++)
        {
            if(s1[i] != s2[i])
            {
                diff_count++;
            }
        };
        return diff_count == 0 || diff_count == 2 ? true : false;
    };

    //判断是否是同一集合
    bool IsSameSet(const string& s1, const string& s2)
    {
        return FindRepresentNode(s1) == FindRepresentNode(s2);
    };

    //合并两个集合
    void Union(const string& s1, const string& s2)
    {
        string re_1 = FindRepresentNode(s1);
        string re_2 = FindRepresentNode(s2);
        if(re_1 != re_2)  //不是一个集合
        {
            size_t size_1 = _sub_size.find(re_1)->second;
            size_t size_2 = _sub_size.find(re_1)->second;

            if(size_1 < size_2)
            {
                _re_map[re_1] = re_2;
                _sub_size[re_2] = size_1 + size_2;
            }
            else
            {
                _re_map[re_2] = re_1;
                _sub_size[re_1] = size_1 + size_2;
            }
        }
    }
private:
    string FindRepresentNode(string s)
    {
        string father = _re_map.find(s)->second;
        if(father != s)
        {
            father = FindRepresentNode(father);
        };
        _re_map.insert({s, father});
        return father;

    }

private:
    size_t uf_size; //并查集合个数
    unordered_map<string, string> _re_map; //<node, represent_node>
    unordered_map<string, int> _sub_size; //子集合大小
};

int main()
{
    vector<string> s{"abc","abc"};
    Solution solu;
    auto ret = solu.numSimilarGroups(s);
    return 0;
}