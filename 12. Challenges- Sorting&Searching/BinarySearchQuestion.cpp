#include<iostream>
using namespace std;

int binary_search(int a[], int n, int key)
{
    int s = 0;
    int e = n-1;
    int mid;

    while(s <= e)
    {
        mid = s+(e-s)/2; //modified approch from mid = (s+e)/2

        if(a[mid] == key)
            return mid;
        else if(a[mid] > key)
            e = mid-1;
        else
            s = mid+1;
    }
    return -1;
}

int main()
{
    int n, m, i, a[100];
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    cin>>m;
    cout<<binary_search(a, n, m);
    return 0;
}