#include<iostream>
#include<algorithm>
using namespace std;

bool myComp(string a, string b)
{
    return (a+b > b+a);
}

int main()
{  
    string s[100];
    int t, n;
    cin>>t;
    while(t > 0)
    {
        cin>>n;
        for(int i=0; i<n; i++)
        {   
            cin>>s[i];
        }

        sort(s, s+n, myComp);

        for(int i=0; i<n; i++)
        { 
            cout<<s[i];
        }
        
        cout<<endl;
        t--;
    }

    return 0;
}