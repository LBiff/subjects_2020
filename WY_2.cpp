#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstddef>
using namespace std;

//小跟堆
class fsys
{
public: 
    //查询最小fd
    int QuaryMinFd()
    {
        for(int i = 0; i <= INT32_MAX; i++)
        {
            if(i == INT_MAX)
            {
                return -1;
            }
            if(fd_map.find(i) == fd_map.end())
            {
                return i;
            }
        };
        return -1;
    };

    int open(const string& file_name)
    {
        int fd = QuaryMinFd();
        fd_map.insert({fd, file_name});
        return fd;
    };

    int dup(int fd)
    {
        auto iter = fd_map.find(fd);
        int new_fd = QuaryMinFd();
        string file = iter->second;
        fd_map.insert({new_fd,file});
        return new_fd;
    };

    void dup2(int fd, int new_fd)
    {
        auto iter_fd = fd_map.find(fd);
        auto iter_new_fd = fd_map.find(new_fd);
  
        if(iter_new_fd != fd_map.end())
        {
            fd_map.erase(new_fd);
        };
        fd_map.insert({new_fd, iter_fd->second});
    };

    void close(int fd)
    {
   
        fd_map.erase(fd);
    };

    string quary(int fd)
    {
        auto iter_fd = fd_map.find(fd);
        return iter_fd->second;
    };

private:
    unordered_map<int, string> fd_map;
};

vector<string> GetStrVSpiltByChar(char c)
{
    string s;
    getline(cin,s);
    vector<string> v;
    size_t first_pos = s.find_first_of(c,0);
    v.push_back(s.substr(0, first_pos));
    int pre = first_pos;
    size_t pos =  s.find_first_of(c,pre + 1);
    while(pos != string::npos)
    {
        v.push_back(s.substr(pre+1, pos-pre -1));
        pre = pos;
        pos = s.find_first_of(c,pos + 1);
    };
    v.push_back(s.substr(pre+1));
    return v;   
};

int main()
{
    string tmp;
    getline(cin,tmp);
    int test_count = atoi(tmp.c_str());
    while(test_count-- > 0)
    {
        fsys fs;
        getline(cin,tmp);
        int diaoyong = atoi(tmp.c_str());
        while(diaoyong-- > 0)
        {
            auto p = GetStrVSpiltByChar(' ');
            if(p[0] == "open")
            {
                cout << fs.open(p[1]) << endl;
            }
            else if(p[0] == "dup")
            {
                cout << fs.dup(atoi(p[1].c_str())) << endl;
            }
            else if(p[0] == "dup2")
            {
                fs.dup2(atoi(p[1].c_str()),atoi(p[2].c_str()));
            } 
            else if(p[0] == "close")
            {
                fs.close(atoi(p[1].c_str()));
            }
            else if(p[0] == "query")
            {
                cout << fs.quary(atoi(p[1].c_str())) << endl;
            }
        }
    };

    return 0;

}
