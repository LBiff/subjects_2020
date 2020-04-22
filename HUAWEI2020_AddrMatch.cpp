//华为2020 地址匹配
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void GetInfo(const string val, const string& s)
{
        size_t l_brack = s.find_first_of('[');
        string v_info= s.substr(0,l_brack);
        if(v_info == val)
        {
            //read[addr=0x17,mask=0xff,val=0x7]
            int first = s.find_first_of(',',0);
            int second = s.find_first_of(',',first + 1);
            string addr = s.substr(l_brack + 6,first - l_brack - 6);
            string mask = s.substr(first + 6, second - first - 6);
            string v = s.substr(second + 5, s.length() - second - 6);
            cout << addr  << " "<< mask << " "<< v << endl;
        }
};

int main()
{
    string all_s;
    getline(cin, all_s);
    int spilt = all_s.find_first_of(' ');
    string val = all_s.substr(0,spilt);
    string p = all_s.substr(spilt + 1);

    //read read[addr=0x17,mask=0xff,val=0x7],read_his[addr=0xff,mask=0xff,val=0x1],read[addr=0xf0,mask=0xff,val=0x80]
    vector<string> v;
    size_t first_pos = p.find_first_of("]",0);
    v.push_back(p.substr(0, first_pos + 1));  //[)
    int pre = first_pos;
    size_t pos =  p.find_first_of("]",pre + 1);
    while(pos != string::npos)
    {
        v.push_back(p.substr(pre+2, pos-pre -1));
        pre = pos;
        pos = p.find_first_of("]",pre + 1);
    };

    if(v.empty())
    {
        return 0 ;
    }
    for(int i =0; i< v.size() - 1; i++)
    {
        GetInfo(val, v[i]);
    };
    GetInfo(val, v.back());

    return 0;
};

