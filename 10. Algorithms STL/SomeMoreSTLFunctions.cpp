#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr)/sizeof(int);

    for(int i = 0; i<n; i++)
        cout<<arr[i]<<" ";

    reverse(arr, arr+n);
    cout<<endl;

    for(int i =0; i<n; i++)
        cout<<arr[i]<<" ";

    return 0;    

}