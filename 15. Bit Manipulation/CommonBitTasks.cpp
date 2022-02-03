#include<iostream>
using namespace std;

bool isOdd(int n)
{
    return (n&1);
}

int getbit(int n, int i)
{
    int mask = (1<<i);
    int bit = (n&mask) > 0 ? 1:0;
    return bit;
}

int setbit(int n, int i)
{
    int mask = (1<<i);
    int ans = (n|mask);
    return ans;
}

int clearibit(int n, int i)
{
    int mask = ~(1<<i);
    int ans = n&mask;
    return ans;
}

int updateibit(int n, int i, int v)
{
    int mask = ~(1<<i);
    int cleardebitn = n&mask;
    int ans = cleardebitn | (v<<i);
    return ans;
}

int clearlastibits(int n ,int i)
{
    int mask = (-1<<i);
    int ans = n&mask;
    return ans;
}

int clearlastitojbits(int n, int i, int j)
{
    int ones = (~0);
    int a = ones<<(j+1);
    int b = (1<<i) - 1;
    int mask = a|b;
    int ans = n&mask;
    return ans;
}

int main()
{
    int n, i, j, v;
    cin>>n>>i>>j>>v;
    cout<<isOdd(n)<<endl;
    cout<<getbit(n, i)<<endl;
    cout<<setbit(n, i)<<endl;
    cout<<clearibit(n, i)<<endl;
    cout<<updateibit(n, i, v)<<endl;
    cout<<clearlastibits(n, i)<<endl;
    cout<<clearlastitojbits(n, i, j)<<endl;
    return 0;
}