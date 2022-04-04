#include<iostream>
#include<stack>
using namespace std;

void stockSpan(int prices[], int n, int span[]){
    stack <int> s;
    s.push(0);
    span[0] = 1;
    // loop for the rest of days O(n) -> push and pop each element only once
    for(int i = 1; i <= n-1; i++){
        int currentPrice = prices[i];
        //topmost element higher tha current price
        while (!s.empty() and prices[s.top()] <= currentPrice)
        {
            s.pop();
        }
        if(!s.empty()){
            int prevHighest =  s.top();
            span[i] = i - prevHighest;
        }
        else{
            span[i] = i+1;
        }
        //push this element back into stack 
        s.push(i);
    }
}

int main(){
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices)/sizeof(int);
    int span[100000] = {0};
    stockSpan(prices, n ,span);
    for(int i = 0; i < n; i++){
        cout<<span[i]<<" ";
    }
    return 0;
}