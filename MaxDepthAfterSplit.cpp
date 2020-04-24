//有效括号字符串的最大嵌套深度

#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution 
{
public:
    vector<int> maxDepthAfterSplit(string seq) 
    {
        vector<int> ret;
        if(seq.empty())
        {
            return ret;
        };
        //在有效的前提下进行分类检测
        stack<int> s;
        s.push(0); //第0个肯定为(
        int check_idx = 1;
        for(; check_idx < seq.size(); check_idx++)
        {
            if(seq[check_idx] == '(')
            {
                s.push(check_idx);
            }
            else //右括号
            {
                s.pop();
                if(s.empty())
                {
                    break;
                }
            }
        };

        if(check_idx != seq.size() - 1) //两边情况
        {
            for(int i = 0; i <= check_idx; i++)
            {
                ret.push_back(0);
            };
            for(int i = check_idx + 1; i < seq.size(); i++)
            {
                ret.push_back(1);
            }
        }
        else  //嵌套情况
        {
            for(int i = 0; i< seq.size(); i++)
            {
                if(seq[i] != '(')
                {
                    break;
                };
            };
        }
    }
};