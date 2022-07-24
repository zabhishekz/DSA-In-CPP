#include<iostream>
using namespace std;
int dp[1000][1000];

int minMoneyNeeded(int n, int tw, int *prices){
    if(n == 0 or tw == 0){
        return 0;
    }
    if(dp[n][tw] != -1){
        return dp[n][tw];
    }
    int ans = 0;
    int inc = 0;
    int exc = 0;
    if(n <= tw){
        inc = prices[n] + minMoneyNeeded(n-1, tw-(n), prices);
    }
    exc = minMoneyNeeded(n-1, tw, prices);
    ans = min(inc, exc); 
    return dp[n][tw] = ans;
}

int main(){
    int n, tw;
    cin>>n>>tw;
    int prices[1005];
    for(int i = 1; i <= n; i++){
        cin>>prices[i];
    }
    memset(dp, -1, sizeof(dp));
    cout<<minMoneyNeeded(n, tw, prices); 
    return 0;
}