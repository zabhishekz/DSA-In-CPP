#include<iostream>
using namespace std;

int tiling(int n, int m)
{
    if(n <= m-1)
    {
        return 1;
    }
    return tiling(n-1, m) + tiling(n-m, m);
}

int main()
{
    int t, n, m;
    cin>>t;
    while(t > 0)
    {
        cin>>n>>m;
        cout<<tiling(n, m)<<endl;
        t--;
    }
    return 0;
} 