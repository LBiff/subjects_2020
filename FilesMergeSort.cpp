//评测题目: 无
/*
 问题：两个文本文件，每个文本文件是一行行的字符串，请合并两个文本，并按照字符串大小排序输出一个新文本。
 字符串比较请自己实现。1)每个文本先排序 2）两个排序后的文本在合并
 
 每行字符串长度不超过256
 
 测试文本
 $cat file_log1.txt
aaaaa
cccccccc
dddddd
bbbbb
eeeeeee

$cat file_log2.txt
aaaaa1
bbbb
dddddd4
eeeeeee5
cccccccc3
fffffffffff

输出文本:
$cat file_log3.txt
aaaaa
aaaaa1
bbbb
bbbbb
cccccccc
cccccccc3
dddddd
dddddd4
eeeeeee
fffffffffff
*/

//cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

// str1小于str2
class Comparator
{
public:
  bool operator()(const string& s1, const string& s2)
  {
  	if(!s1.empty() && s2.empty())
    {
    	return false;
    }
    size_t s1_size = s1.size();
    size_t s2_size = s2.size();
    size_t s1_idx = 0;
    size_t s2_idx = 0;
    while(s1_idx < s1_size && s2_idx < s2_size)
    {
      if(s1[s1_idx] < s2[s2_idx])
      {
        return true;
      }
      else if(s1[s1_idx] > s2[s2_idx])
      {
          return false;
      }
      
      s1_idx++;
      s2_idx++;
    };
    if(s1_idx < s1_size)
    {
        return false;
    };
    return true;
  };
};
   
//从文件中按序读取一行
string ReadFromFileByLine(ifstream& inStream, const string& path, bool& is_end)
{
	if(inStream.eof())
    {
    	is_end = true;
        return "";
    };
    string tmp;
    inStream >> tmp;
    return tmp;
};
    
void WriteFile(ofstream& outStream, const vector<string>& vs, const string& path)
{
	for(auto i : vs)
    {
    	outStream << i << endl;
    };
    outStream.close();
}
// 合并两个文件并排序
//不建议对于大文件采用此操作，因为大文件存在排序后合并时索引溢出
// 大文件采用此操作需要先拆分文件
void MergeFiles(const string& path_1, const string& path_2, const string& out_path)
{
    bool file_1_end = false;
    bool file_2_end = false;
      
    vector<string> vs_1;
    vector<string> vs_2;
    ifstream stream_1(path_1);
    ifstream stream_2(path_2);
    if(!stream_1.is_open())
    {
        cout << "file_1 open failed!" << endl;
        return;
    };
    if(!stream_2.is_open())
    {
        cout << "file_2 open failed!" << endl;
        return;
    };
    while(!file_1_end)
    {
      string tmp = (ReadFromFileByLine(stream_1, path_1, file_1_end));
      if(!file_1_end)
      {
      	vs_1.push_back(tmp);
      }
    };
    while(!file_2_end)
    {
      string tmp = (ReadFromFileByLine(stream_2,path_2, file_2_end));
      if(!file_2_end)
      {
      	vs_2.push_back(tmp);
      };
    };
    //文件流关闭
    stream_1.close();
    stream_2.close();
    
    
  	sort(vs_1.begin(), vs_1.end(), Comparator());
    sort(vs_2.begin(), vs_2.end(), Comparator());
    size_t idx_1 = 0;
    size_t idx_2 = 0;
    vector<string> vs_ret;
    while(idx_1< vs_1.size() && idx_2 < vs_2.size())
    {
    	if(Comparator()(vs_1[idx_1], vs_2[idx_2]))
        {
        	vs_ret.push_back(vs_1[idx_1]);
            idx_1++;
        }
        else
        {
        	vs_ret.push_back(vs_2[idx_2]);
            idx_2++;
        }
    };
    
    while(idx_1 < vs_1.size())
    {
    	vs_ret.push_back(vs_1[idx_1++]);
    };
    while(idx_2 < vs_2.size())
    {
    	vs_ret.push_back(vs_2[idx_2++]);
    };
    
    ofstream out;
    out.open(out_path, ios::out | ios::app);
    if(!out.is_open())
    {
        cout << "out file open failed!" << endl;
    }
    WriteFile(out, vs_ret, out_path);
};

int main()
{
	string path_1 = "./file_log1.txt";
    string path_2 = "./file_log2.txt";
    string out_path = "./file_log3.txt";
    MergeFiles(path_1, path_2, out_path);
    return 0;
};


//linux
//如果是管控log文件，先获取权限
// sudo cp ./file_log2.txt ./file_log_tmp.txt; cat ./file_log1.txt >> ./file_log_tmp.txt; sort ./file_log_tmp.txt > ./file_log3.txt; rm ./file_log_tmp.txt;
