#include<iostream>
using namespace std;

int CountSetBits(int n)
{
    int ans = 0;
    while(n>0)
    {
        ans += (n&1);
        n = (n>>1); 
    }
    return ans;
}

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
    int n;
    cin>>n;
    cout<<CountSetBits(n)<<endl;
    cout<<FastCountSetBits(n)<<endl;
    cout<<__builtin_popcount(n)<<endl;
    return 0;
}