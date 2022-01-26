#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t, arr[1000];
    cin>>t;
    while(t>0)
    {
        int n;
        cin>>n;
        for(int i = 0; i < n; i++)
        {
           cin>>arr[i];
	    }
        next_permutation(arr, arr+n);
        for(int i = 0; i < n; i++)
        {
			cout<<arr[i]<<" ";
		}
        cout<<endl;
        t--;
    }

    return 0;
}