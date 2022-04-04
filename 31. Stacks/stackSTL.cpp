//stack STL
#include<iostream>
#include<stack>
using namespace std;
//o(1) time for all functions
int main(){
    stack<int> s;
    for(int i = 0; i <= 5; i++){
        s.push(i);
    }
    while(!s.empty()){
        cout<<s.top()<<", ";
        s.pop();
    }
}