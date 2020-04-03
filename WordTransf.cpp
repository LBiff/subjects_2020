// // //单词转换
//给定字典中的两个词，长度相等。写一个方法，把一个词转换成另一个词， 
//但是一次只能改变一个字符。每一步得到的新词都必须能在字典中找到。
//编写一个程序，返回一个可能的转换序列。如有多个可能的转换序列，你可以返回任何一个。

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

class Solution
{
public:
//递归查找所有的结果
void FindAllSolution(string cur, string end,
                                       unordered_map<string, vector<string>> neig,
                                       unordered_map<string,int> dis,
                                       vector<string> cur_solution,
                                       vector<vector<string>>* ret)
{
    cur_solution.push_back(cur);
    if(cur == end)
    {
        ret->push_back(cur_solution);
    }
    else
    {
        for(string next : neig.find(cur)->second)
        {
            if((dis.find(next)->second) == (dis.find(cur)->second + 1))
            {
                FindAllSolution(next,end, neig,dis,cur_solution,ret);
            }
        }
    };
};

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
{
    //入hash
    unordered_set<string> str_set;
    for(auto word : wordList)
    {
        str_set.insert(word);
    };
    str_set.insert(beginWord);

    //建立每个节点的邻居
   unordered_map<string, vector<string>> neibor_word;
    auto find_neibor = [&](string ori_str)
    {
        vector<string> insert_str_vec;;
        for(int i =0; i < ori_str.size(); i++)
        {
            string str_tmp = ori_str;
            for(char c = 'a'; c <= 'z'; c++)
            {
                str_tmp[i] = c;
                if(str_set.find(str_tmp) != str_set.end() && c != ori_str[i])
                {
                    insert_str_vec.push_back(str_tmp);
                }
            }
        };
        neibor_word.insert(make_pair(ori_str, insert_str_vec));
    };

    for(auto str_i : str_set)
    {
        find_neibor(str_i);
    };


    //宽度优先遍历创建距离
   unordered_map<string,int> dis;
    dis.insert(make_pair(beginWord,0));

    unordered_set<string> set;  //为了避免环的出现

    queue<string> q;
    q.push(beginWord);

    while(!q.empty())
    {
        string q_top = q.front();
        q.pop();
        for(auto top_neig : neibor_word.find(q_top)->second)
        {
            if(set.find(top_neig) == set.end())  //不存在
            {
                q.push(top_neig);
                dis.insert(make_pair(top_neig, dis.find(q_top)->second + 1));
                set.insert(top_neig);
            }
        };
    };
    vector<vector<string>> ret;
    FindAllSolution(beginWord, endWord,neibor_word,dis,vector<string>(),&ret);
    return ret;
};

};

//方法二：不全部遍历，在建树中检测
///////////////////////////////////////////////////////////////////////////////////////////

class Solution_2
{
public:
//直接深度遍历
struct Node
{
    vector<Node*> _child_list;
    string _value;
    Node* _p;
    Node(string v, Node* p=nullptr):_value(v),_p(p){};
    
};

//返回endNode
Node* FindChild(Node* pn, unordered_set<string>& str_set, string end_str, unordered_set<string>& norpeat_set) 
{
    vector<Node*> children;
    norpeat_set.insert(pn->_value);
    for(int i =0; i < pn->_value.length(); i++)
    {
        string str_tmp = pn->_value;
        for(char c = 'a'; c <= 'z'; c++)
        {
            str_tmp[i] = c;
            if(str_set.find(str_tmp) != str_set.end() && c != pn->_value[i])
            {
                if(norpeat_set.find(str_tmp) == norpeat_set.end())  //没有查找到
                {
                    Node* n = new Node(str_tmp,pn);
                    children.push_back(n);
                    norpeat_set.insert(str_tmp);
                    if(str_tmp == end_str)
                    {
                        pn->_child_list = children;
                        return n;
                    }
                }
            }
        }
    };
    pn->_child_list = children;
    return nullptr;
};
    
//获取最近的endNode
Node* GetLastEndNode(Node* cur, unordered_set<string> str_set, string end_str, unordered_set<string>& norpeat_set)
{
    Node* get_last_end = FindChild(cur,str_set, end_str, norpeat_set);
    if(get_last_end)
    {
        return get_last_end;
    }
    else
    {
        for(auto c : cur->_child_list)
        {
            get_last_end = GetLastEndNode(c,str_set, end_str, norpeat_set);
            if(get_last_end)
            {
                return get_last_end;
            }
        }
    }
    return nullptr;
};


vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList)
{
    //入hash    

    unordered_set<string> str_set;
    for(auto word : wordList)
    {
        str_set.insert(word);
    };
    str_set.insert(beginWord);

    //建立每个节点的邻居 
    Node* begin_node = new Node(beginWord);
    begin_node ->_p = nullptr;
    unordered_set<string> norpeat_set;

    Node* nearest_node = GetLastEndNode(begin_node,str_set,endWord, norpeat_set);

    //向上查找  
    stack<string> stack_str;
    Node* cur = nearest_node;
    while(cur)
    {
        stack_str.push(cur->_value);
        cur = cur->_p;
    };

    vector<string> ret;
    while(!stack_str.empty())
    {
        ret.push_back(stack_str.top());
        stack_str.pop();
    };

    return ret;
};
};


//直接返回距离
int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
{
    unordered_set<string> dic_set;
    for(auto w : wordList)
    {
        dic_set.insert(w);
    };

    if(dic_set.find(endWord) == dic_set.end())
    {
        return 0;
    }
    
    //查找邻居节点
    unordered_map<string, vector<string>> neigbor_map;
    auto find_neigbor = [&](const string& ori_str)
    {
        vector<string> neig_v;
        for(int i =0; i< ori_str.size(); i++)
        {
            for(char c = 'a'; c <= 'z'; c++)
            {
                string str_tmp = ori_str;
                str_tmp[i] = c;
                auto iter = dic_set.find(str_tmp);
                if(iter != dic_set.end() && (*iter) != ori_str)
                {
                    neig_v.push_back(*iter);
                }
            }
        };
        neigbor_map.insert({ori_str, neig_v});
    };
    
    find_neigbor(beginWord);
    for(auto w : wordList)
    {
        find_neigbor(w);
    };
    
    //逻辑建树检测
    //按层加入
    unordered_set<string> inserted_set; //避免环出现
    int ret = 1;
    queue<string> q;
    q.push(beginWord);
    inserted_set.insert(beginWord);
    while(!q.empty())
    {
        size_t q_count = q.size();
        //邻居节点
        ret += 1;
        while(q_count-- > 0)
        {
            string f = q.front();
            q.pop();
            //加入邻居
            auto iter = neigbor_map.find(f);
            for(auto s : iter->second)
            {
                if(s == endWord)
                {
                    return ret;
                }
                if(inserted_set.find(s) == inserted_set.end())
                {
                    q.push(s);
                    inserted_set.insert(s);
                }
            }
        }
    }
    
    return 0; 
}

int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList{"hot","dot","dog","lot","log"};
    ladderLength(beginWord,endWord,wordList);
    // Solution_2 s;

    // vector<string> a = s.findLadders(beginWord, endWord,wordList);
    return 0;
}

