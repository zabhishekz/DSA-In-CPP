#include<iostream>
using namespace std;

int ladders_topdown(int n, int k, int dp[]){
    if(n == 0){
        return 1;
    }
    if(dp[n] != 0){
        return dp[n];
    }
    int ways = 0;
    for(int i = 1; i <= k; i++){
        if(n-i >= 0){
            ways += ladders_topdown(n-i, k, dp);
        }
    }
    return dp[n] = ways;
}

int ladders_bottomUp(int n, int k){
    int ways = 0;
    int dp[100] = {0};
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i] = 0;
        for(int j = 1; j <= k; j++){
            if(i-j >= 0){
                dp[i] += dp[i-j];
            }
        }
    }
    return dp[n];
}

int ladders_bottomUp_Opt(int n, int k){
    int ways = 0;
    int dp[100] = {0};
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= k; i++){
        dp[i] = 2*dp[i-1];
    }
    for(int i = k+1; i <= n; i++){
        dp[i] = 2*dp[i-1] - dp[i-k-1];
    }
    return dp[n];
}

int main(){
    int n, k, dp[100] = {0};
    cin>>n>>k;
    cout<<"Ways : "<<ladders_topdown(n, k, dp)<<endl;
    cout<<"Ways : "<<ladders_bottomUp(n, k)<<endl;
    cout<<"Ways : "<<ladders_bottomUp_Opt(n, k)<<endl;
    return 0;
}