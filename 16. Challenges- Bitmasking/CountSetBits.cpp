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
    int q, n;
    cin>>q;
    while(q>0)
    {
        cin>>n;
        cout<<FastCountSetBits(n)<<endl;
        q--;
    }
    return 0;
}