#include<iostream>
using namespace std;

int main(){
    int n, k, a[15];
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    cin>>k;
    for(int i = 0; i <= n-k; i++){
        int max = a[i];
        int m = i+k;
        for(int j = i; j < m; j++){ 
            if(a[j]>=max){
                max = a[j];
            }
        }
        cout<<max<<" ";
    }
    return 0;
}