#include<iostream>
#include<algorithm>
using namespace std;

void targetsumtriplets(int a[], int n, int target)
{
    for(int i = 0; i < n; i++)
    {   
        int l = i+1;
        int r = n-1;
        while (l < r)
        {
            if(a[i]+a[l]+a[r] == target)
            {
                cout<<a[i]<<", "<<a[l]<<" and "<<a[r]<<endl;
                l++;
                r--;
            }
            else if(a[i]+a[l]+a[r] < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    
}

int main()
{
    int a[1000];
    int n, target;
    cin>>n;
    
    for(int i = 0; i < n; i++)
    {   
        cin>>a[i];
    }
    cin>>target;
    sort(a, a+n);
    targetsumtriplets(a, n, target);    
    
    return 0;
}