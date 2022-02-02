#include<iostream>
using namespace std;

void bubble_sort(int a[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < (n-1-i); j++)
        {
            if( a[j] > a[j+1] )
            {
                swap(a[j], a[j+1]);
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[100];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    bubble_sort(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}