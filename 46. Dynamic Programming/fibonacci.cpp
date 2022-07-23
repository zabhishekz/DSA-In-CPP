#include<iostream>
using namespace std;

//Using recursion
int fib(int n){
    if(n == 0 or n == 1){
        return n;
    }
    int ans;
    ans = fib(n-1) + fib(n-2);
    return ans;
}

//top-down = recursion+memoisation
int fib_topdown(int n, int dp[]){
    if(n == 0 or n == 1){
        return n;
    }
    //look up
    if(dp[n] != 0){
        return dp[n];
    }
    int ans;
    ans = fib_topdown(n-1, dp) + fib_topdown(n-2, dp);
    return dp[n] = ans;
}

//bottom-up
int fib_bottomup(int n){
    if(n == 0 or n == 1){
        return n;
    }
    int dp[100] = {0};
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

//bottom up space optimized
int fib_bottomup_spaceopt(int n){
    if(n == 0 or n == 1){
        return n;
    }
    int a = 0;
    int b = 1;
    int c;
    for(int i = 2; i <= n; i++){
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    int n;
    cin>>n;
    cout<<fib(n)<<endl;

    int dp[100] = {0};
    dp[1] = 1;
    cout<<fib_topdown(n, dp)<<endl;

    cout<<fib_bottomup(n)<<endl;

    cout<<fib_bottomup_spaceopt(n)<<endl;
    return 0;
}