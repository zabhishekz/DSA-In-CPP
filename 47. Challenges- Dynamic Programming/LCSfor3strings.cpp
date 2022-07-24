#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int lcs(string s1, string s2, string s3){
    int n1 = s1.length();
    int n2 = s2.length();
    int n3 = s3.length();
    vector<vector<vector<int>>>dp(n1+1, vector<vector<int>> (n2+1, vector<int>(n3+1, 0)));
    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){
            for(int k = 1; k <= n3; k++){
                if(s1[i-1] == s2[j-1] and s2[j-1] == s3[k-1]){
                    dp[i][j][k] = 1+dp[i-1][j-1][k-1];
                }
                else{
                    int op1 = dp[i-1][j][k];
                    int op2 = dp[i][j-1][k];
                    int op3 = dp[i][j][k-1];
                    dp[i][j][k] = max(op1, max(op2, op3));
                }
            }
        }
    }
    return dp[n1][n2][n3];
}

int main(){
    string s1, s2 ,s3;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);
    int len = lcs(s1, s2, s3);
    cout<<len;
    return 0;
}