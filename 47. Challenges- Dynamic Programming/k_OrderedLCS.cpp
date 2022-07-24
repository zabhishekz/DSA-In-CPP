#include<iostream>
#include<cstring>
#include<string>
#include<stack>
using namespace std;

int dp[2001][2001][6];
int N,M;

int LCS(long* a,long* b,int n,int m,int k){
	if(n == N || m == M){
        return 0;
    }
    if(dp[n][m][k]!=-1){
        return dp[n][m][k];
    }
    int res=0;
    if(a[n] == b[m]){
        res = 1+LCS(a,b,n+1,m+1,k);
    }
    else{
        if(k > 0){
            res = 1+LCS(a,b,n+1,m+1,k-1);
        }
        res = max(res,LCS(a,b,n,m+1,k));
        res = max(res,LCS(a,b,n+1,m,k));
    } 
    return dp[n][m][k]=res; 
}

int main(){
	int k;
    cin>>N>>M>>k;

    long a[N],b[M];
    for(int i = 0; i < N; i++){
        cin>>a[i];
    }

    for(int i = 0; i < M; i++){
        cin>>b[i];     
    }

    for(int i = 0; i <= 2000; i++){
        for(int j = 0; j <= 2000; j++){
            for(int k = 0; k <= 5; k++){
                dp[i][j][k] = -1;
            }
        }
    }
	cout<<LCS(a,b,0,0,k);

	return 0;
}