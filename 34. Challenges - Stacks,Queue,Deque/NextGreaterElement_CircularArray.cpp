#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    stack <int> s;
    int arr[5] ={2,10,12,1,11};
    int n = sizeof(arr)/sizeof(int);
    vector<int> v;
    s.push(arr[n-1]);
    for(int i = 2*n-2; i >= 0; i--){
        while(!s.empty() and s.top() <= arr[i%n]){
            s.pop();
        }
        if(i<n and !s.empty() and s.top() > arr[i]){
            v.push_back(s.top());
        }
        if(i<n and s.empty()){
            v.push_back(-1);
        }
        s.push(arr[i%n]);
    } 
    reverse(v.begin(),v.end());
    for(auto a: v){
        cout<<a<<" ";
    }
    return 0;
}