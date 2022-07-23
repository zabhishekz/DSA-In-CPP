#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    int dp[n+1];
    //lenghts from 0-n
    do[0] = INT_MIN;
    for(int i = 0; i < n; i++){
        dp[i] = INT_MAX:
    }
    for(int i = 0; i < n; i++){
        for(int length = 0; length < n; length++){
            if(dp[length] < a[i] && a[i] < dp[length+1]){
                dp[lenght+1] = a[i];
            }
        }
    }

    int lis = 0;
    for(int = 1; i <= n; i++){
        if(dp[i] != INT_MAX){
            lis = i;
        }
    }
    cout<<lis;
    return 0;
}