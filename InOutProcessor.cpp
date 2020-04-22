//输入输出处理器
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class InOutProcessor
{
public:
    //输入
    //获取一行
    static string GetLine()
    {
        string s;
        getline(cin,s);
        return s;
    };

    //以空格分隔获取一行整数数组
    static vector<int> GetIntVByLineBySpace()
    {
        string s;
        string word;
        vector<int> v;
        getline(cin,s);
        istringstream record(s);
        while(record >> word)
        {
            v.push_back(atoi(word.c_str()));
        };
        return v;
    };
    //获取以特定字符分隔的string数组
    static vector<string> GetStrVByLineBySpecific(string spilt_c)
    {
        string s;
        getline(cin,s);
        vector<string> v;
        size_t first_pos = s.find_first_of(spilt_c,0);
        v.push_back(s.substr(0, first_pos));
        int pre = first_pos;
        size_t pos =  s.find_first_of(spilt_c,pre + 1);
        while(pos != string::npos)
        {
            v.push_back(s.substr(pre+1, pos-pre -1));
            pre = pos;
            pos = s.find_first_of(spilt_c,pos + 1);
        };
        v.push_back(s.substr(pre+1));
        return v;   
    };

    //获取以空格分隔的一行字符串数组
    static vector<string> GetLineStringVSpiltBySpace()
    {
        string s;
        string word;
        vector<string> v;
        getline(cin,s);
        istringstream record(s);
        while(record >> word)
        {
            v.push_back(word);
        };
        return v;
    };


    //输出
    //打印数组，输出左右以l_flg匹配，以split_S分隔
    template<typename T>
    static void PrintV(const vector<T> v, string l_flag = "[", string spilt_s = " ")
    {
        cout << l_flag;
        int i = 0;
        for(; i < v.size() - 1; i++)
        {
            cout << v[i] << spilt_s;
        };
        if(i == v.size() - 1)
        {
            cout <<v[i];
        }
        if(l_flag == "[")
        {
            cout << "]" << endl;
        }
        else if(l_flag == "{")
        {
            cout << "}" << endl;
        }
    };

};

int main()
{
   // auto ret = InOutProcessor::GetStrVByLineBySpecific(",");
    vector<int> a{1,2,3,4,5,6,7,8,9,10};
    InOutProcessor::PrintV(a,"["," ");
    return 0;
}