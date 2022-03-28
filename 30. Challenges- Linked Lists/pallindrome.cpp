#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *next;
    node *prev;

    node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }
};

void insertAtTail(node *&head, int d){
    if(head == NULL){
        head = new node(d);
        return;
    }
    node *tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = new node(d);
    tail->next->prev = tail;
    return;
}

node* take_input(int n){
    int d;
    node * head = NULL;
    while(n > 0){
        cin>>d;
        insertAtTail(head, d);
        n--;
    }
    return head;
}

bool pallindrome(node *&head){ 
    if(head == NULL){
        return true;
    }
    node *a = head;
    node *b = head;
    while(b->next != NULL){
        b = b->next;
    }
    while(a != NULL and b != NULL){
        if(a->data == b->data){
            a=a->next;
            b=b->prev;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    node * head = take_input(n);
    pallindrome(head) ? cout<<"true" : cout<<"false" ;
    return 0;   
}