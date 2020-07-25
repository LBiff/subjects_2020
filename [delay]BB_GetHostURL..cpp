//字节提前批0718
//获取一个合法的URL的Host(域名或IP)部分,如果URL无效则返回Invaild

#include <string>
using namespace std;

string GetHostURL(string& url)
{
    size_t first_sign_idx = url.find_first_of("://");
    if(first_sign_idx != string::npos)
    {
        url = url.substr(first_sign_idx + 3);
    }
    else
    {
        return "Invaild";
    };

    size_t sec_sign_idx = url.find_first_of("/");
    if(sec_sign_idx != string::npos)
    {
        url = url.substr(0, sec_sign_idx);
    }
    else
    {
        return "Invaild";
    };

    return url;
};

int main()
{
    string url = "http://www.baidu.com/fsf/a.txt";
    auto ret = GetHostURL(url);
    return 0;
}