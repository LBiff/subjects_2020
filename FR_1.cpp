//帆软科技
//有序链表的快速合并

#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;


struct ListNode 
{
    pair<int,int> val;
    ListNode *next;
    ListNode(pair<int,int> x) : val(x), next(nullptr) {};
};


ListNode* MergeTwoList(ListNode* l1, ListNode* l2)
{
   ListNode* n1 = l1;

   ListNode tmp({-1,-1});
   ListNode* n1_pre = &tmp;
   n1_pre->next = n1;

   ListNode* n2 = l2;
   while(n1 && n2)
   {
       if(n1_pre->val.first == n1->val.first)
       {
           n1_pre->val.second += n1->val.second;
           n1 = n1->next;
           continue;
       };

       if(n1->val.first == n2->val.first)
       {
           n1->val.second += n2->val.second;
           n2 = n2->next;
       }
       else if(n1->val.first > n2->val.first)
       {
           auto n2_tmp = n2;
           n1_pre -> next = n2;
           n2 = n2 -> next;
           n2_tmp->next = n1;
           n1 = n2_tmp;
       }
       else if(n1->val.first < n2->val.first)
       {
           n1_pre = n1;
           n1 = n1->next;
       }
   };
   if(n2)
   {
       n1_pre->next = n2;
   }
   return l1;
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


vector<int> GetIntVByLineBySpace()
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


void PrintList(ListNode* head)
{
    if(!head)
    {
        return;
    };
    cout << head->val.first << ":" << head->val.second;
    head  = head -> next;
    while(head)
    {
        cout << " " << head->val.first << ":" << head->val.second;
        head = head -> next;
    };
}

int main()
{
    auto p = GetIntVByLineBySpace();
    int list_count = p[0];
    vector<ListNode*> vl;
    while(list_count-- > 0)
    {
       auto l = GetStrVSpiltByChar(' ');
       ListNode* head = nullptr;
       if(l.size() > 0)
       {
           size_t mh_pos = l[0].find_first_of(':');
           int k = atoi(l[0].substr(0, mh_pos).c_str());
           int v = atoi(l[0].substr(mh_pos + 1).c_str());
           head = new ListNode({k,v});
       };
       ListNode* cur = head;
       for(int i = 1; i < l.size(); i++)
       {
           size_t mh_pos = l[i].find_first_of(':');
           int k = atoi(l[i].substr(0, mh_pos).c_str());
           int v = atoi(l[i].substr(mh_pos + 1).c_str());
           ListNode* tmp = new ListNode({k,v});
           cur->next = tmp;
           cur = tmp;
       };
       if(cur)
       {
           cur -> next = nullptr;
       };
       if(head)
       {
           vl.push_back(head);
       }
    };

    ListNode* head = vl[0];
    for(int i = 1; i < vl.size(); i++)
    {
        head = MergeTwoList(head, vl[i]);
    };

    PrintList(head);
    return 0;
};

// 1:7 2:5 3:8 4:7 5:3 6:3

// 3 3 4 3
// 1:5 3:8 5:1
// 1:2 2:2 4:3 5:2
// 2:3 4:4 6:3


