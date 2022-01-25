#include <iostream>
using namespace std;

int main() 
{
    int a[1000], b[1000], m, n, i, j, k, min;
    int res[1001];
    cin>>m;
    for(i=0; i<m; i++)
    {
		cin>>a[i];
	}
    cin>>n;
    for(i=0; i<n; i++)
    {
		cin>>b[i];
	}
    
    i=m-1;
    j=n-1;
    int carry=0, c=0, tempSum;
    while(i>=0 && j>=0)
    {
        tempSum = a[i--] + b[j--] + carry;
        res[c++] = tempSum%10;
        carry = tempSum/10;
    }
    while(i>=0)
    {
        tempSum = a[i--] + carry;
        res[c++] = tempSum%10;
        carry = tempSum/10;
    }
    while(j>=0)
    {
        tempSum = b[j--] + carry;
        res[c++] = tempSum%10;
        carry = tempSum/10;
    }
    if(carry!=0)
    {
        res[c++] = carry;
    }
    
    for(int k = c-1; k>=0; k--)
    {
        cout<<res[k]<<", ";
    }
    cout<<"END";

	return 0; 
} 