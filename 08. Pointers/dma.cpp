#include<iostream>
using namespace std;

int main()
{
    //Static Allocation + Deallocation
    int b[100];
    cout<<sizeof(b)<<endl; //symbol table
    //here b can't be wverwritten, part of ROM

    //Dynamic Allocation(on the fly)
    int n;
    cin>>n;
    int *a = new int[n];
    cout<<sizeof(a)<<endl;
    cout<<a<<endl; //variable a that is created inside static memory ->can be overwritten

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        cout<<a[i]<<" ";
    }

    //Free up space to avoid memory leak
    delete [] a;
    return 0;
}