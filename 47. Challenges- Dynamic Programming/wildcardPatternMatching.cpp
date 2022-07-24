#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int dp[100][100];

bool match(string str, string pattern, int i, int j){
    if(str[i] == '\0' and pattern[j] == '\0'){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(str[i] == pattern[j] or pattern[j] == '?'){
        return dp[i][j] =  match(str, pattern, i+1, j+1);
    }
    if(pattern[j] == '*'){
        if(str[i] == '\0'){
            return dp[i][j] = 0;
        }
        else{
            return dp[i][j] = max(match(str, pattern, i+1, j), match(str, pattern, i, j+1));
        }
    }
    return dp[i][j] = 0;
}

int main(){
    string str, pattern;
    getline(cin, str);
    getline(cin, pattern);
    int n = str.length();
	int m = pattern.length();
	
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++)
			dp[i][j]=-1;
    cout<<match(str, pattern, 0, 0);
    return 0;
}