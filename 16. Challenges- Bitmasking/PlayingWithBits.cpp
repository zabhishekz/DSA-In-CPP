#include<iostream>
using namespace std;

int FastCountSetBits(int n)
{
    int ans = 0;
    while(n>0)
    {
        n = n&(n-1);
        ans++; 
    }
    return ans;
}

int main()
{
    int q;
    cin>>q;
    while(q>0)
    {
        int a, b, ans = 0;
        cin>>a>>b;
        for(int i = a; i <= b; i++)
        {
            ans += FastCountSetBits(i);
        }
        cout<<ans<<endl;
        q--;
    }
    return 0;
}