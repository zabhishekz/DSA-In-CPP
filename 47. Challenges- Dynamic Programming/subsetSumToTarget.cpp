#include<iostream>
using namespace std;

bool subsetsum(int n, int arr[], int tsum){
    if(tsum == 0){
        return true;
    }
    else if(n == 0 and tsum != 0){   
        return false;
    }
    if(arr[n-1] > tsum){
        return subsetsum(n-1, arr, tsum);
    }
    else{
        return subsetsum(n-1, arr, tsum) or subsetsum(n-1, arr, tsum-arr[n-1]);
    }
}

int main(){
    int n ,tsum;
    cin>>n>>tsum;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    if(subsetsum(n, arr, tsum)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}