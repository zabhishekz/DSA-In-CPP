#include<iostream>
using namespace std;
int dp[1000][1000];

int knapsack(int n, int s, int *sizes, int *values){
    if(n == 0 or s == 0){
        return 0;
    }
    if(dp[n][s] != -1){
        return dp[n][s];
    }
    int ans = 0;
    int inc = 0;
    int exc = 0;
    if(sizes[n-1] <= s){
        inc = values[n-1] + knapsack(n-1, s-sizes[n-1], sizes, values);
    }
    exc = knapsack(n-1, s, sizes, values);
    ans = max(inc, exc); 
    return dp[n][s] = ans;
}

int main(){
    int n, s;
    cin>>n>>s;
    int sizes[1005];
    int values[1005];
    for(int i = 0; i < n; i++){
        cin>>sizes[i];
    }
    for(int j = 0; j < n; j++){
        cin>>values[j];
    }
    memset(dp, -1, sizeof(dp));
    cout<<knapsack(n, s, sizes, values); 
    return 0;
}