#include<iostream>
#include<algorithm>
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
    int n, key, q, arr[100000], x[100];
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    cin>>q;
    for(int i = 0; i < q; i++)
        cin>>x[i];  

    for(int i = 0; i < q; i++)
    {
        cout<<first_occurrence(arr, n, x[i])<<" "<<last_occurrence(arr, n, x[i])<<endl;
    }

    return 0;    

}