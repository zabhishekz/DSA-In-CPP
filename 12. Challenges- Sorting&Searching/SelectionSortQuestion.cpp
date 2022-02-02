#include<iostream>
using namespace std;

void selection_sort(int a[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int min_idx = i;
        for(int j = i+1; j < n; j++)
        {
            if( a[j] < a[min_idx] )
            {
                min_idx = j;
            }
        }
        swap(a[i], a[min_idx]);
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
    selection_sort(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}