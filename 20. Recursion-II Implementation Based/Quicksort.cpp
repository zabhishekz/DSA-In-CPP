#include<iostream>
using namespace std;

int partition(int *arr, int s, int e){
    int i = s-1;
    int j = s;
    int pivot = arr[e];
    for(; j <= e-1; j++){
        if(arr[j] <= pivot){
            i += 1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[e]);
    return i+1;
}

void quicksort(int *arr, int s, int e){
    if(s >= e){
        return;
    }
    int p = partition(arr, s, e);
    quicksort(arr, s, p-1);
    quicksort(arr, p+1, e);
}

int main(){
    int a[] = {2, 7, 8, 6, 1, 5, 4};
    int n = 7;
    quicksort(a, 0, n-1);
    for(int i = 0; i < n; i++){
        cout<<a[i]<<", ";
    }
    return 0;
}