#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr)/sizeof(int);

    for(int i =0; i<n; i++)
        cout<<arr[i]<<" ";

    rotate(arr, arr+2, arr+n);
    cout<<endl;

    for(int i =0; i<n; i++)
        cout<<arr[i]<<" ";

    //For vectors-
    cout<<endl<<endl;
    vector <int> v = {10, 20, 30, 40, 50};

    for(int i =0; i<v.size(); i++)
        cout<<v[i]<<" ";

    rotate(v.begin(), v.begin()+2, v.end());
    cout<<endl;

    for(int i =0; i<v.size(); i++)
        cout<<v[i]<<" ";

    //Next Permutation
    cout<<endl<<endl;
    next_permutation(v.begin(), v.end());
    for(int x: v)
        cout<<x<<" ";
    return 0;    

}