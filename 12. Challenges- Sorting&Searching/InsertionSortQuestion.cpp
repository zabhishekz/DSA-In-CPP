#include<iostream>
using namespace std;

void insertion_sort(int a[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int j = i-1;
        int key = a[i];
        while (j >= 0 and a[j]>key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[1000000];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    insertion_sort(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}