#include<iostream>
#include<queue>
using namespace std;

class stack{
    queue <int> q1, q2;
public:
    void push(int x){
        q1.push(x); 
    }
    void pop(){
        //remove last added elemt from q1
        //move first n-1 elemenst from q1 to q2
        if(q1.empty()){
            return;            
        }
        while(q1.size()>1){
            int element = q1.front();
            q2.push(element);
            q1.pop();
        }
        //removes last element that we wanted to delete from stack
        q1.pop();

        //interchange the names of q1 and q2
        swap(q1, q2);

    }
    int top(){
        while(q1.size()>1){
            int element = q1.front();
            q2.push(element);
            q1.pop();
        }
        int element = q1.front();
        q1.pop();
        q2.push(element);
        swap(q1, q2);
        return element;
    }
    int size(){
        return q1.size()+q2.size();
    }
    bool empty(){
        return size() == 0;
    }
};

int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}