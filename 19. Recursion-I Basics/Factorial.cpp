#include<iostream>
using namespace std;

int fact(int n)
{
    //Base Case
    if(n == 0)
    {
        return 1;
    }
    //Recursive Case
    return n * fact(n-1);

}

int main()
{
    int n;
    cin>>n;
    cout<<fact(n);
    return 0;
}