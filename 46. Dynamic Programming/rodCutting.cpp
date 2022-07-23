#include<iostream>
#include<climits>
using namespace std;

//Bottom Up DP
int max_profit_dp(int *prices, int n){
    int dp[n+1];
    dp[0] = 0;
    for(int len = 1; len <= n; len++){
        int ans = INT_MIN;
        for(int i = 1; i <= len; i++){
            ans = max(ans, prices[i-1] + dp[len-i]);
        }
        dp[len] = ans;
    }
    return dp[n];
}

//Recursive Solution
int max_profit(int prices[], int n){
    if(n <= 0){
        return 0;
    }
    int ans = INT_MIN;
    for(int len = 1; len <= n; len++){
        ans = max(ans, prices[len-1]+max_profit(prices, n-len));
    }
    return ans;
}


int main(){
    int prices[] = {3, 5, 8, 9, 10, 17, 20};
    int n = sizeof(prices)/sizeof(int);
    cout<<max_profit(prices, n)<<endl;
    cout<<max_profit_dp(prices, n)<<endl;
    return 0;
}