//Given a sorted array , find pair of elements that sum to k
#include<iostream>
using namespace std;

int main()
{
    int n, a[100];
    cout<<"Enter number of elements(sorted array): ";
    cin>>n;
    cout<<"Enter elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int i = 0;
    int j = n-1;
    int cursum = 0;
    int keysum;
    cout<<"Enter sum for which we have to find pairs: ";
    cin>>keysum;
     
    while(i < j)
    {
        cursum = a[i] + a[j];

        if(cursum > keysum)
            j--;
        else if(cursum < keysum)
            i++;
        else if(cursum == keysum)
        {
            cout<<a[i]<<" and "<<a[j]<<endl;
            i++;
            j--;
        }
    }

    return 0;
}