#include<iostream>
using namespace std;

int fibonacci(int n)
{
    //Base Case
    if(n == 0 || n == 1)
    {
        return n;
    }
    //Recursive Case
    return fibonacci(n-1)+fibonacci(n-2);

}

int main()
{
    int n;
    cin>>n;
    cout<<fibonacci(n);
    return 0;
}