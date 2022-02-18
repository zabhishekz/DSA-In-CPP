#include<iostream>
using namespace std;

void wavesort(int arr[], int n)
{
    for(int i = 0; i < n; i+=2)
    {
        if(i != 0 and arr[i] < arr[i-1])
        {
            swap(arr[i], arr[i-1]);
        }
        if(i != n-1 and arr[i]<arr[i+1])
        {
            swap(arr[i], arr[i+1]);
        }
    }
}

int main()
{
    int arr[] = {1, 3, 4, 2, 7, 8};
    int n = sizeof(arr)/sizeof(n);
    wavesort(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}