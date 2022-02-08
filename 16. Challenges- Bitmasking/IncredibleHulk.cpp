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
    int t, n;
    cin>>t;
    while(t>0)
    {
        cin>>n;
        cout<<FastCountSetBits(n)<<endl;
        t--;
    }
    return 0;
}