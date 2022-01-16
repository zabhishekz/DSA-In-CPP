#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a, int b){
    cout<<"comparing "<<a<<" and "<<b<<endl;
    return a>b;   //a>b for desending order, a<b for ascending order
}

int main(){
    int n, i, a[100];
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin>>a[i];
        
    sort(a, a+n, compare);
    
    for(i = 0; i < n; i++)
        cout<<a[i]<<",";
    
    return 0;

}