#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    stack <int> s;
    int arr[12] ={4,12,5,3,1,2,5,3,1,2,4,6};
    int n = sizeof(arr)/sizeof(int);
    vector<int> v;
    v.push_back(-1);
    s.push(arr[n-1]);
    for(int i = n-2; i >= 0; i--){
        while(!s.empty() and s.top() < arr[i]){
            s.pop();
        }
        if(!s.empty() and s.top() > arr[i]){
            v.push_back(s.top());
        }
        if(s.empty()){
            v.push_back(-1);
        }
        s.push(arr[i]);
    } 
    reverse(v.begin(),v.end());
    for(auto a: v){
        cout<<a<<" ";
    }
    return 0;
}