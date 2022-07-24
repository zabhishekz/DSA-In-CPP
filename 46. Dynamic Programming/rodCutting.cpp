#include<iostream>
#include<climits>
using namespace std;


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

//Bottom Up DP
int max_profit_dp(int *prices, int n){
    int dp[n+1];
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        int ans = INT_MIN;
        for(int j = 0; j < i; j++){
            ans = max(ans, prices[j] + dp[i-j-1]);
        }
        dp[i] = ans;
    }
    return dp[n];
}



int main(){
    int prices[] = {3, 5, 8, 9, 10, 17, 20};
    int n = sizeof(prices)/sizeof(int);
    cout<<max_profit(prices, n)<<endl;
    cout<<max_profit_dp(prices, n)<<endl;
    return 0;
}