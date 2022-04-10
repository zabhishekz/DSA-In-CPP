#include<iostream>
#include<stack>
using namespace std;

class queue{
    stack <int> s1, s2;
public:
    void push(int x){
        while(s1.size()>0){
            int element = s1.top();
            s2.push(element);
            s1.pop();
        }
        s1.push(x); 
        while(s2.size()>0){
            int element = s2.top();
            s1.push(element);
            s2.pop();
        }

    }
    void pop(){
        if(s1.empty()){
            return;            
        }
        s1.pop();
    }
    int top(){
        return s1.top();
    }
    int size(){
        return s1.size()+s2.size();
    }
    bool empty(){
        return size() == 0;
    }
};

int main(){
    int n;
    queue q;
    cin>>n;
    for (int i = 0; i < n; i++){
        q.push(i);
    }

    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    return 0;
}