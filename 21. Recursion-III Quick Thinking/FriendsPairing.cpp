#include<iostream>
using namespace std;

int friends(int n)
{
    if(n == 0 or n == 1 )
    {
        return 1;
    }
    return friends(n-1) + (n-1)*friends(n-2);
}

int main()
{
    int n;
    cin>>n;
    cout<<friends(n);
    return 0;
} 