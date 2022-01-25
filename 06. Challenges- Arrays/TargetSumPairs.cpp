#include<iostream>
#include<algorithm>
using namespace std;

void targetsumpair(int a[], int n, int target)
{
    int i = 0;
    int j = n-1;
    while (i < j)
    {
        if(a[i]+a[j] == target)
        {
            cout<<a[i]<<" and "<<a[j]<<endl;
            i++;
            j--;
        }
        else if(a[i]+a[j] < target)
        {
            i++;
        }
        else
        {
            j--;
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
    targetsumpair(a, n, target);    
    
    return 0;
}