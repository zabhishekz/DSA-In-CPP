#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *next;

    node(int d){
        data = d;
        next = NULL;
    }
};

class Queue{
    node *front = NULL;
    node *rear = NULL;
public:
    void push(int d){
        if(front == NULL and rear == NULL){ 
            rear = new node(d);
            front = rear;
        }
        else{
            rear->next = new node(d);
            rear = rear->next;
        }
        return;
    }
    void pop(){
        if(front == NULL and rear == NULL){
            return;
        }
        node * temp = front->next;
        delete front;
        front = temp;
    }
    void print(){
        node * temp = front;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.print();
    q.pop();
    q.pop();
    q.push(5);
    q.push(6);
    q.print();
    return 0;
}