#include<iostream>
#include<algorithm>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int d){
        data = d;
        next = NULL;
    }
};
node *top = NULL;


void push(int ele){
    node * nn = new node(ele);
    if(top == NULL){
        top = nn;
        return;
    }
    nn->next = top;
    top = nn;
}

void pop(){
    if(top == NULL){
        cout<<"List Empty";
        return;
    }
    else{
        int ele = top->data;
        node*temp = top;
        top = top->next;
        delete temp;
    }
}

void peek(){
    if(top == NULL){
        cout<<"List Empty";
        return;
    }
    else{
        cout<<top->data;
    }
}

void display(){
    if(top == NULL){
        cout<<"List Empty";
        return;
    }
    else{
        node*temp = top;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
}

int main(){
    push(1);
    push(2);
    push(3);
    pop();
    display();
    return 0;
}