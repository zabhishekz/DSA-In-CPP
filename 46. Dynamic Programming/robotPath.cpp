#include<iostream>
#include<cstring>
using namespace std;
#define MOD 1000000007
int dp[1001][1001];

int numWays(int R, int C){
    if(dp[0][0] == -1){
        return 0;
    }
    //compute number of ways for firstrow
    for(int j = 0; j < C; j++){
        if(dp[0][j] == -1){
            break;
        }
        dp[0][j] = 1;
    }
    //compute number of ways for firstCol
    for(int j = 0; j < R ; j++){
        if(dp[j][0] == -1){
            break;
        }
        dp[j][0] = 1;
    }

    //Bottom up
    for(int i = 1; i < R; i++){
        for(int j = 1; j < C; j++){
            if(dp[i][j] == -1){
                continue;
            }
            dp[i][j] = 0;
            if(dp[i][j-1] != -1){
                dp[i][j] = dp[i][j-1]%MOD;
            }
            if(dp[i-1][j] != -1){
                dp[i][j] = (dp[i][j]+ dp[i-1][j])%MOD;
            }
        }
    }
    if(dp[R-1][C-1] == -1){
        return 0;
    }
    return dp[R-1][C-1];
}

int main(){
    memset(dp,0, sizeof(dp));
    int m, n, p;
    cin>>m>>n>>p;
    for(int i = 0; i < p; i++){
        int x, y;
        cin>>x>>y;
        dp[x-1][y-1] = -1;
    }
    cout<<numWays(m, n)<<endl;
    return 0;
}