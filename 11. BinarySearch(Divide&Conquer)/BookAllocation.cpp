#include<iostream>
#include<climits>
using namespace std;

bool isPossible(int arr[], int n, int m, int curr_min)
{
    int studentUsed = 1;
    int pagesReading = 0;
    for(int i = 0; i < n; i++)
    {
        if(pagesReading + arr[i] > curr_min)
        {
            studentUsed++;
            pagesReading = arr[i];
            if(studentUsed > m)
                return false;
        }
        else
        {
            pagesReading += arr[i];
        }   
    }
    return false;
}

int findpage(int arr[], int n, int m)
{
    int sum = 0;
    if(n < m)
        return -1;

    for(int i = 0; i<n; i++)
        sum +=arr[i];

    int s = arr[n-1];
    int e = sum;
    int ans = INT_MAX;

    while(s<=e)
    {
        int mid = (s+e)/2;
        if(isPossible(arr, n, m, mid))
        {
            ans = min(ans, mid);
            e = mid-1;
        }
        else
        {
            s = mid+1;
        }
    } 
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        int n, m, arr[1000];
        cin>>n>>m;
        for(int i = 0; i<n; i++)
            cin>>arr[i];
        cout<<findpage(arr, n, m)<<endl;  
        t--;
    }
    return 0;
}