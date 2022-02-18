#include<iostream>
using namespace std;

void dnf_sort(int a[], int n)
{
    //sort arrays of 0s, 1s, 2s
    int lo = 0;
    int mid = 0;
    int hi = n-1;
    while(mid <= hi)
    {
        if(a[mid]==0)
        {
            swap(a[mid],a[lo]);
            lo++;
            mid++;
        }
        if(a[mid]==1)
        {
            mid++;
        }
        if(a[mid]==2)
        {
            swap(a[mid],a[hi]);
            hi--;
        }
    }
    return;
}

int main()
{
    int arr[] = {2, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 2, 0};
    int n = sizeof(arr)/sizeof(n);
    dnf_sort(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}