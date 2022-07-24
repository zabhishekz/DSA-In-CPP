#include<iostream>
using namespace std;

int countStrings(int n)
{
    int a[n+1], b[n+1];
    a[0] = b[0] = 0;
	a[1]=b[1]=1;
    for (int i = 2; i < n; i++){
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i-1];
    }
    return a[n-1] + b[n-1];
}



long long int countNumbers(long long int n, int last_digit, long long int dp[2][101]){
    if(n == 0){
        return 1;
    }
    if(dp[last_digit][n] != -1){
        return dp[last_digit][n];
    }
    if(last_digit == 0){
        return dp[last_digit][n] = countNumbers(n-1, 0, dp) + countNumbers(n-1, 1, dp);
    }
    else{
        return dp[last_digit][n] = countNumbers(n-1, 0, dp);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        long long int dp[2][101];
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = -1;
            }
        }
        dp[0][0] = 1;
        dp[1][0] = 1;
        long long int a = countNumbers(n-1, 0, dp) + countNumbers(n-1, 1, dp); 
        cout<<a<<endl;
    }
    return 0;
}

