//最长出现的单词
//Error
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

string mostCommonWord(string paragraph, vector<string>& banned)
{
    //去除逗号和句号
    string clean_para;
    for(auto c : paragraph)
    {
        if(('a' <= c  && c <= 'z') ||('A' <= c  && c <= 'Z') || c == ' ')
        {
            clean_para += c;
        }
    };
    //转换小写
    transform(clean_para.begin(), clean_para.end(),clean_para.begin(), ::tolower);
    //分割
    vector<string> splited_s;
    int start_idx = 0;
    int end_idx = clean_para.find_first_of(' ', start_idx);
    while(end_idx != string::npos && 0 <= end_idx && end_idx < clean_para.size())
    {
        splited_s.push_back(clean_para.substr(start_idx, end_idx - start_idx));
        start_idx = end_idx + 1;
        end_idx = clean_para.find_first_of(' ', start_idx);
    };
    auto last_idx = clean_para.find_last_of(' ');
    if(last_idx != string::npos)
    {
         splited_s.push_back(clean_para.substr(last_idx + 1, clean_para.size() - last_idx - 1));
    }
    else
    {
         splited_s.push_back(clean_para);
    }
    
    unordered_map<string, int> map;
    for(string s : banned)
    {
        map.insert({s, INT_MIN});
    };

    pair<string, int> ret{"", 0};
    for(string s: splited_s)
    {
        auto iter = map.find(s);
        if(map.find(s) != map.end())
        {
            iter->second++;
            if(iter->second > ret.second)
            {
                ret.first = s;
                ret.second = iter->second;
            }
        }
        else
        {
            map.insert({s, 1});
            if(ret.second < 1)
            {
                ret.first = s;
                ret.second = 1;
            }

        }
    };
    return ret.first;
};


int main()
{
    string paragraph = "Bob. hIt, baLl";
    vector<string> banned = {"bob", "hit"};
    mostCommonWord(paragraph, banned);
}