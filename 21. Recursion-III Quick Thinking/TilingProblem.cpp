#include<iostream>
using namespace std;

int tiling(int n)
{
    if(n <= 3)
    {
        return 1;
    }
    return tiling(n-1) + tiling(n-4);
}

int main()
{
    int n;
    cin>>n;
    cout<<tiling(n);
    return 0;
} 