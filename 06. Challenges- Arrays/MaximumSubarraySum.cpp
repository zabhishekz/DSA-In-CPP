#include<iostream>
using namespace std;

int main()
{
    
    int t, n, a[100];
    cin>>t;
    while(t > 0)    
    {   
        cin>>n;
        int ms = 0;
        int cs = 0;
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        for(int i = 0; i < n; i++)
        {
            cs = cs+a[i];
            if (cs < 0)
                cs = 0;
            ms = max(cs, ms);
        }
        cout<<ms<<endl;
        t--;
    }
    return 0;
}