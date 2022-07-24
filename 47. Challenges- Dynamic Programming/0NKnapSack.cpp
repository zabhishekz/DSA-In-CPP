#include<iostream>
using namespace std;

int knapsack0N(int n, int w, int *wt, int *val){
    int dp[10001] = {0};
    for(int i = 0; i <= w; i++){
        for(int j = 0; j < n; j++){
            if(wt[j] <= i){
                dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);
            }
        }
    }
    return dp[w];
}

int main(){
    int n, w;
    cin>>n>>w;
    int wt[10001];
    int val[10001];
    for(int i = 0; i < n; i++){
        cin>>wt[i];
    }
    for(int i = 0; i < n; i++){
        cin>>val[i];
    }
    cout<<knapsack0N(n, w, wt, val); 
    return 0;
}