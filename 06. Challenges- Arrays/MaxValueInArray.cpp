#include<iostream>
#include<climits>
using namespace std;

int maxvalueinarray(int arr[], int n)
{
    int maxval = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        maxval = max(arr[i], maxval);
    }
    return maxval;
}

int main()
{
    int n, a[1000];
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<maxvalueinarray(a, n);
    return 0;
}