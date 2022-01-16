#include<iostream>
using namespace std;

void insertion_sort(int a[], int n){
    int i, j, key;
    for(i = 1; i < n; i++){
       key = a[i];
       j = i-1;
       while(j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
       a[j+1] = key;
    }
}

int main(){
    int n, i, a[100];
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin>>a[i];
        
    insertion_sort(a, n);
    
    for(i = 0; i < n; i++)
        cout<<a[i]<<",";
    
    return 0;

}
