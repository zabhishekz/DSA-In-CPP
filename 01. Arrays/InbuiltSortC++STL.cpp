#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, i, a[100];
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin>>a[i];
        
    sort(a, a+n);
    
    for(i = 0; i < n; i++)
        cout<<a[i]<<",";
    
    return 0;

}
