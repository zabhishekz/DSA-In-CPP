#include<iostream>
using namespace std;

int main(){
    int n, arr[1000000], max;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    for(int i = 0; i < n; i++){
        max = -1;
        for(int j = i+1; j < n; j++){
            if(arr[j]>arr[i]){
                max = arr[j];
                break;
            }
        }
        if(max == -1){
            for(int j = 0; j < i; j++){
                if(arr[j]>arr[i]){
                    max = arr[j];
                    break;
                }
            }
        }
        cout<<max<<" ";
    }
    return 0;
}