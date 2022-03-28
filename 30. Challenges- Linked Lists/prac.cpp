#include<iostream>
#include<stack>
using namespace std;

void transfer(stack<int> &s1, stack<int> &s2, int n){
    for(int i = 0; i < n; i++){
        s2.push(s1.top());
        s1.pop();
    }
}

void reverseStack(stack<int> &s1){
    stack<int> s2;
    int n = s1.size();
    for(int i = 0; i < n; i++){
        int temp = s1.top();
        s1.pop();
        transfer(s1,s2,n-i-1);
        s1.push(temp);
        transfer(s2,s1,n-i-1);
    }
}

using namespace std;
int main(){
    stack<int> s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    reverseStack(s);
    while(! s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;   
}