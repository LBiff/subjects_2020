#include <vector>
#include<iostream>
using namespace std;

int main()
{
    int test_count;
    cin >> test_count;

    while(test_count-- > 0)
    {
        int len;
        int think_count;
        cin >> len >> think_count;
        vector<int> v(len, 0);
        while(think_count-- > 0)
        {
            int start;
            int end;
            cin >> start >> end;
            for(int i = start; i <= end; i++)
            {
                if(i - 1 >= 0 && i - 1 < len)
                {
                    v[i - 1] += 1;
                }
            }
        };

        if(!v.empty())
        {
            cout << v[0];
            for(int i = 1; i < len; i++)
            {
                cout << " " << v[i];
            };
            cout << endl;
        }
    }

    return 0;
}