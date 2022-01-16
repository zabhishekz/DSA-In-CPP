#include<iostream>
using namespace std;

int binary_search(int a[], int n, int key){
    int s = 0;
    int e = n-1;
    int mid;

    while(s <= e){
        mid = s+(e-s)/2; //modified approch from mid = (s+e)/2

        if(a[mid] == key)
            return mid;
        else if(a[mid] > key)
            e = mid-1;
        else
            s = mid+1;
    }
    return -1;
}

int main(){
    int n, key, i, a[100];

    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements:\n";
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    cout<<"Enter element to find: ";
    cin>>key;

    cout<<binary_search(a, n, key);
    return 0;
}