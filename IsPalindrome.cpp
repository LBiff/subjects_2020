//判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

bool isPalindrome(int x) 
{
    if(x < 0 || (x % 10 == 0 && x != 0)) //前缀不可能为0
    {
        return false;
    };

    //拿到其最高的标志位
    int n = 1;
    while(x / n >= 10)
    {
        n *= 10;
    };

    int r = 0;
    int l =0;
    while(x > 0)
    {
        l = x / n;
        r = x % 10;
        if(l != r)
        {
            return false;
        };
        //删除前
        x = x % n;
        //删除后
        x /= 10;
        n /= 100;
    };

    return true;
};

//判断一个单链表是否回文
//1.全部入数组判断
//双指针，快2慢1，快指针压到null,慢指针偶数压到后中，奇数压中间，从快指针后入栈，栈反序与比较
#include <stack>
using namespace std;
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool isPalindrome(ListNode* head) 
{
    if(!head || !(head->next)) //0或1个
    {
        return true;
    };
    if(!(head->next->next)) //只有两个节点
    {
        return head->val == head->next->val;
    }
    
    ListNode* low  = head -> next; //有效
    ListNode* fast = low ->next; //有效
    while(fast)
    {
        low = low->next;
        fast = fast->next ? fast->next->next : nullptr;
    };

    //奇数low压中中间节点
    //偶数个low压中中下一位置
    stack<ListNode*> s;
    while(low)
    {
        s.push(low);
        low = low->next;
    };
    ListNode* new_node = head;
    while(!s.empty())
    {
        if(new_node->val != s.top()->val)
        {
            return false;
        };
        new_node = new_node->next;
        s.pop();
    };
    return true;
}

int main()
{
    int x = 1001;
    auto ret = isPalindrome(x);
    return 0;
}
