#include<iostream>
using namespace std;

int main(){
    int n, key, i, a[100];

    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin>>a[i];
    cout<<"Enter element to find: ";
    cin>>key;

    for(i = 0; i < n; i++){
        if(a[i] == key){
            cout<<key<<" found at index "<<i<<endl;
            break;
        }
    }
    if(i == n){
        cout<<key<<" is not found"<<endl;
    }

    return 0;

}
