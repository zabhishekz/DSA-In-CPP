#include<iostream>
using namespace std;

int maxFromKadane(int a[], int n)
{
    int cs=0, maxSum=0;
    for(int i=0; i<n; i++)
    {
        cs = cs + a[i];
        if(cs < 0)
        {
            cs = 0;
        }
        maxSum = max(cs, maxSum);
    }
    return maxSum;
}

int main()
{
    int n, t, a[10000];
    cin>>t;
    while(t > 0)
    {
        cin>>n;
        for(int i=0; i<n; i++)
        	cin>>a[i];

        int CumSum = 0;
        int candidate1 = maxFromKadane(a, n);
        // cout<<"candidate1 - "<<candidate1<<endl;
        for(int i=0; i<n; i++)
        {
            CumSum = CumSum+a[i];
            a[i] = (-1)*a[i];
        }
        // cout<<"CumSum - "<<CumSum<<endl;
        int invertedMax = maxFromKadane(a, n);
        // cout<<"invertedMax - "<<invertedMax<<endl;
        int candidate2 = invertedMax + CumSum;
        // cout<<"candidate2 - "<<candidate2<<endl;
        int ans = max(candidate1, candidate2);
        cout<<ans<<endl;
        t--;
	}

	return 0;
}