#include<iostream>
using namespace std;

void merge(int a[], int s, int e){
    int mid  = (s + e)/2;
    int i = s;
    int j = mid+1;
    int k = s;

    int temp[100];

    while(i <= mid and j <= e){
        if(a[i] < a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
        }
    }
    while(i <= mid){
        temp[k++] = a[i++];
    }
    while(j <= e){
        temp[k++] = a[j++];
    }
    
    for(int i = s; i <= e; i++){
        a[i] = temp[i];
        // cout<<a[i]<<", ";
    }
    cout<<endl;
}

void mergesort(int a[], int s, int e){
    if(s >= e){
        return;
    }
    //follow 3 steps
    //1. Divide
    int mid = (s + e)/2; 

    //2. Recursively the arrays - s, mid and mid+1, e
    mergesort(a, s, mid);
    mergesort(a, mid+1, e);

    //3. merge two parts
    merge(a, s, e);
}

int main(){
    int a[100];
    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    mergesort(a, 0, n-1);
    for(int i = 0; i < n; i++){
        cout<<a[i]<<", ";
    }
    return 0;
}