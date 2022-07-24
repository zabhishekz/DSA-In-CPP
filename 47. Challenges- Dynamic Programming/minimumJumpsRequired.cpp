#include<iostream>
#include<climits>
using namespace std;

int minJumps(int i, int n, int arr[]){
    if(i >= n-1){
        return 0;
    }
    int maxj = arr[i];
    int maxidx = i+1;
    int res = INT_MAX;
    for(int j = i+1; j <= i+maxj and j < n; j++){
        int sub_res = minJumps(j, n, arr);
        if(sub_res != INT_MAX){
            res = min(res, sub_res+1);
        }
    }
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        cout<<minJumps(0, n, arr)<<endl;
    }
    return 0;
}