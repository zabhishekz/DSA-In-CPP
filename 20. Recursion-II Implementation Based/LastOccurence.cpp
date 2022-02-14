#include<iostream>
using namespace std;

int lastocc(int *a, int n ,int key)
{
    if(n == 0)//base case
    {
        return -1;
    }
    int i = lastocc(a+1, n-1, key);
    if(i == -1)
    {
        if(a[0] == key)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    
    return i+1;
}

int linearsearch(int *a, int n, int key)
{
    // base case
    if(n == -1)
    {
        return -1;
    }
    // recursive case
    if( a[n] == key)
    {
        return n;
    }
    return linearsearch(a, n-1, key);
}

int main()
{
    int arr[] = {1, 2, 3, 7, 4, 5, 6, 7, 8};
    int key = 7;
    int n = sizeof(arr)/sizeof(int);
    cout<<lastocc(arr, n, key)<<endl;
    cout<<linearsearch(arr, n, key);
    return 0;
}