#include<iostream>
using namespace std;

int main(){
    int n, a[100];
    int ms = 0;
    int cs = 0;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements:\n";
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    
    for(int i = 0; i < n; i++){
        cs = cs+a[i];
        if(cs < 0)
            cs = 0;
        ms = max(cs, ms);
    }

    cout<<"Maximum sum is "<<ms<<endl;

    return 0;
}