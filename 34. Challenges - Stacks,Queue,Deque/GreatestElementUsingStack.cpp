#include<iostream>
#include<stack>
using namespace std;

void printnge(int *a, int n){
    stack<int> s;
    s.push(a[0]);
    for(int i = 1; i < n; i++){
        while(!s.empty() && s.top() < a[i]){
            cout<<a[i]<<" ";
            s.pop();
        }
        s.push(a[i]);
    }
    while(!s.empty()){
        cout<<-1<<" ";
        s.pop();
    }
}

int main(){
    int arr[10];
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    printnge(arr, n);
    return 0;
}