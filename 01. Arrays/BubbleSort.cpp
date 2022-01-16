#include<iostream>
using namespace std;

void bubble_sort(int a[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0;j < (n-i-1); j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}

int main(){
    int n, i, a[100];
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin>>a[i];
    bubble_sort(a, n);
    for(i = 0; i < n; i++)
        cout<<a[i]<<",";
    
    return 0;
}
