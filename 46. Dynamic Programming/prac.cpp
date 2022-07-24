#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s1 = "ABCD";
    string s2 = "ABEDG";
    int n1 = s1.length();
    int n2 = s2.length();
    int i,j;
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    for(i = 1; i <= n1; i++){
        for( j = 1; j <= n2; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout<<dp[n1][n2];
    return 0;
}