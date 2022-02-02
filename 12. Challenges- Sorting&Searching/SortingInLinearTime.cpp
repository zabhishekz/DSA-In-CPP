#include<iostream>
using namespace std;

void lineartimesort(int a[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid <= high)
    {
        if(a[mid] == 0)
        {   
            swap(a[mid], a[low]);
            low++;
            mid++;
        }
        else if(a[mid] == 1)
            mid++;
        else
        {
            swap(a[mid], a[high]);
            high--;
        }      
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
    lineartimesort(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}