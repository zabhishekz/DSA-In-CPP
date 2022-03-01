//operator Overloading
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

void insertAtHead(node *&head, int d){
    if(head == NULL){
        head = new node(d);
        return;
    }
    node *n = new node(d);
    n->next = head;
    head = n;
}

void print(node *head){
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<endl;
}

node* take_input(){
    int d;
    cin>>d;
    node * head = NULL;
    //take input until input is -1
    while(d != -1){
        insertAtHead(head, d);
        cin>>d;
    }
    return head;
}

ostream& operator<<(ostream &os, node *head){
    print(head);
    return os;
}

int main(){
    node * head = take_input();
    node * head2 = take_input();
    //cascading of operator<<
    cout<<head<<head2;
    return 0;   
}