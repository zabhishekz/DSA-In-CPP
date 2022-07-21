#include<iostream>
#include<stack>
using namespace std;
 
void generateps(int arr[],int n, int ps[]){
    stack<int> s;
    for(int i = 0; i < n; i++){
        while(!s.empty() and arr[s.top()]>=arr[i]){
            s.pop();
        }
        if(s.empty()){
            ps[i] = -1; 
        }
        else if(arr[s.top()] < arr[i]){
            ps[i] = s.top();
        }
        s.push(i);
    }
}   

void generatens(int arr[],int n,int ns[]){
    stack<int> s;
    for(int i = n-1; i >= 0; i--){
        while(!s.empty() and arr[s.top()]>=arr[i]){
            s.pop();
        }
        if(s.empty()){
            ns[i] = n; 
        }
        else if(arr[s.top()] < arr[i]){
            ns[i] = s.top();
        }
        s.push(i);
    }
}   

int main(){
    int arr[9] = {4,2,1,5,6,3,2,4,2};
    int ns[9]={0};
    int ps[9]={0};
    int n = 9;
    int ans = 0;
    generatens(arr,n,ns);
    generateps(arr,n,ps);
    for(int i = 0; i < n; i++){
        ans = max(ans,(ns[i]-ps[i]-1)*arr[i]);
    }
    cout<<ans;
    return 0;
}