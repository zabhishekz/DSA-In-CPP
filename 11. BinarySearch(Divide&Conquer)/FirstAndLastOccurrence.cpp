#include<iostream>
using namespace std;

int first_occurrence(int a[], int n, int key)
{
    int s = 0; 
    int e = n - 1;
    int ans = -1;
    while(s<=e)
    {
        int mid  = (s+e)/2;
        if(a[mid] == key)
        {
            ans = mid;
            e = mid-1;
        }
        else if(a[mid]>key)
        {
            e = mid-1;
        }
        else
        {
            s = mid +1;
        }
    }
    return ans;
}

int last_occurrence(int a[], int n, int key)
{
    int s = 0; 
    int e = n - 1;
    int ans = -1;
    while(s<=e)
    {
        int mid  = (s+e)/2;
        if(a[mid] == key)
        {
            ans = mid;
            s = mid+1;
        }
        else if(a[mid]>key)
        {
            e = mid-1;
        }
        else
        {
            s = mid +1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 4, 4, 4, 8 ,9};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    cout<<"First Occurrence of "<<key<<" is "<<first_occurrence(arr, n, key)<<endl; 
    cout<<"LAst Occurrence of "<<key<<" is "<<last_occurrence(arr, n, key);
    return 0; 
}