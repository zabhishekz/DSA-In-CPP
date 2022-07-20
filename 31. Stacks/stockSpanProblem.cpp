#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> stockSpan(vector<int> prices, int n){
    vector<int> span;
    stack<pair<int,int>> s;
    for(auto price: prices){
        int days = 1;
        while(!s.empty() and s.top().first <= price){
            days += s.top().second;
            s.pop();
        }
        s.push({price,days});
        span.push_back(days);
    }
    return span;
}

int main(){
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    int n = prices.size();
    vector<int> ans = stockSpan(prices, n );
    for(int i = 0; i < n; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}