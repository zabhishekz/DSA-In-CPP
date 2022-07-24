#include<iostream>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int  l, r;
    l = r = 0;
    int i, j;
    int maxlensofar = 0;
    int zerocount = 0;
    while(r < n){
        if(arr[r] == 1){
            r++;
        }
        else{
            r++;
            zerocount++;
        }
        while(zerocount > k){
            if(arr[l] == 0){
                zerocount--;
                l++;
            }
            else{
                l++;
            }
        }
        if (r-l > maxlensofar){
            maxlensofar = r-l;
            i = l;
            j = r;
        }
    }
    cout<<maxlensofar;
    for(int k = i; k < r; k++){
        arr[k] = 1;
    }
    for(int i = 0; i < n; i++){
        cout<<arr[i];
    }
    return 0;
}