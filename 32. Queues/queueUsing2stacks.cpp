#include<iostream>
#include<stack>
using namespace std;

class queue{
    stack <int> s1, s2;
public:
    void push(int x){//O(1)
        s1.push(x); 
    }
    void pop(){
        if(s1.empty()){
            return;            
        }
        while(s1.size()>1){
            int element = s1.top();
            s2.push(element);
            s1.pop();
        }
        //removes last element that we wanted to delete from stack
        s1.pop();
        //put elements back
        while(s2.size()>0){
            int element = s2.top();
            s1.push(element);
            s2.pop();
        }
    }
    int top(){
        while(s1.size()>1){
            int temp = s1.top();
            s2.push(temp);
            s1.pop();
        }
        int element = s1.top();
        while(s2.size()>0){
            int temp = s2.top();
            s1.push(temp);
            s2.pop();
        }
        return element;
    }
    int size(){
        return s1.size()+s2.size();
    }
    bool empty(){
        return size() == 0;
    }
};

int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    return 0;
}