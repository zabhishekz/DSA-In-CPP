#include<iostream>
using namespace std;

int BinaryStrings(int n)
{
    //Base Case
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 2;
    }
    //Recursive Case
    return BinaryStrings(n-1)+BinaryStrings(n-2);

}

int main()
{
    int n;
    cin>>n;
    cout<<BinaryStrings(n);
    return 0;
}